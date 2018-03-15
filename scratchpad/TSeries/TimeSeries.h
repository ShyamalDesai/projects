/*
 * TimeSeries.h
 *
 *  Created on: Jun 20, 2017
 *      Author: mluk
 */

#ifndef CHALLENGE_TIMESERIES_H_
#define CHALLENGE_TIMESERIES_H_

#include <vector>
#include <stdexcept>

template <typename T>
class TimeSeries
{

public:
    std::vector<uint64_t> timeUsSinceMid;
    std::vector<T> values;

    void addValue(uint64_t time, T value)
    {
        timeUsSinceMid.push_back(time);
        values.push_back(value);
    }
    int size() const
    {
        return values.size();
    }


    int calculateIndex (const int left, const int right, uint64_t startTime) const
     {
        //implement a  binary search for the lookup
        if (left == right)
            return left;

        int mid = left + (right-left)/2;

        if (startTime == timeUsSinceMid[mid])
            return mid;
        else if (startTime > timeUsSinceMid[mid])
            return calculateIndex(left, mid, startTime);
        else
            return calculateIndex(mid+1, right, startTime);

     }

    /**
     * samples this timeSeries based on 2 parameters, a sampling frequency, and a startTime
     * startTime is optional. If it is not provided, then it'd start at the first element of this time series.
     *
     * if startTime is set before this timeSeries starts, it would fast forward until the first valid startTime.
     * e.g.  if timeSeries starts 9:00:01, and you sample at 30 seconds, with startTime at 9:00:00, then you'd
     *         fast forward to first valid startTime, or 9:00:30.
     * A particular sample would be the time of this sample, plus the value at or before that time.
     *
     * e.g. say your original time series is
     *
09:00:00 0
09:01:00 1
09:02:00 2
09:03:00 3
09:04:00 4
09:05:00 5
09:06:00 6
09:07:00 7
09:08:00 8
09:09:00 9

if you were to sample it at 30 second interval, the output would be
09:00:00 0
09:00:30 0
09:01:00 1
09:01:30 1
09:02:00 2
09:02:30 2
09:03:00 3
09:03:30 3
09:04:00 4
09:04:30 4
09:05:00 5
09:05:30 5
09:06:00 6
09:06:30 6
09:07:00 7
09:07:30 7
09:08:00 8
09:08:30 8
09:09:00 9




     *
     *
     * @param sampleFreq
     * @param startTime
     * @return
     */
    TimeSeries<T> * sample(uint64_t sampleFreq, uint64_t startTime = 0)
    {


        //validate input values
//---------------------------------------------------------
        if (timeUsSinceMid.empty())
        {
            return nullptr;
        }
        if (timeUsSinceMid.size() != values.size() )
        {
            throw std::logic_error(" Unable to relate number of samples with correct values ");
        }

//---------------------------------------------------------
        int index = 0;//start from the beginning whenever the starttime is zero or less than the first value

        if (startTime >  timeUsSinceMid[0]) {
            index = calculateIndex (0, timeUsSinceMid.size(), startTime);
        }
        //once index is set; now is the time to iterate over the values in the given frequency
        TimeSeries<T> *pResult = new TimeSeries <T> ();
        pResult->addValue(timeUsSinceMid[index], values[index]);
        int i = index;
        int j = index + 1;
        double refTime = timeUsSinceMid[index] + sampleFreq;

        while (i < timeUsSinceMid.size() && j < timeUsSinceMid.size() )
        {

                if (timeUsSinceMid[j]  < refTime)
                {
                    j++;

                }

                if (timeUsSinceMid[j]  == refTime)
                {
                    pResult->addValue(timeUsSinceMid[j], values[j]);
                    refTime += sampleFreq;
                    i = j;
                    j + i+1;
                    continue;

                }
                while (timeUsSinceMid[j] > refTime)
                {
                    pResult->addValue(timeUsSinceMid[i], values[i]);
                    refTime += sampleFreq;
                    std::cout << "ref time " << refTime << std::endl;
                    //++j;

                }
                pResult->addValue(timeUsSinceMid[j], values[j]);
                i = j++;


         }

            /*for (j = i+1; j < timeUsSinceMid.size(); j++)
            {
                if (timeUsSinceMid[j] - timeUsSinceMid[i]  == sampleFreq)
                {
                    if (j != index)
                    {
                        pResult->addValue(timeUsSinceMid[j], values[j]);
                        i = j;
                    }
                }
                else if (timeUsSinceMid[j] - timeUsSinceMid[i] > sampleFreq)
                {
                    //append to output time series list
                    if (j-1 != index)
                    {
                        pResult->addValue(timeUsSinceMid[j-1], values[j-1]);
                        i = j-1;
                    }
                }
            }*/



        return pResult;
    }
};


template <typename T>
inline std::ostream& operator<<( std::ostream& out, const TimeSeries <T>& o  )
{
    // feel free to implement this to help your debugging
    out << "Begin printing series ----------------" << std::endl;
    for (int i = 0; i < o.size(); i++)
    {
        out << o.timeUsSinceMid[i] << "\t" << o.values[i] << std::endl;
    }
    out << "End printing series---------------- " << std::endl << std::endl;
    return out;
}

#endif

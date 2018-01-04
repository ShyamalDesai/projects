#pragma once
#include <vector>
#include <functional>
#include <iterator>
#include <algorithm>
namespace hartree
{
	class Util
	{
	public:

		enum RET { SUCCESS=0, INVALID_PARAMS};
		//unary predicate for detecting ascending val
		template <class TYPE>
		struct asc : public std::unary_function<TYPE,bool>
		{
			asc (const int val) : _prev (val) {}
			void reset  (const int val)
			{
				_prev = val;
			}

			bool operator () (const TYPE val) {
				bool bRet  = false;
				if ( _prev + 1 == val )
					bRet = true;
				_prev = val;
				return bRet;
			}
		private:
			TYPE _prev;
		};


		//unary predicate for detecting ascending val:
		template <class TYPE>
		struct dsc : public std::unary_function<TYPE,bool>
		{

			dsc (const int val) : _prev (val) {}

			void reset  (const int val)
			{
				_prev = val;
			}

			bool operator () (const TYPE val) {
				bool bRet  = false;
				if ( _prev - 1 == val )
					bRet = true;
				_prev = val;
				return bRet;
			}
		private:
			TYPE _prev;
		};

		//O(n) = n

        //this function can be parameterized for all sequential containers.

		template <typename FUNC>
		RET findSubsequence (std::vector <int>& inp,
							std::vector <int>::iterator& subSeqStart,
							int& subsequenceSize)
		{
			//i/p validation
			if (inp.empty())
				return INVALID_PARAMS;

//initialize the output params
			subSeqStart = inp.begin();
			subsequenceSize = 1;

			if (inp.size () > 1)
			{
//if the input size is 1, then we already have initialized the out params correctly

				std::vector <int> :: iterator inpItr = inp.begin();
				std::vector <int> :: iterator inpEnd = inp.end() ;
				FUNC func (*inpItr);
				inpItr++;
//initialize the functor with the first value in the array and start tracking with the 2nd value

				std::vector <int>::iterator seqStart = inp.begin();
				int seqSize = 1;

				while (inpItr != inpEnd)
				{
					if (func(*inpItr)) //if the predicate is satisfied, then increment the size of the subsequence
					{
						++seqSize ;

					}
					else
					{
					//the predicate fails. so time to note the sequence size generated. if the sequence size is max encountered so far, then update the out params
						if (seqSize > subsequenceSize)
						{
							subsequenceSize = seqSize;
							subSeqStart = seqStart;
						}
						//intialize the tracking pointer with the current position and make the sequence size 1
						seqStart  = inpItr;
						seqSize = 1;
					}
					++inpItr;
				}
				//this takes care of sub sequence that ends in the last char (that kind of subsequence would not execute the else part above)
				//found the noted issue with the unit tests
				if (seqSize > subsequenceSize)
				{
					subsequenceSize = seqSize ;
					subSeqStart = seqStart;
				}
			}


			//avoid a copy by returning an iterator pointing to the beginning of the subsequence and the size of the subsequence
			//shown here as this is the 2nd iteration

			/*std::vector <int> :: const_iterator maxSeqEnd = maxSeqStart;
			std::advance(maxSeqEnd, maxSeqSize);
			std::copy (maxSeqStart, maxSeqEnd, std::back_inserter (subSequence));*/
			return SUCCESS;
		}
	};
}


// detectBreach.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <deque>

template <typename T>
struct CMovingWindow
{
	CMovingWindow(int windowSize/*, int maxSampleCount*/) //windowSize is the time window in which we keep a count of values
		: _windowSize(windowSize)
		//, _maxSampleCount
	{
	}
	//always maintain a window of the time we are monitoring
	int sample(const T& value)
	{
		if (!_values.empty())
		{
			T diff = value - _values.front();
			while (diff > _windowSize)
			{
				_values.pop_front();
				if (_values.empty())
					break;
				diff = value - _values.front();
			}
		}
		_values.push_back(value);
		return _values.size();
	}


private:
	std::deque<T> _values;
	const int _windowSize; //does not make sense to change windowSize for this class
	//const int _maxSampleCount;
	
};
using namespace std;
void printUsage()
{
	cout << "exercise1 <input-file>" << endl;
}
int main(int argc, char** argv)
{
	int T(0), N(0), inputLines(0);
	if (argc != 2)
	{
		printUsage();
		return 0;
	}
	ifstream inFile(argv[1]);
	if (!inFile)
	{
		cout << "Unable to open: " << argv[1] << endl;
		return 1;
	}
	inFile >> T >> N >> inputLines;
	cout << "T: " << T;
	cout << " N: " << N << endl;
	//convert T ms in micros
	CMovingWindow<uint64_t> movingWindow (T*1000);
	for (int i = 0; i < inputLines; ++i)
	{
		uint64_t ts(0);
		inFile >> ts;
		bool breach(false);
		/* Your code here */
		int count = movingWindow.sample(ts);
		if (count > N)
			breach = true;
		cout << ts << endl;
		if (breach)
			cout << "Breach at timestamp: " << ts << endl;
	}
	return 0;
}

#include "stdafx.h"
#include "Duration.h"
#include "BaseUtil\Win32ErrorHelper.h"

namespace Util
{
	namespace Photosophus
	{

		Duration::Duration(TIMERESOLUTION res)
		{
			LARGE_INTEGER li;
			if (!::QueryPerformanceFrequency(&li))
			{
				throw std::runtime_error("Cannot query performance frequency " + Win32ErrorHelper::GetErrorDescription(::GetLastError()));
			}
			int divisor = 1;
			switch (res)
			{
			case TIMERESOLUTION::MILLISECONDS:
				divisor = 1000;
				break;
			case TIMERESOLUTION::MICROSECONDS:
				divisor = 1000000;
				break;
			case TIMERESOLUTION::NANOSECONDS:
				divisor = 1000000000;
				break;
			case TIMERESOLUTION::SECONDS:
			default:
				break;
			}
			_pcFrequency = double(li.QuadPart)/divisor;
		}


		Duration::~Duration()
		{
		}


		void 
		Duration::startTimer()
		{
			LARGE_INTEGER li;
			_startTimestamp = ::QueryPerformanceCounter(&li);
			_startTimestamp = li.QuadPart;
		}

		uint64_t 
		Duration::stopTimer()
		{
			LARGE_INTEGER li;
			::QueryPerformanceCounter(&li);
			return (uint64_t) (double(li.QuadPart - _startTimestamp) / _pcFrequency);

		}
	}
}
#pragma once
#include "Win32ErrorHelper.h"
#include <iostream>
namespace Util
{
	namespace Photosophus
	{
		template <typename T>
		class DurationGuard
		{
		public:
			static const char *RESDESC[] = { "Seconds, Milliseconds, Microseconds, NanoSeconds" };
			DurationGuard(TIMERESOLUTION tres, const std::string& source) 
				: _duration(tres)
				, _source (source)
				, _tres (tres)
			{
				_duration.startTimer();
			}
			~DurationGuard()
			{
				uint64_t elapsedTime  = _duration.stopTimer();
				std::cout << "Time taken for " << _source.c_str() << " is " << elapsedTime << RESDESC[_tres] << std::endl;
			}
		private:

			T	_duration;
			std::string _source;
			TIMERESOLUTION _tres;
		};
	}
}


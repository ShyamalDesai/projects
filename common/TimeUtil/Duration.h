#pragma once

namespace Util
{
	namespace Photosophus
	{
		enum class TIMERESOLUTION { SECONDS = 0, MILLISECONDS, MICROSECONDS, NANOSECONDS };

		class Duration
		{
		public:
			Duration(TIMERESOLUTION res = TIMERESOLUTION::SECONDS);
			~Duration();
			void startTimer();
			uint64_t stopTimer();
		private:
			double _pcFrequency;
			uint64_t _startTimestamp;
		};
	}
}


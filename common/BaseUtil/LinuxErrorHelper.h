#pragma once
#include <string>

namespace Util
{
	namespace Photosophus
	{
		class LinuxErrorHelper
		{
			public:
			static std::string GetErrorDescription(const int hr, const char *src = nullptr);
			static void Terminate (const bool useExit3);

		};
	}
}

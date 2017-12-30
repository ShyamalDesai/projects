#pragma once
namespace Util
{
	namespace Photosophus
	{
		class Win32ErrorHelper
		{
		public:
			static std::string GetErrorDescription(const int hr, const char *src = nullptr);

		};
	}
}


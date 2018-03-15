#ifndef ERRORHANDLER_H_INCLUDED
#define ERRORHANDLER_H_INCLUDED
#ifdef linux
	#include "LinuxErrorHelper.h"
#endif

#ifdef _WIN32
	#include "Win32ErrorHelper.h"
#endif

namespace Util
{
	namespace Photosophus
	{
		template <typename ERRORHANDLERIMPL>
		class ErrorHelper : public ERRORHANDLERIMPL
		{
			static std::string GetErrorDescription(const int hr, const char *src = nullptr)
			{	
				return ERRORHANDLERIMPL::GetErrorDescription (hr, src);
			}
			static void Terminate (const bool useExit3)
			{
				ERRORHANDLERIMPL::Terminate (useExit3);
			}	
		};

#ifdef linux
		typedef ErrorHelper<LinuxErrorHelper> PSErrorHelper;
#endif

#ifdef _WIN32
		typedef ErrorHelper <Win32ErrorHelper> PSErrorHelper;
#endif		
	}//Photosophus
}
#endif

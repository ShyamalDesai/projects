#include "stdafx.h"
#include "Win32ErrorHelper.h"
#include <tchar.h>

namespace Util
{
	namespace Photosophus
	{
		
		std::string 
		Win32ErrorHelper::GetErrorDescription(const int errorCode, const char *src )
		{
			LPTSTR lpszErrorText;
			FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
				src,
				errorCode,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				(LPTSTR)&lpszErrorText,
				0,
				NULL);

				if (lpszErrorText != NULL)
				{
					std::string ret ((const char *) lpszErrorText);
					LocalFree(lpszErrorText);
					lpszErrorText = NULL;
					return ret;
				}
				else
					return (const char *)_T("");
		}
	}
}
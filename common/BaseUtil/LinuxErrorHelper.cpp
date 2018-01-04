#include "LinuxErrorHelper.h"
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "ename.c.inc"

namespace Util
{
	namespace Photosophus
	{
		//This is an expensive call as there is a std::String (heap allocation) and string manipulation
		//also makes a system call for strerror
		//Should be used in case of a system error
		std::string
		LinuxErrorHelper::GetErrorDescription(const int errorCode, const char *src )
		{
			#define  BUF_SIZE 500
			char buf[BUF_SIZE], errText[BUF_SIZE];

			snprintf(errText, BUF_SIZE, " [%s:%s] ", (errorCode > 0 && errorCode < MAX_ENAME)? ename[errorCode] : "?Unknown?", strerror (errorCode));

			std::string retStr ("Error:");
			if (src)
				retStr += src;
			retStr += ", Desc: ";
			retStr += errText;
			return retStr;
		}

		void
		LinuxErrorHelper::Terminate (const bool useExit3)
		{
			char *s;
			/*
			 * Dump core if EF_DUMPCORE env is defined and is a nonempty string;
			 * otherwise call exit (3) or _exit (2), depending on the value of 'useExit3'. 
			 */

			s = getenv ("EF_DUMPCORE");

			if (s != NULL && *s != '\0')
				abort();
			else if (useExit3)
				exit (EXIT_FAILURE);
			else
				_exit (EXIT_FAILURE);
		}

	}
}

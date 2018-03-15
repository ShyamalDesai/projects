#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
class Util
{
public:
	static 
	bool 
	strtod(const std::string& str, 
			double& value)
	{
		bool bRet(true);

		if (!str.empty())
		{
			try
			{
				value = std::stod(str);
			}
			catch (const std::invalid_argument& excpt)
			{
				std::cout << " Invalid field value: Failed to convert " << str.c_str() << " to double: " << excpt.what() << std::endl;
				bRet = false;
			}
			catch (const std::out_of_range& excpt)
			{
				std::cout << " Out of range: field value: Failed to convert " << str.c_str() << " to double: " << excpt.what() << std::endl;
				bRet = false;
			}
			catch (...)
			{
				std::cout << " Unknown error: field value: Failed to convert " << str.c_str() << " to double. " << std::endl;
				bRet = false;
			}
		}
		else
			std::cout << " Empty field value: Failed to convert " << std::endl;
		return bRet;
	}


	static 
	std::vector <std::string> 
	split(char *str, 
		const char *delimiters)
	{
		std::vector <std::string> ret;
		if (strlen(str))
		{
			//char *next_token1 = NULL;
			//char *pcs = ::strtok(str, delimiters, &next_token1);
			char *pcs = ::strtok(str, delimiters);
			while (pcs)
			{
				std::string final(pcs);//costly alloc on the heap but it is ok at startup
				final.erase(std::remove_if(final.begin(), final.end(), isspace), final.end()); //remove spaces to be more tolerant in parsing
				ret.push_back(final);
				pcs = ::strtok(NULL, delimiters);
				//pcs = ::strtok(NULL, delimiters, &next_token1);
			}
		}
		return ret;
	}
};


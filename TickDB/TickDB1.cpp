// TickDB.cpp : Defines the entry point for the console application
#include <iostream>
#include <fstream>
#include "CTickRepository.h"
void printUsage()
{
	std::cout << "TickDB <input-file> -Oprint/-Oproduct" << std::endl;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printUsage();
		return 0;
	}
	bool bPrintOptimize = false;
	bool bProductOptimize = false;

	if (argc > 2)
	{
		//read the optimization value
		if (_stricmp(argv[2], "-Oprint") == 0)
		{
			bPrintOptimize = true;
		}
		else if (_stricmp(argv[2], "-Oproduct") == 0)
		{
			bProductOptimize = true;
		}
	}

	char c = '\0';
	std::cout << "Enter P for print command, S for Sum of Products and Q for quit " << std::endl;
	std::cin >> c;
	CTickRepository tickRepo(argv[1], bPrintOptimize, bProductOptimize);
	std::string symbol;
	uint64_t start(0);
	uint64_t end(0);
	std::string field1;
	std::string field2;

	while (c != 'Q' && c != 'q')
	{
		
		if (c == 'P' || c=='p')
		{
			std::cout << "Enter Symbol starttime endtime separated by space" << std::endl;
			std::cin >> symbol >> start >> end;
			tickRepo.print(symbol, start, end);
		}
		else if (c == 'S' || c == 's')
		{
			std::cout << "Product: Enter Symbol starttime endtime field1 field2 separated by space" << std::endl;
			std::cin >> symbol >> start >> end >> field1 >> field2;
			tickRepo.product(symbol, start, end, field1, field2);
		}

		std::cout << "Enter P for print command, S for Sum of Products and Q for quit " << std::endl;
		std::cin >> c;
	}

	return 0;
}


#pragma once
#include <iostream>
#include <vector>
#define PHONE_NUMBER_SIZE 7

namespace Algos
{
	void
	print(const std::vector<int>& base)
	{
        	//++countofnos;
        	for (int i = 0; i < PHONE_NUMBER_SIZE; ++i)
                	std::cout << base[i];

        	std::cout << std::endl;
	}


	//static algo definitions
	//the first is the number generator algorithm that uses a supplied object to generate new moves
	//It also receives the depth of numbers to be generated as argument
	//since this algo has state, it be better implemented using a functor
	template <typename GENERATOR>
	struct PhoneNumberGeneratorAlgo
	{
		PhoneNumberGeneratorAlgo(const int size, const int maxMoveCount=3) 
		: _size (size)
		, _maxMoveCount (maxMoveCount)
		{}

		bool
		operator() (const GENERATOR& gen,
						std::vector <int>& base,
						int lastDigit,
						int count)
		{
			bool bRet(true);

			//terminating condition
			if (count == _size)
			{
				//print all the numbers in the vector
				print(base);
				return false;
			}

			//all the possible next moves from this location (lastdigit)
			const std::vector <int>& moves = gen.getMovesFromPosition(lastDigit);

			//movecount is the max possible moves from a given location (number) for that GENERATOR object
			//since the GENERATOR object statically defines all the moves from each location, it is expected to have -1 for undefined moves

			for (int movecount = 0; movecount < _maxMoveCount; ++movecount)
			{
				if (moves[movecount] != -1)
				{
					base[count] = moves[movecount];
					this->operator() (gen, base, moves[movecount], count + 1);
				}
			}
			return bRet;
		}
	private:
		int _size;
		int _maxMoveCount;
	};

}


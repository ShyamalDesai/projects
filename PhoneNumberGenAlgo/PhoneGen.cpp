#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <string>
#include <thread>
#include <algorithm>
#include <functional>
#include "KnightMoveGenerator.h"
#include "PhoneNumberGenerator.h"
#include "Algos.h"
#include <future>
/************************************************

2. Phone number generation Write a C++ program that generates, and prints out, all valid phone numbers subject to the following constraints:
a. They consist of a sequence of digits generated by following the moves of a given chess piece on the following telephone keypad, starting from any position:
1   2   3
4   5   6
7   8   9
*   0   #

b. They are of length 7, and cannot begin with a 0 or a 1. In addition, they can contain only digits, so * and # should not be included. keypad, starting from any position:

c. The program should be written in a generic object-oriented manner, so that it works with any chess piece, but for the purposes  of this  specific  test you only need to implement support for the knight,  which has the following valid  move pattern, upon starting at the center dot:

On the telephone keypad, for example, a knight starting on number 8 could move to 1 or 3. From 1, it could move to 6 or 8, etc.
*************************************************/

///the first strategy that comes to mind is creating a chess piece object e.g. knight
/// the knight will store all moves from each number that is possible, statically
/// so the problem translates to traversing the static tree generated (recursively). the algo will enumerate all possible moves (max 3) for a knight from the current location
///it recursively calls the 1st move, which recurses till 7 digits are generated. Once it returns, the 2nd move is enumerated. since it is recursive, all possible moves can be enumerated.
///also using the principles of dynamic programming: each recursive stage builds on the previous one
///There is an opportunity for parallelism in this algorithm as the numbers to be generated from starting digits can be treated as not interfering with each other.

//the implementation uses an algorithm (Algos.h), templatized on the type of "next move generator" (e.g. knight). 
//Each next move generator defines the possible moves from each location and exposes a function to return the possible moves from a given location


int phoneNumber[PHONE_NUMBER_SIZE];
/*static int countofnos = 0;

void 
print(const std::vector<int>& base)
{
	++countofnos;
	for (int i = 0; i < PHONE_NUMBER_SIZE; ++i)
		std::cout << base[i];

	std::cout << std::endl;
}*/



int main()
{
	//Phone Number generator can be templatized on the knight/bishop/etc... move generator
	PhoneNumberGenerator<KnightMoveGenerator> knightMoveGenerator;

	//the algo works by enumerating all possible values from the given location recursively
	//it backs up by 1 at a time to traverse all possible locations
	Algos::PhoneNumberGeneratorAlgo <PhoneNumberGenerator<KnightMoveGenerator> > algo((PHONE_NUMBER_SIZE));

	std::vector<int> base(PHONE_NUMBER_SIZE, 0);
	for (int i = 2; i < 10; ++i)
	{
		base[0] = i;
		algo(knightMoveGenerator, base, i, 1);
		printf("\n");
	}


//-------------------------------------------------
//algo called in async mode parallel
////------------------------------------------------

/*std::map <int, std::vector<int> > bases;

	std::vector <std::future<bool> > results(8);
	for (int i = 2; i < 10; ++i)
	{
		std::vector <int>& base = bases[i-2];
		base.resize (PHONE_NUMBER_SIZE);
		base[0] = i;
		results[i-2] = std::async (algo,
                      std::ref (knightMoveGenerator),
                      std::ref(base),
                      i,
                      1);
		
	}
	for (int i = 0; i < 8; ++i)
	{
		results[i].get();
	}*/
	return 0;
}


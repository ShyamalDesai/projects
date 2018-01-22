// findSubSequence.cpp : Defines the entry point for the console application.
//
/**************************************************************

1. Write a C++ program that would find and print the first longest ascending or descending contiguous subsequence for a vector of integers. For example, given a vector with

4, 2, 1, 2, 3, 4, 3, 5, 1, 2, 4, 6, 5

The program would find the underlined subsequence and print it.

implied requirements:

---If there are 2 subsequences of the same size, then the first one should be selected
---ascending or descending (OR)

****************************************************************/

/**************Notes**************/
/*
Though the test cases for only ASCENDING is provided, the descending case functor is included.
The only change is to provide a different template argument to the  findSubSequence method.
e.g. util.findSubsequence<Util::asc<int> >
util.findSubsequence<Util::dsc<int> >

*/



#include "TestSubSequence.h"
#include <iostream>

void Test_Subsequence_All ()
{
	if (!hartree_test::TestSubSequence::TestNormalCaseAsc())
		std::cout << std::endl << "Failure:: Normal case in extracting ascending sub sequence failed " << std::endl;
	else
		std::cout << std::endl << "Success:: Normal case in extracting ascending sub sequence succeeded" << std::endl;


	if (!hartree_test::TestSubSequence::TestCaseWithFullInputAsSubsequenceAsc())
		std::cout << std::endl << "Failure:: case in extracting full input as ascending sub sequence failed " << std::endl;
	else
		std::cout << std::endl << "Success:: Normal case in extracting full input as sub sequence succeeded" << std::endl;

	if (!hartree_test::TestSubSequence::TestCaseWith1ElementAsc())
		std::cout << std::endl << "Failure::case in only 1 element in input failed" << std::endl;
	else
		std::cout << std::endl << "Success: case in only 1 element in input succeeded" << std::endl;


	if (!hartree_test::TestSubSequence::TestEmptyCaseAsc())
		std::cout << std::endl << "Failure:: test case with  empty input failed " << std::endl;
	else
		std::cout << std::endl << "Success: test case with  empty input succeeded" << std::endl;


	if (!hartree_test::TestSubSequence::TestMaxSubsequenceOf1())
		std::cout << std::endl << "Failure:: Input with a subsequence on only 1 number failed" << std::endl;
	else
		std::cout << std::endl << "Success:: Input with a subsequence on only 1 number succeeded" << std::endl;

    if (!hartree_test::TestSubSequence::SelectFirstOf2EqualSubsequence())
		std::cout << std::endl << "Failure:: Input with 2 subsequences of equal length failed" << std::endl;
	else
		std::cout << std::endl << "Success:: Input with 2 subsequences of equal length succeeded" << std::endl;
}


int main(int argc, char* argv[])
{
	Test_Subsequence_All ();
}


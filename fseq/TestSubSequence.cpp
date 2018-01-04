
#include "TestSubSequence.h"
#include "Util.h"
#include <vector>
#include <iostream>
using namespace hartree;
namespace hartree_test
{
	TestSubSequence::TestSubSequence(void)
	{
	}


	TestSubSequence::~TestSubSequence(void)
	{
	}


	void printResult (std::vector <int>& inp, std::vector <int>::iterator startOfSubSequence, int subSequenceSize)
	{
		std::cout << "\nMax subsequence in " << std::endl;
		std::copy (inp.begin(), inp.end(), std::ostream_iterator<int> (std::cout, ", "));
		std::cout << "\nis  " << std::endl;
		std::vector <int> ::iterator itrend = startOfSubSequence;
		std::advance (itrend, subSequenceSize);
		std::copy (startOfSubSequence, itrend, std::ostream_iterator<int> (std::cout, ", "));
	}

	bool
	TestSubSequence::TestNormalCaseAsc()
	{
		bool bRet (false);
		std::vector<int> inp;
		inp.push_back (4);
		inp.push_back (2);
		inp.push_back (1);
		inp.push_back (2);
		inp.push_back (3);
		inp.push_back (4);
		inp.push_back (3);
		inp.push_back (5);
		inp.push_back (1);
		inp.push_back (2);
		inp.push_back (4);
		inp.push_back (6);
		inp.push_back (5);

		std::vector <int> expectedResult ;
		expectedResult.push_back(1);
		expectedResult.push_back(2);
		expectedResult.push_back(3);
		expectedResult.push_back(4);

		std::vector <int> op;
		Util util;
		std::vector <int>::iterator startOfSubSequence = inp.begin();
		int subSequenceSize = 0;
		Util::RET ret = util.findSubsequence<Util::asc<int> > (inp, startOfSubSequence, subSequenceSize);
		if (ret == Util::SUCCESS)
		{

			printResult(inp, startOfSubSequence, subSequenceSize);
			std::vector <int> ::iterator itrend = startOfSubSequence;
			if (std::equal(startOfSubSequence, itrend, expectedResult.begin()))
				bRet = true;
		}

		return bRet;
	}

	bool
	TestSubSequence::TestEmptyCaseAsc()
	{
		bool bRet (false);

		std::vector<int> inp;
		std::vector <int>::iterator startOfSubSequence = inp.begin();
		int subSequenceSize = 0;
		Util util;

		Util::RET ret = util.findSubsequence<Util::asc<int> > (inp, startOfSubSequence, subSequenceSize);
		if (ret == Util::INVALID_PARAMS)
			bRet = true;
		return bRet;
	}

	bool
	TestSubSequence::TestCaseWith1ElementAsc()
	{
		bool bRet (false);
		std::vector<int> inp;
		std::vector <int>::iterator startOfSubSequence = inp.begin();
		int subSequenceSize = 0;
		Util util;
		inp.push_back (4);
		Util::RET ret = util.findSubsequence<Util::asc<int> > (inp, startOfSubSequence, subSequenceSize);
		if (ret == Util::SUCCESS)
		{
			if (subSequenceSize == 1 && startOfSubSequence == inp.begin())
			bRet = true;
		}


		return bRet;
	}

	bool
	TestSubSequence::TestCaseWithFullInputAsSubsequenceAsc()
	{
		bool bRet (false);
		std::vector<int> inp;
		inp.push_back (-1);
		inp.push_back (0);
		inp.push_back (1);
		inp.push_back (2);
		inp.push_back (3);
		inp.push_back (4);
		inp.push_back (5);
		inp.push_back (6);
		inp.push_back (7);
		inp.push_back (8);
		inp.push_back (9);
		inp.push_back (10);

		std::vector <int> expectedResult ;
		expectedResult.push_back(1);
		expectedResult.push_back(2);
		expectedResult.push_back(3);
		expectedResult.push_back(4);

		std::vector <int> op;
		Util util;
		std::vector <int>::iterator startOfSubSequence = inp.begin();
		int subSequenceSize = 0;
		Util::RET ret = util.findSubsequence<Util::asc<int> > (inp, startOfSubSequence, subSequenceSize);
		if (ret == Util::SUCCESS)
		{

			printResult(inp, startOfSubSequence, subSequenceSize);
			std::vector <int> ::iterator itrend = startOfSubSequence;
			if (std::equal(startOfSubSequence, itrend, expectedResult.begin()))
				bRet = true;
		}

		return bRet;
	}


	bool
	TestSubSequence::TestMaxSubsequenceOf1()
	{
		bool bRet (false);
		std::vector<int> inp;
		inp.push_back (8);
		inp.push_back (6);
		inp.push_back (3);
		inp.push_back (1);

		std::vector <int> expectedResult ;
		expectedResult.push_back(8);

		std::vector <int> op;
		Util util;
		std::vector <int>::iterator startOfSubSequence = inp.begin();
		int subSequenceSize = 0;
		Util::RET ret = util.findSubsequence<Util::asc<int> > (inp, startOfSubSequence, subSequenceSize);
		if (ret == Util::SUCCESS)
		{

			printResult(inp, startOfSubSequence, subSequenceSize);
			std::vector <int> ::iterator itrend = startOfSubSequence;
			if (std::equal(startOfSubSequence, itrend, expectedResult.begin()))
				bRet = true;
		}

		return bRet;
	}

	bool
	TestSubSequence::SelectFirstOf2EqualSubsequence()
	{
        bool bRet (false);
		std::vector<int> inp;
		inp.push_back (8);
		inp.push_back (9);
		inp.push_back (1);
		inp.push_back (2);
		inp.push_back (3);
		inp.push_back (2);
		inp.push_back (1);
		inp.push_back (4);
		inp.push_back (5);
		inp.push_back (6);
		inp.push_back (9);
		inp.push_back (10);

		std::vector <int> expectedResult ;
		expectedResult.push_back(1);
		expectedResult.push_back(2);
		expectedResult.push_back(3);


		std::vector <int> op;
		Util util;
		std::vector <int>::iterator startOfSubSequence = inp.begin();
		int subSequenceSize = 0;
		Util::RET ret = util.findSubsequence<Util::asc<int> > (inp, startOfSubSequence, subSequenceSize);
		if (ret == Util::SUCCESS)
		{

			printResult(inp, startOfSubSequence, subSequenceSize);
			std::vector <int> ::iterator itrend = startOfSubSequence;
			if (std::equal(startOfSubSequence, itrend, expectedResult.begin()))
				bRet = true;
		}

		return bRet;
	}

	bool
	TestSubSequence::TestNormalCaseDsc()
	{
		bool bRet (false);
		return bRet;
	}

	bool
	TestSubSequence::TestEmptyCaseDsc()
	{
		bool bRet (false);
		return bRet;
	}

	bool
	TestSubSequence::TestCaseWith1ElementDsc()
	{
		bool bRet (false);
		return bRet;
	}

	bool
	TestSubSequence::TestCaseWithSubsequenceOf1Dsc()
	{
		bool bRet (false);
		return bRet;
	}
}

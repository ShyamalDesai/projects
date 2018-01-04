#pragma once
namespace hartree_test
{

	class TestSubSequence
	{
	public:
		TestSubSequence(void);
		~TestSubSequence(void);

		static bool TestNormalCaseAsc();
		static bool TestEmptyCaseAsc();
		static bool TestCaseWith1ElementAsc();
		static bool TestCaseWithFullInputAsSubsequenceAsc();
		static bool TestMaxSubsequenceOf1();
		static bool SelectFirstOf2EqualSubsequence();

		static bool TestNormalCaseDsc();
		static bool TestEmptyCaseDsc();
		static bool TestCaseWith1ElementDsc();
		static bool TestCaseWithSubsequenceOf1Dsc();

	};
}

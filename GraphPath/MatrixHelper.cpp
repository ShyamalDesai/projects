#include "MatrixHelper.h"

bool
MatrixHelper::testMatrix()
{
	std::vector <std::vector <int> > a = { { 2, 2, 2 },
	{ 2, 2, 2 },
	{ 2, 2, 2 } };
	std::vector <std::vector <int> > b = { { 1, 2 },
	{ 3, 4 },
	{ 5, 6 } };

	std::vector <std::vector <int> > result = MatrixHelper::multiply(a, b);
	MatrixHelper::printMatrix(result);
	std::vector <std::vector <int> > expectedResult = { {18, 24},
														{18, 24},
														{ 18, 24 } };
	return verifyMatrix(result, expectedResult);
}

bool 
MatrixHelper::testMatrixPblm()
{
	bool bRet(false);
	std::vector <std::vector <int> > a = { { 0, 1, 1 },
	{ 1, 0, 1 },
	{ 1, 1, 0 } };
	

	std::vector <std::vector <int> > result = MatrixHelper::pow(a, 2);
	MatrixHelper::printMatrix(result);

	std::vector <std::vector <int> > expectedResult = { { 2, 1, 1 },
	{ 1, 2,  1 },
	{ 1, 1, 2 } };
	if (verifyMatrix(result, expectedResult))
	{


		std::vector <std::vector <int> > result2 = MatrixHelper::pow(a, 3);
		MatrixHelper::printMatrix(result2);

		std::vector <std::vector <int> > expectedResult2 = { { 2, 3, 3 },
															{ 3, 2,  3 },
															{ 3, 3, 2 } };
		if (verifyMatrix(result2, expectedResult2))
		{
			std::vector <std::vector <int> > result3 = MatrixHelper::pow(a, 4);
			MatrixHelper::printMatrix(result3);

			//std::vector <std::vector <int> > expectedResult3 = { { 2, 3, 3 },



			std::vector <std::vector <int> > expectedResult3 = { { 6, 5, 5 },
																	{ 5, 6,  5 },
																	{ 5, 5, 6 } };
			if (verifyMatrix(result3, expectedResult3))
			{
				return true;
			}
		}
	}

	return bRet;
}

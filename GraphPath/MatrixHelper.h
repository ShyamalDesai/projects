#pragma once
#include <vector>
#include <iostream>
class MatrixHelper
{
public:
	//takes a 2 dimensional vector as a matrix
//-----------------------------------------------------------------------------------------
	//print row in 1 line with a tab for each column
//-----------------------------------------------------------------------------------------
	template <typename T> 
	static void printMatrix(const std::vector <std::vector <T> >& matrix)
	{
		if (!matrix.empty())
		{
			for (int i = 0; i <(int) matrix.size(); ++i)
			{
				for (int j = 0; j < (int) matrix[0].size(); ++j)
				{
					std::cout << matrix[i][j] << "\t";
				}
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}

//-----------------------------------------------------------------------------------------
	// validate that matrices are not empty
	// validate that m*n and n*r matrix condition is satisfied
	// return an empty vector on failed validation (quite expensive for a no result)
	// resize resultant vector rows and columns to use indexes (a resize can be done in a inner loop)
	// multiply/add row vector of left with column vector of right
//-----------------------------------------------------------------------------------------

	template <typename T>
	static 
	std::vector < std::vector <T> > 
	multiply(const std::vector <std::vector <T> >& left, 
			const std::vector <std::vector <T> >& right)
	{

		//check if multiplication is possible
		if ((!left.empty() && !right.empty()) && left[0].size() == right.size())
		{
			int m = left.size();
			int n = right.size();
			int r = right[0].size();

			std::vector < std::vector <T> > result;
			result.resize(m);
			for (int sz = 0; sz < m; ++sz)
			{
				result[sz].resize(r);
			}
			
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < r; ++j)
				{
					for (int k = 0; k < n; ++k)
					{

						/*********************This can be done in a parallel for-each loop***********/
						result[i][j] += left[i][k] * right[k][j];
					}
				}
			}
			return result;
		}
		else
		{
			//return empty vector
			return  std::vector < std::vector <T> >();
		}
	}

//-------------------------------------------------------------------------------
	//dup a 2d vector
//-------------------------------------------------------------------------------

	template <typename T>
	static
	std::vector < std::vector <T> > 
	dup(const std::vector <std::vector <T> >& a)
	{
//		std::cout << "Dup the following:" << std::endl;
//		printMatrix(a);
			 
		std::vector < std::vector <T> > result;
		if (!a.empty())
		{
			result.resize(a.size());
			int colsize = (int) a[0].size();
			for (int sz = 0; sz < colsize; ++sz)
			{
				result[sz].resize(colsize);
			}

			for (int i = 0; i < (int) a.size(); ++i)
			{
				for (int j = 0; j < (int) a[i].size(); ++j)
				{
					

					result[i][j] = a[i][j];
					
				}
			}
		}
//		std::cout << " The dup is " << std::endl;
//		printMatrix(result);
		return result;
	}

//========================================================================
	//exponentiation of a matix using euler's fast power algo
//========================================================================
	template <typename T>
	static 
	std::vector < std::vector <T> >  
	pow(const std::vector <std::vector <T> >& a, 
		const uint16_t exp)
	{
		
		std::vector < std::vector <T> > result = MatrixHelper::dup(a);
		uint16_t  n = exp;
		while (n > 1) {
			if (n % 2 == 0)
			{
				result = multiply(result, result);
//				std::cout << " expoed " << std::endl;
//				printMatrix(result);
				n /= 2;
			}
			else {
				result = multiply(a, pow (result, n-1));
//				std::cout << " expoed " << std::endl;
//				printMatrix(result);
				break;
			}
		}
		return result;
	}


//---------------------------------------------------------------------
	//verify 2 matrices to see if they are equal. 
	//an equality operator can be overloaded to call this function
	//ensure they are not empty, has similar rows and columns 
	//step by each element and compare left and right
	//exit with false on any mismatch
	//else return true;
//---------------------------------------------------------------------
	template <typename T>
	static bool 
	verifyMatrix(const std::vector <std::vector <T> >& result, 
	const std::vector <std::vector <T> >& expectedResult)
	{
		bool bRet = true;
		if (!result.empty() && !expectedResult.empty() && result.size() == expectedResult.size() && result[0].size() == expectedResult[0].size())
		{
			for (int i = 0; i < (int) result.size(); ++i)
			{
				for (int j = 0; j < (int) result[0].size(); ++j)
				{
					if (result[i][j] != expectedResult[i][j])
					{
						bRet = false;
						break;
					}
				}
			}

		}
		else
			bRet = false;
		return bRet;
	}

	static bool testMatrix(); //normal matric multiplication
	static bool testMatrixPblm();
	//test boundary 2 empty vectors, 1 empty
	//test different colums where multiplication is not possible
	//test large nos for overflow (fix to throw limit exception)
	//test larger sizes of left and right matrix
};


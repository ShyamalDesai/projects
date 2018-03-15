#include "TestDetectBreach.h"
#include <vector>
#include "MatrixHelper.h"
#include "util.h"
#include <algorithm>
std::vector <std::vector <int> > twoPath{
	//		A    B    C    D    E    F    G    H    I    J
	/*A*/{ 0,   1  },

	/*B*/{ 1,   0  },

	
};


std::vector <std::vector <int> > threePath{
	//		A    B    C    D    E    F    G    H    I    J
	/*A*/{  0,   1,   1},

	/*B*/{  1,   0,   0},

	/*C*/{  1,   0,   0},


};

std::vector <std::vector <int> > threePathAllConn{
	//		A    B    C    D    E    F    G    H    I    J
	/*A*/{ 0,   1,   1 },

	/*B*/{ 1,   0,   1 },

	/*C*/{ 1,   1,   0 },


};


TestDetectBreach::TestDetectBreach()
{
}


TestDetectBreach::~TestDetectBreach()
{
}


bool 
TestDetectBreach::test2Points()
{
	bool bRet = false;
	int numbers_of_ways = 0;// init the return value to 0;
	std::vector < std::vector <int> >  expo = MatrixHelper::pow(twoPath, 2);
	Adder<int> adder = std::for_each(expo[0].cbegin(), expo[0].cend(), Adder<int>());

	numbers_of_ways = adder.getSum();
	MatrixHelper::printMatrix(expo);

	if (1 == numbers_of_ways)
	{

		std::vector < std::vector <int> >  expo3 = MatrixHelper::pow(threePath, 1);
		adder = std::for_each(expo3[0].cbegin(), expo3[0].cend(), Adder<int>());

		numbers_of_ways = adder.getSum();
		MatrixHelper::printMatrix(expo3);

		if (2 == numbers_of_ways)
		{
			std::vector < std::vector <int> >  expo4 = MatrixHelper::pow(threePathAllConn, 3);
			adder = std::for_each(expo4[0].cbegin(), expo4[0].cend(), Adder<int>());

			numbers_of_ways = adder.getSum();
			MatrixHelper::printMatrix(expo4);

			bRet = true;
		}
	}

	return bRet;

}

bool 
TestDetectBreach::test3Points()
{
	return false;
}

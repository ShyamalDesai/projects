// GraphPathCount.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include "MatrixHelper.h"
#include <vector>
#include <algorithm>
#include "util.h"
#include "TestDetectBreach.h"
//----------------------------------------------------------------------------
//implement the algo to count number of paths in a graph using adjacency matrix
//where a the number of paths of size K from node i to node j is the exponentiation 
//of the adjacency matrix by K and the value of matrix [i][j] will have the count of
//number of paths of size k from i to j

//the first step is to create the adjacency matrix of the figure given (by labelling each vertex) (the edge value is 1 in all cases in this example)


//----------------------------------------------------------------------------

std::vector <std::vector <int> > adjPath {
//		A    B    C    D    E    F    G    H    I    J
/*A*/  {0,   1,   0,   0,   1,   0,   0,   0,   0,   0},

/*B*/  {1,   0,   1,   0,   0,   0,   0,   1,   0,   0},

/*C*/  {0,   1,   0,   1,   0,   0,   0,   0,   1,   0},

/*D*/  {0,   0,   1,   0,   1,   0,   0,   1,   0,   0},

/*E*/  {1,   0,   0,   1,   0,   1,   0,   0,   0,   0},

/*F*/  {0,   0,   0,   0,   1,   0,   1,   1,   0,   1},

/*G*/  {0,   0,   0,   0,   0,   1,   0,   1,   0,   1},

/*H*/  {0,   1,   0,   1,   0,   0,   1,   0,   1,   1},

/*I*/  {0,   0,   1,   0,   0,   1,   0,   1,   0,   0},

/*J*/  {0,   0,   0,   0,   0,   0,   1,   1,   0,   0}

};

//TODO: Your data structure, data, function definitions
//Please refactor your submission to show good coding style.
#define TOWNSTOVISITPERDAY 10
int main()
{

/*-----------------------------------------test breach*/

	//TestDetectBreach tst;
	//tst.test2Points();
	//MatrixHelper mh;
	//mh.testMatrixPblm();
/*--------------------------------------------*/
	int numbers_of_ways = 0;// init the return value to 0;
	std::vector < std::vector <int> >  expo = MatrixHelper::pow(adjPath, TOWNSTOVISITPERDAY);

	//the first row is a path from starting point A to rest of the points
	//a sum of the first vector is the number of ways to travel from a till 10 towns
	
	Adder<int> adder = std::for_each(expo[0].cbegin(), expo[0].cend(), Adder<int>());
	numbers_of_ways = adder.getSum();

	std::cout << "Number of path from the start point in the given diagram for 10 town visits is " << numbers_of_ways << std::endl;

	return numbers_of_ways;
}

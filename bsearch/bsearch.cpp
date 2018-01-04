#include <iostream>

#include <vector>
#include <iterator>
/*
 *
 *
 */
template <typename ITER, typename VALTYPE>
bool
bsearch ( ITER left, ITER right,  const VALTYPE val)
{
	bool bRet (false);

	if (left > right)
	{

		std::cout << "left greater than right" << std::endl;
		return false;
	}
	auto distance = std::distance (left, right);
	std::cout << " disance calculated = " << distance << std::endl;
	distance = distance/2;
	std::cout << " disance halved = " << distance << std::endl;

	ITER iter = left;
	std::advance (iter, distance);

	if (*iter == val)
	{
		std::cout << " Found the value " << val << std::endl;
		bRet =  true;
	}
	else if (val > *iter)
	{
		++iter;
		std::cout << " val greater than value of iter " << *iter << std::endl;
		bsearch (iter, right, val);
	}
	else 
	{
		--iter ;
		std::cout << " val less than the value of iter " << *iter << std::endl; 
		bsearch (left, iter, val);
	}

	return bRet;
}


int main ()
{
	std::vector <int> primevalues = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

	if (bsearch<std::vector<int>::const_iterator, int> (primevalues.begin(), primevalues.end(), 67))
			std::cout << "Found value 67 in the array " << std::endl;
	else
			std::cout <<" did not find the value 67 in the array " << std::endl;

	if (!bsearch<std::vector<int>::const_iterator, int> (primevalues.begin(), primevalues.end(), 30))
			std::cout << "could not find value 30 in prime values table " << std::endl;

}

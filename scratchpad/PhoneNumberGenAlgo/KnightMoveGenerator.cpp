#include "KnightMoveGenerator.h"
#include <sstream>

KnightMoveGenerator::KnightMoveGenerator()
{

	std::vector <int> values(4, 0);
	_moves[0] = (values = {  6, 4, -1});
	_moves[1] = (values = {  6, 8, -1});
	_moves[2] = (values = {  7, 9, -1});
	_moves[3] = (values = {  4, 8, -1});
	_moves[4] = (values = {  3, 9, 0 });
	_moves[5] = (values = {  -1, -1, -1 });
	_moves[6] = (values = {  1, 0, 7 });
	_moves[7] = (values = {  2, 6, -1 });
	_moves[8] = (values = {  1, 3, -1 });
	_moves[9] = (values = {  2, 4, -1});

}


KnightMoveGenerator::~KnightMoveGenerator()
{
}

const std::vector <int>& 
KnightMoveGenerator::getMovesFromPosition(const int val ) const
{
	//check for boundaries
	if (val > 9 || val < 0)
	{
		std::stringstream ss("Invalid input values given to Knight Move Generator: Moves can only be generated for values between 0-9");
		ss << ". Value given: " << val;
		throw std::runtime_error(ss.str());
	}
	KNIGHTMOVESDEF_CONST_ITER iter = _moves.find(val);
	if (iter == _moves.end())
	{
		std::stringstream ss("Knight Move Generator: No Moves defined for value: ");
		ss << val;
		throw std::runtime_error(ss.str());

	}
	return iter->second;
	
	
}

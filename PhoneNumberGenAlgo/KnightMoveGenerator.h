#pragma once
#include <map>
#include <vector>

typedef std::map<int, std::vector<int> > KNIGHTMOVESDEF;
typedef KNIGHTMOVESDEF::const_iterator KNIGHTMOVESDEF_CONST_ITER;
typedef KNIGHTMOVESDEF::iterator KNIGHTMOVESDEF_ITER;
class KnightMoveGenerator //:	public IPhoneNumberGenerator
{
public:
	KnightMoveGenerator();
	~KnightMoveGenerator();

	const std::vector <int>& getMovesFromPosition(const int val) const ;
	
private: 
	KNIGHTMOVESDEF _moves;
};


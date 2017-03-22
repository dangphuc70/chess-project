#include "Rules.h"
#include "SomeMoveValidators.h"

using namespace std;


Rules::Rules()
{
	// make the validators
	RookValidator * rook = new RookValidator;
	KnightValidator * knight = new KnightValidator;
	BishopValidator * bishop = new BishopValidator;
	QueenValidator * queen = new QueenValidator;
	KingValidator * king = new KingValidator;
	PawnValidator * pawn = new PawnValidator;
	// put in the map
	validators.insert(std::pair<string, MoveValidator*>(rook->identifier(), rook));
	validators.insert(std::pair<string, MoveValidator*>(knight->identifier(), knight));
	validators.insert(std::pair<string, MoveValidator*>(bishop->identifier(), bishop));
	validators.insert(std::pair<string, MoveValidator*>(queen->identifier(), queen));
	validators.insert(std::pair<string, MoveValidator*>(king->identifier(), king));
	validators.insert(std::pair<string, MoveValidator*>(pawn->identifier(), pawn));
}


Rules::~Rules()
{
	for (auto i = validators.begin(); i != validators.end(); ++i)
	{
		delete (*i).second;
	}
}

const MoveValidator * Rules::find(const std::string & key) const
{
	auto r = validators.find(key);
	if (r == validators.end())
		return nullptr;
	else
		return (*r).second;
}

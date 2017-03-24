#include "Move.h"
#include <sstream>


Move::Move(const Coordinate & _From,
	const Coordinate & _To,
	const string & _MovePiece,
	const string & _TakenPiece)
	:
	from_(_From),
	to_(_To),
	commonName_(_MovePiece),
	taken_(_TakenPiece)
{
}

Move::~Move()
{
}

const string & Move::MovePiece() const
{
	return commonName_;
}

const string & Move::TakenPiece() const
{
	return taken_;
}

string Move::toString() const
{

	return commonName_ +
		',' + from_.toCommonCoordinate() +
		',' + to_.toCommonCoordinate() +
		';' +
		taken_;
}

bool Move::isTakeMove() const
{
	return taken_.empty() || (taken_.length() == 0);
}

bool Move::empty() const
{
	return commonName_.empty() || (commonName_.length() == 0);
}

ostream & operator<<(ostream & o, const Move & m)
{
	o << m.commonName_ << ' ';
	o << m.from_ << ' ';
	o << m.to_ << ' ';
	o << m.taken_ << endl;
	return o;
}

istream & operator >> (istream & i, Move & m)
{
	i >> m.commonName_ >> m.from_ >> m.to_ >> m.taken_;
	return i;
}

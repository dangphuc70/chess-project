#include "Rook.h"



Rook::Rook()
{
}


Rook::~Rook()
{
}

bool Rook::validate_move(const Coordinate & s, const Coordinate & d)
{
	return (s.x == d.x) || (s.y == d.y);
}

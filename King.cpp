#include "King.h"
#include <cmath>


King::King(const std::string& _Symbol, PieceOut::Color _Color) : Piece(_Symbol, _Color)
{
}


King::~King()
{
}

Piece * King::clone() const
{
	return new King(*this);
}

bool King::validate_move(const Coordinate & _sour, const Coordinate & _dest)
{
	int dx = _dest.x - _sour.x;
	dx = abs(dx);
	int dy = _dest.y - _sour.y;
	dy = abs(dy);
	return (dx <= 1) && (dy <= 1);
}

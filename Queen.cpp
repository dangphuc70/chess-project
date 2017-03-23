#include "Queen.h"
#include <cmath>


Queen::Queen(const std::string& _Symbol, PieceOut::Color _Color) : Piece(_Symbol, _Color)
{
}


Queen::~Queen()
{
}

Piece * Queen::clone() const
{
	return new Queen(*this);
}

bool Queen::validate_move(const Coordinate & s, const Coordinate & d)
{
	int dx = d.x - s.x;
	int dy = d.y - s.y;
	dx = abs(dx);
	dy = abs(dy);
	return (s.x == d.x || s.y == d.y) || (dx == dy);
}

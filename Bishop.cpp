#include "Bishop.h"
#include <cmath>


Bishop::Bishop(const std::string& _Symbol, PieceOut::Color _Color) : Piece(_Symbol, _Color)
{
}


Bishop::~Bishop()
{
}

Piece * Bishop::clone() const
{
	return new Bishop(*this);
}

bool Bishop::validate_move(const Coordinate & s, const Coordinate & d)
{
	int dx = d.x - s.x;
	int dy = d.y - s.y;
	dx = abs(dx);
	dy = abs(dy);
	return (dx == dy);
}

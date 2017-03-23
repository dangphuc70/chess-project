#include "Knight.h"



Knight::Knight(const std::string& _Symbol, PieceOut::Color _Color) : Piece(_Symbol, _Color)
{
}


Knight::~Knight()
{
}

Piece * Knight::clone() const
{
	return new Knight(*this);
}

bool Knight::validate_move(const Coordinate & s, const Coordinate & d)
{
	int dx = d.x - s.x;
	int dy = d.y - s.y;
	dx = abs(dx);
	dy = abs(dy);
	return (dx + dy == 3);
}

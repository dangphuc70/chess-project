#include "Rook.h"



Rook::Rook(const std::string& _Symbol, PieceOut::Color _Color) : Piece(_Symbol, _Color)
{
}


Rook::~Rook()
{
}

Piece * Rook::clone() const
{
	return new Rook(*this);
}

bool Rook::validate_move(const Coordinate & s, const Coordinate & d)
{
	return (s.x == d.x) || (s.y == d.y);
}

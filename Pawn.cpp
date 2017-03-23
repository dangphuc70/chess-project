#include "Pawn.h"



Pawn::Pawn(const std::string& _Symbol, PieceOut::Color _Color) : Piece(_Symbol, _Color)
{
}


Pawn::~Pawn()
{
}

Piece * Pawn::clone() const
{
	return new Pawn(*this);
}

bool Pawn::validate_move(const Coordinate & s, const Coordinate & d)
{
	int dx = d.x - s.x;
	int dy = d.y - s.y;
	if (color() == PieceOut::black) {
		if (dy == 1) return dx == 1 || dx == -1 || dx == 0;
	}
	else if (color() == PieceOut::white) {
		if (dy == -1) return dx == 1 || dx == -1 || dx == 0;
	}
	return false;
}

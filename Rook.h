#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook();
	~Rook();

public:
	//PieceOut
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest);
	// Rook itself has no color
	// PieceOut::Color color() method
	// is for derived BlackRook and WhiteRook to implement
};


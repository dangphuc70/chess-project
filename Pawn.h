#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
	Pawn(const std::string& _Symbol, PieceOut::Color _Color);
	~Pawn();
	virtual Piece * clone() const;

	bool validate_move(const Coordinate& _sour, const Coordinate& _dest);
};


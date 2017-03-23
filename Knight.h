#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(const std::string& _Symbol, PieceOut::Color _Color);
	~Knight();
	virtual Piece * clone() const;

	bool validate_move(const Coordinate& _sour, const Coordinate& _dest);
};


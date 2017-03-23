#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const std::string& _Symbol, PieceOut::Color _Color);
	~Bishop();
	virtual Piece * clone() const;

	bool validate_move(const Coordinate& _sour, const Coordinate& _dest);
};


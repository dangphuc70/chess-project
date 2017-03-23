#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(const std::string& _Symbol, PieceOut::Color _Color);
	~Queen();
	virtual Piece * clone() const;

	bool validate_move(const Coordinate& _sour, const Coordinate& _dest);
};


#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(const std::string& _Symbol, PieceOut::Color _Color);
	virtual ~Rook();
	virtual Piece * clone() const;

public:
	//PieceOut
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest);

};


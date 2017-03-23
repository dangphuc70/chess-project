#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(const std::string& _Symbol, PieceOut::Color _Color);
	~King();
	virtual Piece * clone() const;


public:
	//PieceOut
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest);
};


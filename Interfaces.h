#pragma once
#include <string>

#include "Coordinate.h"
class PieceOut // Piece.h
{
public:
	virtual bool validate_move(const Coordinate& _sour, const Coordinate& _dest) = 0;
	enum Color { black, white };
	virtual Color color() = 0;
};

class BoardOut // Board.h
{
public:
	virtual bool validate_move(const Coordinate& _sour, const Coordinate& _dest) = 0;
};

class Text // Piece.h
{
public:
	virtual const std::string & Symbol() = 0;
	virtual size_t SymbolLength() = 0;
};
#pragma once
#include <string>

#include "Coordinate.h"
class PieceOut
{
public:
	virtual bool validate_move(const Coordinate& _sour, const Coordinate& _dest) = 0;
	enum Color { black, white };
	virtual Color color() = 0;
};

class BoardOut
{
public:
	virtual bool validate_move(const Coordinate& _sour, const Coordinate& _dest) = 0;
};

class Text
{
public:
	virtual const std::string & Symbol() = 0;
	virtual size_t SymbolLength() = 0;
};
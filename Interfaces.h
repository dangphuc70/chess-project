#pragma once
#include <string>

#include "Coordinate.h"
#include "Piece.h"
#include <map>

class PieceOut // implemented by Piece
{
public:
	virtual bool validate_move(const Coordinate& _sour, const Coordinate& _dest) = 0;
	enum Color { black, white };
	virtual Color color() = 0;
	virtual const std::string& name() = 0;
};

class BoardOut // implemented by Board
{
public:
	virtual bool validate_move(const Coordinate& _sour, const Coordinate& _dest) = 0;
};

class Text // implemented by Piece
{
public:
	virtual const std::string & Symbol() = 0;
	virtual size_t SymbolLength() = 0;
};

class TextPieceIsomorphism // implemented by Piece
{
public:
	virtual std::string toString() = 0;

	//deleted for the already present Piece constructors
	//virtual Piece toPiece(const std::string& piece_representation_in_string) = 0;
};


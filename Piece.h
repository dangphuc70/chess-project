#pragma once
#include <string>
#include "Interfaces.h"

class Piece : public PieceOut, public Text
{
public:
	Piece(const std::string& _Symbol, PieceOut::Color _Color);
	virtual ~Piece();

	virtual Piece * clone() const = 0;

public:
	//PieceOut
	virtual bool validate_move(const Coordinate& _sour, const Coordinate& _dest) = 0;

	//PieceOut
	virtual PieceOut::Color color();

	//Text
	const std::string & Symbol();
	//Text
	size_t SymbolLength();

private:
	std::string symbol;
	PieceOut::Color colr;

};


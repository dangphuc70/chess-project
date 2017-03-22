#pragma once
#include <string>
#include "Interfaces.h"
#include "MoveValidator.h"

class Piece : public PieceOut, public Text, public TextPieceIsomorphism
{
public:
	Piece();
	Piece(const std::string& string_equivalence_of_piece, const char delim = default_delim);
	~Piece();


public:
	//TextPieceIsomorphism
	std::string toString(); // ? use <sstream> : similar to iostream but in to and out of string

public:
	//PieceOut
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest) const;
	//PieceOut
	PieceOut::Color color();
	//PieceOut
	const std::string& name();
	
	//Text
	const std::string& Symbol();
	//Text
	size_t SymbolLength();

private:
	PieceOut::Color color_code;
	std::string name0;
	std::string symbol0;
	const MoveValidator * validator_ptr;

private:
	static const char default_delim = ':';

};


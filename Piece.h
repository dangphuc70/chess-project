#pragma once
#include <string>
#include "Interfaces.h"
#include "MoveValidator.h"

class Piece : public PieceOut, public TextPieceIsomorphism
{
public:
	Piece(PieceOut::Color _Color=PieceOut::white, const MoveValidator * _Validator=nullptr, const std::string& _OnBoardSymbol="");
	~Piece();


public:
	//TextPieceIsomorphism
	std::string toString(); // ? use <sstream> : similar to iostream but in to and out of string
	const std::string & OnBoardSymbol();


private:
	static const char default_delim = ':';
	std::string onboardsymbol;


public:
	//PieceOut
	bool validate_move(const Coordinate& _sour, const Coordinate& _dest);
	//PieceOut
	PieceOut::Color color();
	


private:
	PieceOut::Color color_code;
	const MoveValidator * validator_ptr;


};


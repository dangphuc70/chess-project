#pragma once
#include "Rook.h"

class BlackRook : public Rook
{
public:
	BlackRook();
	~BlackRook();

public:
	//PieceOut
	PieceOut::Color color();
	//PieceOut
	const std::string & name();

	//Text
	const std::string & Symbol();
	//Text
	size_t SymbolLength();

private:
	std::string text_name;
	std::string symbol;
};


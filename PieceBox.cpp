#include "PieceBox.h"
#include <string>
#include <iostream>

void PieceBox::Insert(const string & key, Piece * p) {
	box.insert(make_pair(key, unique_ptr<Piece>(p)));
}

PieceBox::PieceBox()
{
	PieceOut::Color black = PieceOut::black;
	PieceOut::Color white = PieceOut::white;
	Insert("BR", new Rook(" B R ", black));
	Insert("BN", new Knight(" B N ", black));
	Insert("BB", new Bishop(" B B ", black));
	Insert("BQ", new Queen(" B Q ", black));
	Insert("BK", new King(" B K ", black));
	Insert("BP", new Pawn(" B P ", black));

	Insert("WR", new Rook(" W R ", white));
	Insert("WN", new Knight(" W N ", white));
	Insert("WB", new Bishop(" W B ", white));
	Insert("WQ", new Queen(" W Q ", white));
	Insert("WK", new King(" W K ", white));
	Insert("WP", new Pawn(" W P ", white));
}


PieceBox::~PieceBox()
{
}


unique_ptr<Piece> PieceBox::operator[](const string & key)
{
		auto result = box.find(key);
		if (result == box.end()) {
			throw string(key + " not found");
		}
		Piece * p = box[key]->clone();
		return unique_ptr<Piece>(p);
}

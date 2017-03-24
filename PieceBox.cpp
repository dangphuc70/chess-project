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
	Insert("BR", new Rook(" bBR ", black));
	Insert("BN", new Knight(" bBN ", black));
	Insert("BB", new Bishop(" bBB ", black));
	Insert("BQ", new Queen(" bBQ ", black));
	Insert("BK", new King(" bBK ", black));
	Insert("BP", new Pawn(" bBP ", black));

	Insert("WR", new Rook(" wWR ", white));
	Insert("WN", new Knight(" wWN ", white));
	Insert("WB", new Bishop(" wWB ", white));
	Insert("WQ", new Queen(" wWQ ", white));
	Insert("WK", new King(" wWK ", white));
	Insert("WP", new Pawn(" wWP ", white));
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

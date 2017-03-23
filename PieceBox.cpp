#include "PieceBox.h"
#include <string>
#include <iostream>

void Insert(map<string, unique_ptr<Piece>> &a, const string & key, Piece * p) {
	a.insert(make_pair(key, unique_ptr<Piece>(p)));
}

PieceBox::PieceBox()
{
	PieceOut::Color black = PieceOut::black;
	PieceOut::Color white = PieceOut::white;
	Insert(box, "BR", new Rook(" bBR ", black));
	Insert(box, "BN", new Knight(" bBN ", black));
	Insert(box, "BB", new Bishop(" bBB ", black));
	Insert(box, "BQ", new Queen(" bBQ ", black));
	Insert(box, "BK", new King(" bBK ", black));
	Insert(box, "BP", new Pawn(" bBP ", black));

	Insert(box, "WR", new Rook(" wWR ", white));
	Insert(box, "WN", new Knight(" wWN ", white));
	Insert(box, "WB", new Bishop(" wWB ", white));
	Insert(box, "WQ", new Queen(" wWQ ", white));
	Insert(box, "WK", new King(" wWK ", white));
	Insert(box, "WP", new Pawn(" wWP ", white));
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
		Piece * p = box[key].get()->clone();
		return unique_ptr<Piece>(p);
}

#pragma once
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

#include <map>
#include <string>
#include <memory>

using namespace std;

class PieceBox
{
public:
	PieceBox();
	~PieceBox();

	unique_ptr<Piece> operator[](const string & key);


private:
	typedef string _CommonName;
	map<_CommonName, unique_ptr<Piece>> box;


	// for ease of syntax
	void Insert(const string & key, Piece * p);

};


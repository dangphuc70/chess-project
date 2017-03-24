#pragma once
#include <iostream>
#include <string>
#include "Coordinate.h"
using namespace std;
class Move
{
	friend ostream& operator<<(ostream& o, const Move& m);
	friend istream& operator>> (istream& i, Move& m);
public:
	Move(const Coordinate& _From = { 0, 0 },
		const Coordinate& _To = { 0, 0 },
		const string & _MovePiece = "",
		const string & _TakenPiece = "");

	~Move();

	const string& MovePiece() const;
	const string& TakenPiece() const;
	string toString() const;
	bool isTakeMove() const;
	bool empty() const;

private:
	string commonName_;
	Coordinate from_;
	Coordinate to_;
	string taken_; // CommonName of piece taken if this is a take move
};


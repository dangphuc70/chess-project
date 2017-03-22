#include <iostream>
#include "Game.h"
#include "Interfaces.h"
#include "Piece.h"

void main()
{
	using namespace std;
	
	Game game(3, 7);
	Piece emptyPiece;
	game.place({0,0}, &emptyPiece);

	game.draw();
	cout << "----------------------------------------------" << endl;

	game.move({ 0,0 }, { 5,0 });
	game.draw();


	system("PAUSE");
}
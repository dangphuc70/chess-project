#include <iostream>
#include "Game.h"
#include "Interfaces.h"
#include "Rook.h"
#include "King.h"

#include "PieceBox.h"

void main()
{
	using namespace std;
	{
		Game game(3, 7);
		/*unique_ptr<Piece> blackRook(new Rook(" BRK ", PieceOut::black)); 
		unique_ptr<Piece> blackKing(new King(" BKG ", PieceOut::black));
		
		game.place({0,0}, blackKing, unique_ptr<string>(new string("BK")));
		game.place({5,5}, blackRook, unique_ptr<string>(new string("BR")));*/

		PieceBox box;

		game.place({0,0}, box["WQ"], unique_ptr<string>(new string("WQ")));
		game.place({ 0,1 }, box["WR"], unique_ptr<string>(new string("WR")));
		game.place({ 5,5 }, box["BR"], unique_ptr<string>(new string("BR")));


		game.draw();
		cout << "-----------------------------------------------------------" << endl;

		game.move({ 0,0 }, { 1,0 });
		game.draw();

		game.save("savedgame.txt");

		game.clear();
		game.draw();

		game.load("savedgame.txt");
		game.draw();
	}
	_CrtDumpMemoryLeaks();
	system("PAUSE");
}
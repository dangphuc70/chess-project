#include <iostream>
#include "BlackRook.h"
#include "Game.h"
#include "Interfaces.h"

void main()
{
	using namespace std;
	
	Game game(3, 7);
	game.place({0,0}, new BlackRook);

	game.draw();
	cout << "----------------------------------------------" << endl;

	game.move({ 0,0 }, { 5,0 });
	game.draw();


	system("PAUSE");
}
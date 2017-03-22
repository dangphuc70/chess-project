#include <iostream>
#include "BlackRook.h"
#include "Game.h"
#include "Interfaces.h"

void main()
{
	using namespace std;
	
	Game game;
	game.place({0,0}, new BlackRook);

	game.draw();
	cout << "----------------------------------------------" << endl;

	game.move({ 0,0 }, { 0,6 });
	game.draw();


	system("PAUSE");
}
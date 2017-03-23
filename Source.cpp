#include <iostream>
#include <string>
#include "Game.h"
#include "Interfaces.h"
#include "Rook.h"
#include "King.h"

#include "PieceBox.h"

class Menu
{
public:
	Menu();
	~Menu();

private:

};


void main()
{
	using namespace std;
	{
		Game game;
		game.draw();
	}
	_CrtDumpMemoryLeaks();
	system("PAUSE");
}


Menu::Menu()
{
}

Menu::~Menu()
{
}

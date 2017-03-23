#include <iostream>
#include <string>
#include "Game.h"
#include "Interfaces.h"
#include "Rook.h"
#include "King.h"

#include "PieceBox.h"

#include "CommandArgument.h"

class Menu
{
public:
	Menu(Game * game);
	~Menu();
	
	bool input();

private:
	Game * game_;

};


void main()
{
	using namespace std;
	{
		Game game;
		Menu menu(&game);
		game.draw();
		while (menu.input());

		cout << "Goodbye" << endl;
	}
	_CrtDumpMemoryLeaks();
	system("PAUSE");
}

Menu::Menu(Game * game) : game_(game)
{
}

Menu::~Menu()
{
}

bool Menu::input()
{
	string command;
	getline(cin, command);
	CommandArgument c(command);
	switch (c.type()) {
	case CommandArgument::move:
		game_->move(c.from(), c.to());
		game_->draw();
		break;
	case CommandArgument::show:
		game_->draw();
		cout << game_->Turn() << " move" << endl;
		cout << "number of turn" << game_->numberOfTurn() << endl;
		break;
	case CommandArgument::newgame:
		game_->clear();
		game_->load("hello.txt");
		cout << "New game" << endl;
		game_->draw();
		break;
	case CommandArgument::save:
		if (game_->save(c.filename())) {
			cout << "Saved successfully to : " << c.filename() << endl;
		}
		else {
			cout << "Saving unsuccessful : possible reason : failed when opening file " << c.filename() << endl;
		}
		break;
	case CommandArgument::load:
		if (game_->load(c.filename())) {
			cout << "Load successfully from : " << c.filename() << endl;
			game_->draw();
		}
		else {
			cout << "Loading unsuccessful : possible reason : failed when opening file "
				<< c.filename()
				<< " or failed to create file " << c.filename()
				<< endl;
		}
		break;
	
	case CommandArgument::help:
		cout << "Help Page" << endl;
		cout << "Example:" << endl;
		cout << "These are example of all possible commands" << endl 
			<< " move b3 b7" << endl
			<< " show           -- show the current board, current turn (black or white), number of turn" << endl
			<< " save save1.txt -- save current game to file (path) \"save1.txt\"" << endl
			<< " new            -- load a new game -- this does not save current game" << endl
			<< " load save1.txt -- load a game from file (path) \"save1.txt\"" << " -- this does not save current game" << endl
			<< " help           -- show this help page" << endl
			<< " quit           -- quit game" << endl;
		cout << "You can try out these commands sequential to see their functions" << endl;
		break;
	case CommandArgument::quit:
		return false;
		break;
	case CommandArgument::epsilon:
		break;
	}
	return true;
}

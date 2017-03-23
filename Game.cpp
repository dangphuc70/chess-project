#include "Game.h"
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include "PieceBox.h"

using namespace std;

Game::Game(size_t c_h, size_t c_w) : cell_height(c_h), cell_width(c_w), box(),
turn(false), nturn(0)
{
	load("hello.txt");
}


Game::~Game()
{
}

int Game::numberOfTurn()
{
	return nturn;
}

const string & Game::Turn()
{
	return turn ? turnBlack : turnWhite;
}

bool Game::save(const  string filename)
{
	ofstream savefile(filename);

	if (!savefile) {
		cout << "Unable to save to file : " << filename << endl;
		return false;
	}

	cout << "Saving..." << endl;

	for (size_t x = 0; x < Board::chess_board_size_first; ++x) {
		for (size_t y = 0; y < Board::chess_board_size_second; ++y) {
			if (b_map[x][y] != nullptr)
				savefile << x << ' ' << y << ' ' << *(b_map[x][y]) << ' ';
		}
	}
	return true;
}

bool Game::load(const string filename)
{
	ifstream loadfile(filename);

	if (!loadfile) {
		cout << "Unable to load from file : " << filename << endl;
		return false;
	}

	clear(); // clear game
	cout << "Loading..." << endl;
	try {
		Coordinate d = { 0, 0 };
		string chunk;
		while (loadfile) {
			loadfile >> d.x >> d.y;
			cout << d.x << ' ' << d.y << endl;
			loadfile >> chunk;
			cout << chunk << endl;
			place(d, box[chunk], unique_ptr<string>(new string(chunk)));
		}
		return true;
	}
	catch (string e) {
		cout << "Exception being handled" << endl;
		cout << e << endl;
		return false;
	}
}

bool Game::place(const Coordinate & destination, unique_ptr<Piece>& _Piece, unique_ptr<string>& _Key)
{
	bool coordinate_valid = board.valid_coordinate(destination);
	if (coordinate_valid) {
		board[destination] = std::move(_Piece); // this destroys piece already at destination
		                                // and puts piece there
		b_map[destination.x][destination.y] = std::move(_Key);
		
	}
	return coordinate_valid;
}

bool Game::place(const Coordinate & destination, const std::string & _CommonName)
{
	bool coordinate_valid = board.valid_coordinate(destination);
	if (coordinate_valid) {
		board[destination] = std::move(box[_CommonName]); // this destroys piece already at destination
												// and puts piece there
		b_map[destination.x][destination.y] = std::move(unique_ptr<string>(new string(_CommonName)));
	}
	return coordinate_valid;
}

bool Game::validate_move(const Coordinate & source, const Coordinate & destination)
{
	// check if coordinate source is actually a piece
	if (!board[source])
		return false;

	if (!board.valid_coordinate(source) || !board.valid_coordinate(destination))
		return false;

	if (turn == true && board[source]->color() == PieceOut::white) {
		return false;
	}

	if (turn == false && board[source]->color() == PieceOut::black) {
		return false;
	}
	

	// special case : Pawn
	bool BP = false;
	bool WP = false;
	if ( (BP = (*(b_map[source.x][source.y]) == "BP"))
		|| (WP = (*(b_map[source.x][source.y]) == "WP"))) {
	
		if (!board[source]->validate_move(source, destination)) {
			return false;
		}
		int dx = destination.x - source.x;
		int dy = destination.y - source.y;

		if (dx == 0) { // move
			if (board[destination] != nullptr) // obstructed
				return false;
		}
		else { // possible take
			if (board[destination] == nullptr) // nothing to take
				return false;
			else if (board[destination]->color() == PieceOut::black && BP) { // black obstructed by black
				return false;
			}
			else if (board[destination]->color() == PieceOut::white && WP) { // white obstructed by white
				return false;
			}
		}

		return true;
	}
	else
		return board.validate_move(source, destination)
			&& board[source]->validate_move(source, destination);
	
}

bool Game::move(const Coordinate & s, const Coordinate & d)
{
	bool valid = validate_move(s, d);
	if (valid) {
		board[d] = std::move(board[s]);
		b_map[d.x][d.y] = std::move(b_map[s.x][s.y]);
		++nturn;
		turn = !turn;
	}
	return valid;
}



// helper
class R
{
public:
	R(size_t im, size_t jm, size_t i0 = 0, size_t j0 = 0);
	~R();

	
public:
	// ~not used
	void draw();


private:
	size_t i0;
	size_t j0;

	size_t im;
	size_t jm;

public:
	enum where {
			top_left = 0,
			horizontal_side = 1,
			top_right = 2,
			vertical_side = 3,
			bottom_right = 4,
			bottom_left = 5,
			inside = 6,
			// probably not used in Game (the following 2 elements)
			edge_region = 7,

	};

	where position(size_t i, size_t j);
};


void Game::draw()
{
	bool coordinate_marker = true;

	const size_t black = 0;
	const size_t white = 1;
	const unsigned char border[2][7] = {
		{ 176, 176, 176, 176, 176, 176, 176 },
		//{201, 205, 187, 186, 188, 200, 32},
		{ 32, 32, 32, 32, 32, 32, 32 }
		//{ 218, 196, 191, 179, 217, 192, 32 }
		
	};
	const unsigned char board_border[6] = {
		218, 196, 191, 179, 217, 192
	}; // no need for interior, just borders

	size_t b_width = Board::chess_board_size_second * cell_width + 2;
	size_t b_height = Board::chess_board_size_first * cell_height + 2;

	R cell_regionist(cell_height, cell_width);
	R board_regionist(b_height, b_width);


	if (coordinate_marker) {
		cout << ' ';
		for (size_t x = 0; x < Board::chess_board_size_second; ++x) {
			for (size_t i = 0; i < cell_width; ++i) {
				if (i == cell_width / 2) cout << char('a' + x);
				else cout << ' ';
			}
		}
		cout << endl << ' ';
	}


	size_t b_h = 0;
	for (size_t b_w = 0; b_w < b_width; ++b_w) {
		cout << board_border[board_regionist.position(b_h, b_w)];
	} cout << endl;


	//summary of recursive structure that's about to happen
	//traverse: board row - -> unit line of board row - -> cell in row - -> unit line of cell
	//unit lines of cells are concatenable on one line
	//everything is nearly concatenable (vertically)
	//a picture would explain better (unfortunately not provided)

	size_t color = 0;
	// notes about (i,j) and (x,y) at end of scope
	for (size_t y = 0; y < Board::chess_board_size_first; ++y) { // traverse board -- up-down
		
		// render line-by-line
		for (size_t j = 0; j < cell_height; ++j) {

			// line start here
			
			bool middle = (j == cell_height / 2); // if j is at about middle of the cell (height - wise)
			if (coordinate_marker && middle) cout << (8-y);
			else if (coordinate_marker) cout << ' ';
			cout << board_border[R::vertical_side];
			
			for (size_t x = 0; x < Board::chess_board_size_second; ++x) { // traverse board -- left-right
																		  // determine cell color
																		  // x and y are both determined here
				color = (black_cell({ x,y })) ? (0) : (1);
				// 0 : black
				// 1 : white
				for (size_t i = 0; i < cell_width; ++i) {
					R::where p = cell_regionist.position(j, i);
					if (board[{x, y}] != nullptr
						&& p == R::vertical_side
						&& middle) {
						cout << border[color][R::vertical_side]
							<< (board[{x,y}]->Symbol())
							<< border[color][R::vertical_side];
						break; // this cell line unit done
					}
					else {
						cout << border[color][p];
					}
				}	
			}


			if (coordinate_marker && middle) cout << board_border[R::vertical_side] << (8 - y);
			else 
			// j is a line
			cout << board_border[R::vertical_side];

			cout << endl;
			// line end here
			               // this line unit done
						  // line break
		}
	}
	
	if (coordinate_marker) cout << ' ';

	b_h = b_height - 1;
	for (size_t b_w = 0; b_w < b_width; ++b_w) {
		cout << board_border[board_regionist.position(b_h, b_w)];
	} cout << endl;
	

	if (coordinate_marker) {
		cout << ' ';
		for (size_t x = 0; x < Board::chess_board_size_second; ++x) {
			for (size_t i = 0; i < cell_width; ++i) {
				if (i == cell_width / 2) cout << char('a' + x);
				else cout << ' ';
			}
		}
		cout << endl;
	}

	 // (i,j) maps printed cell (including borders)
	// each character is a (i,j)

	 // (x,y) maps the cells on the chess board
	// each cell is a (x,y)
}

void Game::clear()
{
	for (size_t x = 0; x < Board::chess_board_size_first; ++x) {
		for (size_t y = 0; y < Board::chess_board_size_second; ++y) {
			board[{x, y}].reset();
			b_map[x][y].reset();
		}
	}
}

bool Game::black_cell(const Coordinate & coor)
{
	return (coor.x + coor.y) % 2 != 0;
}

Coordinate Game::to_coordinate(char letter, size_t number)
{
	if (letter >= 'a' && letter <= 'h') {
		if (number >= 1 && number <= 8) {
			return {size_t(letter-'a'), 8-number};
		}
	}
	return {0,0};
}



R::R(size_t im, size_t jm, size_t i0, size_t j0)
{
	if (im > i0 && jm > j0) {
		this->i0 = i0;
		this->j0 = j0;
		this->im = im;
		this->jm = jm;
	}
	else {
		this->i0 = 0;
		this->j0 = 0;
		this->im = im;
		this->jm = jm;
	}
}

R::~R()
{
}

void R::draw()
{
	const unsigned char t_left = 218, h_side = 196, t_right = 191;
	const unsigned char edge_r = 167;
	const unsigned char               in = '-', v_side = 179;
	const unsigned char b_left = 192, b_right = 217;

	using namespace std;
	for (size_t i = i0; i <= im; ++i)
	{
		for (size_t j = j0; j <= jm; ++j)
		{
			switch (position(i, j))
			{
			case top_left:
				cout << t_left;
				break;
			case horizontal_side:
				cout << h_side;
				break;
			case top_right:
				cout << t_right;
				break;
			case vertical_side:
				cout << v_side;
				break;
			case bottom_right:
				cout << b_right;
				break;
			case bottom_left:
				cout << b_left;
				break;
			case edge_region:
				cout << edge_r;
				break;
			case inside:
				cout << in;
				break;
			}
		}
		cout << endl;
	}

}

R::where R::position(size_t i, size_t j)
{
	if (i == i0 && j == j0)
		return top_left;
	else if (i == i0 && j == jm-1)
		return top_right;
	else if (i == im-1 && j == jm-1)
		return bottom_right;
	else if (i == im-1 && j == j0)
		return bottom_left;
	else if (i == i0 || i == im-1)
		return horizontal_side;
	else if (j == j0 || j == jm-1)
		return vertical_side;
	else if (i == i0 + 1 || i == im - 2 || j == j0 + 1 || j == jm - 2)
		return inside;
	else
		return inside;
}



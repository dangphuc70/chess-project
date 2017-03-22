#include "Game.h"
#include <vector>
#include <iostream>

using namespace std;

Game::Game(size_t c_h, size_t c_w) : cell_height(c_h), cell_width(c_w)
{
}


Game::~Game()
{
}

bool Game::place(const Coordinate & destination, Piece * _Piece)
{
	bool coordinate_valid = board.valid_coordinate(destination);
	if (coordinate_valid) {
		board[destination].reset(_Piece); // this destroys piece already at destination
		                                // and puts piece there
	}
	return coordinate_valid;
}

bool Game::validate_move(const Coordinate & source, const Coordinate & destination)
{
	return board.validate_move(source, destination)
		&& board[source]->validate_move(source, destination);
}

bool Game::move(const Coordinate & s, const Coordinate & d)
{
	bool valid = validate_move(s, d);
	if (valid) {
		board[d] = std::move(board[s]);
	}
	return valid;
}



// helper class
// R ~ Rectangle
// (relevant to a rectangle, not a Rectangle object)
#include "R.h"


void Game::draw()
{
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
	const size_t b_width = Board::chess_board_size_second * cell_width + 2;
	const size_t b_height = Board::chess_board_size_first * cell_height + 2;
	
	
	R cell_regionist(cell_height, cell_width);
	R board_regionist(b_height, b_width);

	size_t b_h = 0;
	for (size_t b_w = 0; b_w < b_width; ++b_w) {
		cout << board_border[board_regionist.position(b_h, b_w)];
	} cout << endl;


	//summary of recursive structure that's about to happen
	//traverse: board row - -> unit line of board row - -> cells in row - -> unit line of cell
	// unit line is a console line (printed console line)
	//unit lines of cells are concatenable on one line (in the console)
	//everything is nearly concatenable vertically and therefore, vertical concatenability is trivial
	//a picture would better explain (unfortunately, not provided)

	size_t color = 0;
	// notes about (i,j) and (x,y) at end of scope
	for (size_t y = 0; y < Board::chess_board_size_first; ++y) { // traverse board -- up-down
		
		// render line-by-line
		for (size_t j = 0; j < cell_height; ++j) {

			// line start here
			cout << board_border[R::vertical_side];
			bool middle = (j == cell_height / 2); // if j is at about the
			                                     // middle of the cell (height-wise)

			
			for (size_t x = 0; x < Board::chess_board_size_second; ++x) { // traverse board -- left-right
																		  // determine cell color
																		  // x and y are both determined at
				                                                          // this stage
				color = (black_cell({ x,y })) ? (0) : (1);
				// 0 : black
				// 1 : white
				for (size_t i = 0; i < cell_width; ++i) {
					R::where p = cell_regionist.position(j, i);
					if (board[{x, y}] != nullptr // contact with piece
						&& p == R::vertical_side
						&& middle) {
						cout << border[color][R::vertical_side]
							<< (board[{x, y}]->Symbol())
							<< border[color][R::vertical_side];
						break; // this cell-line-unit done
					}
					else {
						cout << border[color][p];
					}
				}	
			}

			// j is a line (console line)
			cout << board_border[R::vertical_side] << endl;
			// line end here
			               // this line unit done (console line)
						  // line break
		}
	}
	
	b_h = b_height - 1;
	for (size_t b_w = 0; b_w < b_width; ++b_w) {
		cout << board_border[board_regionist.position(b_h, b_w)];
	} cout << endl;
	
	 // (i,j) maps printed cell (including borders)
	// each character is a (i,j)

	 // (x,y) maps the cells on the chess board
	// each cell is a (x,y)
}

bool Game::black_cell(const Coordinate & coor)
{
	return (coor.x + coor.y) % 2 != 0;
}




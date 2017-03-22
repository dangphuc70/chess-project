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



// helper
class R
{
public:
	R(size_t im, size_t jm, size_t i0 = 0, size_t j0 = 0);
	~R();

	// ~not used
public:
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
	const size_t black = 0;
	const size_t white = 1;
	const unsigned char border[2][7] = {
		{ 176, 176, 176, 176, 176, 176, 176 },
		//{201, 205, 187, 186, 188, 200, 32},
		{ 32, 32, 32, 32, 32, 32, 32 }
		//{ 218, 196, 191, 179, 217, 192, 32 }
		
	};
	R cell_regionist(cell_height, cell_width);

	const unsigned char board_border[6] = {
		218, 196, 191, 179, 217, 192
	}; // no need for interior, just borders

	const size_t b_width = Board::chess_board_size_second * cell_width + 2;
	const size_t b_height = Board::chess_board_size_first * cell_height + 2;
	R board_regionist(b_height, b_width);

	size_t b_h = 0;
	for (size_t b_w = 0; b_w < b_width; ++b_w) {
		cout << board_border[board_regionist.position(b_h, b_w)];
	} cout << endl;


	size_t color = 0;
	// notes about (i,j) and (x,y) at end of scope
	for (size_t y = 0; y < Board::chess_board_size_first; ++y) { // traverse board -- up-down
		
		// render line-by-line
		for (size_t j = 0; j < cell_height; ++j) {

			// line start here
			cout << board_border[R::vertical_side];
			bool middle = (j == cell_height / 2); // if j is at about middle of the cell (height - wise)

			
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
							<< (board[{x, y}]->Symbol())
							<< border[color][R::vertical_side];
						break; // this cell line unit done
					}
					else {
						cout << border[color][p];
					}
				}	
			}

			// j is a line
			cout << board_border[R::vertical_side] << endl;
			// line end here
			               // this line unit done
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



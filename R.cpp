#include "R.h"

#include <iostream>
using namespace std;

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
	else if (i == i0 && j == jm - 1)
		return top_right;
	else if (i == im - 1 && j == jm - 1)
		return bottom_right;
	else if (i == im - 1 && j == j0)
		return bottom_left;
	else if (i == i0 || i == im - 1)
		return horizontal_side;
	else if (j == j0 || j == jm - 1)
		return vertical_side;
	else if (i == i0 + 1 || i == im - 2 || j == j0 + 1 || j == jm - 2)
		return inside;
	else
		return inside;
}
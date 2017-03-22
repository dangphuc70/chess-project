#pragma once
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

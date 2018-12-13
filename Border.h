#pragma once
#include <vector>

/**
n-dimensional rectangular domain
*/

class Border
{
	int n; /**< dimension */
public:
	std::vector<double> left;
	std::vector<double> right;
	Border(int n_ = 0) : n(n_), left(n_), right(n_) {};
	friend void borderInput(Border &b);
	~Border() {};
};

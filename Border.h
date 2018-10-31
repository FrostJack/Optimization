#pragma once
#include <vector>

class Border
{
	int n;
public:
	std::vector<double> left;
	std::vector<double> right;
	Border(int n_ = 0) : n(n_), left(n_), right(n_) {};
	friend void borderInput(Border &b);
	~Border() {};
};

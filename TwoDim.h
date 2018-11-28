#pragma once
#include "Func.h"

//f(x, y) = 5x ^ 2 - 6xy + 5y ^ 2
//min f(x, y) = 0 at (0, 0)

class TwoDim :
	public Func
{
public:
	TwoDim() :Func(2) {};
	double f(const std::vector<double> &point) override;
	~TwoDim() {};
};


#pragma once
#include "Func.h"
/*
f(x, y) = 3*sin^2(x) + 4*cos^2(y)
min f(x, y) = 0 at (2 * pi * n1, 2 * pi * n2 + pi / 2) or (2 * pi * n1 + pi, 2 * pi * n2 + pi / 2) 
*/
class TwoDim2 :
	public Func
{
public:
	TwoDim2() :Func(2) {};
	double f(const std::vector<double> &point) override;
	~TwoDim2() {};
};


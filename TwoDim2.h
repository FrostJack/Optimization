#pragma once
#include "Func.h"
/*
Rosenbrock function
f(x, y) = (1 - x)^2 + 100(y - x^2)^2
min f(x, y) = 0 at (1, 1)
*/
class TwoDim2 :
	public Func
{
public:
	TwoDim2() :Func(2) {};
	double f(const std::vector<double> &point) override;
	~TwoDim2() {};
};


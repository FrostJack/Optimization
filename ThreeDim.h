#pragma once
#include "Func.h"
//f(x, y, z) = x ^ 2 + y ^ 2 + z ^ 2
//min f(x, y, z) = 0 at (0, 0, 0)
class ThreeDim :
	public Func
{
public:
	ThreeDim() :Func(3) {};
	double f(const std::vector<double> &point) override;
	~ThreeDim() {};
};


#pragma once
#include "Func.h"
class ThreeDim :
	public Func
{
public:
	ThreeDim() :Func(3) {};
	double f(const std::vector<double> &point) override;
	~ThreeDim() {};
};


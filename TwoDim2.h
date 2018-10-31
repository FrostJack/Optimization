#pragma once
#include "Func.h"
class TwoDim2 :
	public Func
{
public:
	TwoDim2() :Func(2) {};
	double f(const std::vector<double> &point) override;
	~TwoDim2() {};
};


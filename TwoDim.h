#pragma once
#include "Func.h"

class TwoDim :
	public Func
{
public:
	TwoDim() :Func(2) {};
	double f(const std::vector<double> &point) override;
	~TwoDim() {};
};


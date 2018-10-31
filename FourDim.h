#pragma once
#include "Func.h"
class FourDim :
	public Func
{
public:
	FourDim() :Func(4) {};
	double f(const std::vector<double> &point) override;
	~FourDim() {};
};


#pragma once

#include <vector>
#include <math.h>

class Func
{
protected:
	int n;
public:
	Func(int n_ = 0) :n(n_) {};
	int dim() { return n; }
	virtual double f(const std::vector<double> &point) = 0;
	virtual ~Func() {};
};


#pragma once

#include <vector>
#include <math.h>

/**
virtual parent class for objects immitating mathematical functions. 
*/

class Func
{
protected:
	int n; /**< function dimension */
public:
	Func(int n_ = 0) :n(n_) {};
	int dim() { return n; }
	virtual double f(const std::vector<double> &point) = 0; 
	virtual ~Func() {};
};


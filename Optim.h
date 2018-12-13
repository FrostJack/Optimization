#pragma once

#include "Func.h"
#include "Border.h"

const int max_steps = 1e6;

class Optim
{
protected:
	int steps; /**< the amount of steps algorithm made while minimizing a function */
	std::vector<double> ans; /**< minimum point */
	double f_ans; /**< minimum value */
public:
	Optim(): steps(0), ans(0), f_ans(0) {};
	virtual void calculate(Func *pfun, const Border &border, const std::vector<double> &point, const double &eps = 0, 
		const int &improve = max_steps) = 0;
	void output();
	virtual ~Optim() {};
};


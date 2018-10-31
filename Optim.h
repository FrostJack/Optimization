#pragma once

#include "Func.h"
#include "Border.h"

class Optim
{
protected:
	int steps;
	std::vector<double> ans;
	double f_ans;
public:
	Optim(): steps(0), ans(0), f_ans(0) {};
	virtual void calculate(Func *pfun, const Border &border, const std::vector<double> &point, const double &eps = 0, 
		const int &improve = 10000) = 0;
	void output();
	virtual ~Optim() {};
};


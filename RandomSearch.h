#pragma once
#include "Optim.h"

const double delta = 1e-2;

class RandomSearch :
	public Optim
{
	double prob;
public:
	RandomSearch(double p = 0.6) : Optim(), prob(p) {};
	void calculate(Func *pfun, const Border &border, const std::vector<double> &point, const double &eps = 0, const int &improve = 10000)
		override;
	~RandomSearch() {};
};


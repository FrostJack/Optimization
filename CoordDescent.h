#pragma once
#include "Optim.h"

const double alpha = 0.618;

class CoordDescent :
	public Optim
{
public:
	CoordDescent(): Optim() {};
	void calculate(Func *pfun, const Border &border, const std::vector<double> &point, const double &eps = 0, const int &improve = 10000) 
		override;
	~CoordDescent() {};
};

double GoldenRatio(double a, double b, Func *pfun, double eps, int index, std::vector<double> &var);

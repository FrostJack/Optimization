#pragma once

#include <vector>
const double alpha = 0.618;

typedef double(*fptr)(std::vector<double>);

double GoldenRatio(double a, double b, fptr f, double eps, int index, std::vector<double> var);


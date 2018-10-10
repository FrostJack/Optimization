#pragma once

#include <vector>
const double alpha = 0.618;

typedef double(*fptr)(std::vector<double>);

double GoldenRatio(double a, double b, fptr f, double eps, int index, std::vector<double> &var);

double Norm(const std::vector<double> &x, const std::vector<double> &y, int n);

int CoordinateDescent(fptr f, double eps, std::vector<double> &var, const std::vector<double> &border);

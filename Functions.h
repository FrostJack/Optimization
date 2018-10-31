#pragma once

#include <vector>
#include "Func.h"

const double alpha = 0.618;

double GoldenRatio(double a, double b, Func &fun, double eps, int index, std::vector<double> &var);

double Norm(const std::vector<double> &x, const std::vector<double> &y, int n);

int CoordinateDescent(Func &fun, double eps, std::vector<double> &var, const std::vector<double> &border);

int RandomSearch(Func &fun, double eps, std::vector<double> &var, const std::vector<double> &border);

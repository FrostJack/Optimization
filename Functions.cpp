#include "stdafx.h"
#include "Functions.h"
#include <iostream>

double GoldenRatio(double a, double b, fptr f, double eps, int index, std::vector<double> &var) {
	double len = b - a;
	double left = b - alpha * len;
	var[index] = left;
	double fleft = f(var);
	double right = a + alpha * len;
	var[index] = right;
	double fright = f(var);
	while ((len) > eps) {
		if (fleft > fright) {
			a = left;
			len = b - a;
			left = right;
			fleft = fright;
			right = a + alpha * len;
			var[index] = right;
			fright = f(var);
		}
		else {
			b = right;
			len = b - a;
			right = left;
			fright = fleft;
			left = b - alpha * len;
			var[index] = left;
			fleft = f(var);
		}
	}
	return (a + b) / 2;
}

double Norm(const std::vector<double> &x, const std::vector<double> &y, int n) {
	double res = 0;
	for (int j = 0; j < n; ++j) {
		res += pow(x[j] - y[j], 2);
	}
	return res;
}

int CoordinateDescent(fptr f, double eps, std::vector<double> &var, const std::vector<double> &border) {
	double len = 0;
	double eps2 = pow(eps, 2);
	int steps = 0;
	int n = border.size() / 2;
	std::vector<double> var2(var);
	while (steps < 10000) {
		for (int j = 0; j < n; ++j) {
			var[j] = GoldenRatio(border[2 * j], border[2 * j + 1], f, eps, j, var);
		}
		if (Norm(var, var2, n) < eps2) {
			return 1;
		}
		var2 = var;
	}
	return 0;
}
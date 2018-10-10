#include "stdafx.h"
#include "Functions.h"

double GoldenRatio(double a, double b, fptr f, double eps, int index, std::vector<double> var) {
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
			right = a + alpha * len;
			fleft = fright;
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
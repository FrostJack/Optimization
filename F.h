#pragma once
#include <vector>

double f1(const std::vector<double> &point) {
	double x = point[0];
	double y = point[1];
	return 5 * pow(x, 2) - 6*x*y + 5 * pow(y, 2);
}


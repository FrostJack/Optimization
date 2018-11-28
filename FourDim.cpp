#include "stdafx.h"
#include "FourDim.h"
#include "Exception.h"

double FourDim::f(const std::vector<double> &point) {
	if (point.size() != n)
		throw Exception("Point with wrong dimension received in function");
	return exp(pow(point[0], 2) + pow(point[1], 2)) + exp(sin(point[2]/4) + cos(point[3]/4));
}

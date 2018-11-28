#include "stdafx.h"
#include "ThreeDim.h"
#include "Exception.h"

double ThreeDim::f(const std::vector<double> &point) {
	if (point.size() != n)
		throw Exception("Point with wrong dimension received in function");
	double x = point[0];
	double y = point[1];
	double z = point[2];
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

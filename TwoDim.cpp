#include "stdafx.h"
#include "TwoDim.h"
#include "Exception.h"

double TwoDim::f(const std::vector<double> &point) {
	if (point.size() != n)
		throw Exception("Point with wrong dimension received in ThreeDim function");
	double x = point[0];
	double y = point[1];
	return 5 * pow(x, 2) - 6 * x*y + 5 * pow(y, 2);
}
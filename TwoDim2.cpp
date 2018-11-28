#include "stdafx.h"
#include "TwoDim2.h"
#include "Exception.h"

double TwoDim2::f(const std::vector<double> &point) {
	if (point.size() != n)
		throw Exception("Point with wrong dimension received in ThreeDim function");
	double x = point[0];
	double y = point[1];
	return 3 * pow(sin(x), 2) + 4 * pow(cos(y), 2);
}
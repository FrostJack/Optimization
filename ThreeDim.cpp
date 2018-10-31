#include "stdafx.h"
#include "ThreeDim.h"


double ThreeDim::f(const std::vector<double> &point) {
	if (point.size() != n)
		throw "Wrong point's dimension";
	double x = point[0];
	double y = point[1];
	double z = point[2];
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

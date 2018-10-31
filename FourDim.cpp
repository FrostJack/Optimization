#include "stdafx.h"
#include "FourDim.h"

double FourDim::f(const std::vector<double> &point) {
	if (point.size() != n)
		throw "Wrong point's dimension";
	return pow(point[0], 2) + pow(point[1], 2) + pow(point[2], 2) + pow(point[3], 2);
}

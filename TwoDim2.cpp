#include "stdafx.h"
#include "TwoDim2.h"


double TwoDim2::f(const std::vector<double> &point) {
	if (point.size() != n)
		throw "Wrong point's dimension";
	double x = point[0];
	double y = point[1];
	return 3 * pow(sin(x), 2) + 4 * pow(cos(y), 2);
}
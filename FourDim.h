#pragma once
#include "Func.h"
/*f(x) = exp((x_1)^2 + (x_2)^2) + exp(sin(x_3 / 4) + cos(x_4 / 4))
min f(x) = 1 + 1/e^2 at (x1, x2, x3, x4) = (0, 0, 8 * pi * n1 - 2 * pi, 8 * pi * n2 + 4 * pi) for integer n1, n2 */
class FourDim :
	public Func
{
public:
	FourDim() :Func(4) {};
	double f(const std::vector<double> &point) override;
	~FourDim() {};
};


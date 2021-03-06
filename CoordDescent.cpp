#include "stdafx.h"
#include "CoordDescent.h"


void CoordDescent::calculate(Func *pfun, const Border &border, const std::vector<double> &point, const double &eps, 
	const int &improve) {
	steps = 0;
	int improve_steps = 0;
	int n = pfun->dim();
	std::vector<double> var(point);
	ans = point;
	f_ans = pfun->f(ans);
	double f_var;
	while (steps < max_steps) {
		++steps;
		for (int j = 0; j < n; ++j) {
			var[j] = GoldenRatio(border.left[j], border.right[j], pfun, eps, j, var);
		}
		f_var = pfun->f(var);
		if (f_var < f_ans) {
			ans = var;
			if ((f_ans - f_var) < eps) {
				f_ans = f_var;
				return;
			}
			f_ans = f_var;
			improve_steps = 0;
		}
		else {
			++improve_steps;
			if (improve_steps > improve)
				return;
		}
	}
	return;
}

double GoldenRatio(double a, double b, Func *pfun, double eps, int index, std::vector<double> &var) {
	double len = b - a;
	double left = b - alpha * len;
	var[index] = left;
	double fleft = pfun->f(var);
	double right = a + alpha * len;
	var[index] = right;
	double fright = pfun->f(var);
	while ((len) > eps) {
		if (fleft > fright) {
			a = left;
			len = b - a;
			left = right;
			fleft = fright;
			right = a + alpha * len;
			var[index] = right;
			fright = pfun->f(var);
		}
		else {
			b = right;
			len = b - a;
			right = left;
			fright = fleft;
			left = b - alpha * len;
			var[index] = left;
			fleft = pfun->f(var);
		}
	}
	return (a + b) / 2;
}
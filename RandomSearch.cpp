#include "stdafx.h"
#include "RandomSearch.h"
#include <random>

void RandomSearch::calculate(Func *pfun, const Border &border, const std::vector<double> &point, const double &eps,
	const int &improve) {
	unsigned seed = 13;
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> stand(0.0, 1.0);
	steps = 0;
	int improve_steps = 0;
	int n = pfun->dim();
	double rand, left, right;
	ans = point;
	f_ans = pfun->f(ans);
	std::vector<double> y(point);
	double f_y;
	while (steps < 100000) {
		rand = stand(generator);
		if (rand > prob)
			for (int j = 0; j < n; ++j) {
				rand = border.left[j] + (border.right[j] - border.left[j])*stand(generator);
				y[j] = rand;
			}
		else {
			for (int j = 0; j < n; ++j) {
				if (border.left[j] > ans[j] - delta)
					left = border.left[j];
				else left = ans[j] - delta;
				if (border.right[j] < ans[j] + delta)
					right = border.right[j];
				else right = ans[j] - delta;
				rand = left + (right - left)*stand(generator);
				y[j] = rand;
			}
		}

		f_y = pfun->f(y);
		if (f_y < f_ans) {
			ans = y;
			if ((f_ans - f_y) < eps) {
				f_ans = f_y;
				return;
			}
			f_ans = f_y;
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

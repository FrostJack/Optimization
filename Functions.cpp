#include "stdafx.h"
#include "Functions.h"
#include <iostream>
#include <random>
#include <chrono>

double GoldenRatio(double a, double b, Func &fun, double eps, int index, std::vector<double> &var) {
	double len = b - a;
	double left = b - alpha * len;
	var[index] = left;
	double fleft = fun.f(var);
	double right = a + alpha * len;
	var[index] = right;
	double fright = fun.f(var);
	while ((len) > eps) {
		if (fleft > fright) {
			a = left;
			len = b - a;
			left = right;
			fleft = fright;
			right = a + alpha * len;
			var[index] = right;
			fright = fun.f(var);
		}
		else {
			b = right;
			len = b - a;
			right = left;
			fright = fleft;
			left = b - alpha * len;
			var[index] = left;
			fleft = fun.f(var);
		}
	}
	return (a + b) / 2;
}

double Norm(const std::vector<double> &x, const std::vector<double> &y, int n) {
	double res = 0;
	for (int j = 0; j < n; ++j) {
		res += pow(x[j] - y[j], 2);
	}
	return res;
}

int CoordinateDescent(Func &fun, double eps, std::vector<double> &var, const std::vector<double> &border) {
	double len = 0;
	double eps2 = pow(eps, 2);
	int steps = 0;
	int n = border.size() / 2;
	std::vector<double> var2(var);
	while (steps < 10000) {
		for (int j = 0; j < n; ++j) {
			var[j] = GoldenRatio(border[2 * j], border[2 * j + 1], fun, eps, j, var);
		}
		if (Norm(var, var2, n) < eps2) {
			return 1;
		}
		var2 = var;
	}
	return 0;
}

int RandomSearch(Func &fun, double eps, std::vector<double> &var, const std::vector<double> &border) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> stand(0.0, 1.0);
	int steps = 0;
	int small_steps = 0;
	int n = border.size() / 2;
	double rand;
	double fx = fun.f(var);
	std::vector<double> y(var);
	while (steps < 100000) {
		for (int j = 0; j < n; ++j) {
			rand = border[2 * j] + (border[2 * j + 1] - border[2 * j])*stand(generator);
			y[j] = rand;
		}
		if (fun.f(y) < fx) {
			var = y;
			if ((fx - fun.f(y)) < eps)
				return 0;
			fx = fun.f(y);
			small_steps = 0;
		}
		else ++small_steps;
		if (small_steps > 50000)
			return 1;
	}
	return 2;
}
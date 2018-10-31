// Optimization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Functions.h"
#include "TwoDim.h"
#include "Border.h"
#include "TwoDim2.h"
#include "ThreeDim.h"
#include "FourDim.h"
#include "RandomSearch.h"
#include "Optim.h"
#include "CoordDescent.h"

int main()
{
	double eps = 0;
	double prob = 0.6;
	int improve = 10000;
	Func * pfun = NULL;
	Optim * popt = NULL;
	int n;
	int f = 0;

	std::cout << "Please, choose one of the example functions:" << std::endl;
	std::cout << "1. 5x^2 - 6xy + 5y^2" << std::endl;
	std::cout << "2. 3*sin^2(x) + 4*cos^2(y)" << std::endl;
	std::cout << "3. x^2 + y^2 + z^2" << std::endl;
	std::cout << "4. (x_1)^2 + (x_2)^2 + (x_3)^2 + (x_4)^2" << std::endl;
	int choice = 0;
	delete pfun;
	while (!f) {
		f = 1;
		std::cin >> choice;
		switch (choice) {
		case 1: pfun = new TwoDim();
			break;
		case 2: pfun = new TwoDim2();
			break;
		case 3: pfun = new ThreeDim();
			break;
		case 4: pfun = new FourDim();
			break;
		default:
			std::cout << "Wrong choice. Try again." << std::endl;
			f = 0;
			break;
		}
	}
	n = pfun->dim();
	Border b(n);
	borderInput(b);

	std::cout << "Please, choose stopping criteria:" << std::endl;
	std::cout << "1. Difference in function values" << std::endl;
	std::cout << "2. Iteration steps from last imrpovement" << std::endl;
	std::cout << "3. Both" << std::endl;
	f = 0;
	while (!f) {
		f = 1;
		std::cin >> choice;
		switch (choice) {
		case 1: std::cout << "Please input error value: " << std::endl;
			std::cin >> eps;
			break;
		case 3: std::cout << "Please input error value: " << std::endl;
			std::cin >> eps;
		case 2: std::cout << "Please input max steps value from last improvement: " << std::endl;
			std::cin >> improve;
			break;
		default: std::cout << "Wrong choice. Try again." << std::endl;
			f = 0;
			break;
		}
	}

	std::cout << "Please, choose optimization method:" << std::endl;
	std::cout << "1. Coordinate Descent" << std::endl;
	std::cout << "2. Random Search." << std::endl;
	f = 0;
	delete popt;
	while (!f) {
		f = 1;
		std::cin >> choice;
		switch (choice) {
		case 1: popt = new CoordDescent();
			break;
		case 2: std::cout << "Please input probability for local search: " << std::endl;
			std::cin >> prob;
			popt = new RandomSearch(prob);
			break;
		default: std::cout << "Wrong choice. Try again." << std::endl;
			f = 0;
			break;
		}
	}

	std::cout << "Please, input starting point" << std::endl;
	std::vector<double> point(n);
	for (int i = 0; i < n; ++i) {
		std::cout << "Input " << i + 1 << " coordinate" << std::endl;
		std::cin >> point[i];
	}

	popt->calculate(pfun, b, point, eps, improve);
	popt->output();
    return 0;
}


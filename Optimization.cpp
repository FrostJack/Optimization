// Optimization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
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
#include "Exception.h"
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
	std::cout << "2. Rosenbrock function (1 - x)^2 + 100(y - x^2)^2" << std::endl;
	std::cout << "3. x^2 + y^2 + z^2" << std::endl;
	std::cout << "4. exp((x_1)^2 + (x_2)^2) + exp(sin(x_3 / 4) + cos(x_4 / 4))" << std::endl;
	int choice = 0;
	delete pfun;
	while (!((choice > 0) && (choice < 5))) {
		std::cout << "You need to choose an integer number from 1 to 4\n";
		while (!(std::cin >> choice)) {
			std::cin.clear();
			std::string line;
			std::getline(std::cin, line);
			std::cout << line << " - is not a number\n";
		}
	}
	switch (choice) {
	case 1: pfun = new TwoDim();
		break;
	case 2: pfun = new TwoDim2();
		break;
	case 3: pfun = new ThreeDim();
		break;
	case 4: pfun = new FourDim();
		break;
	}

	n = pfun->dim();
	Border b(n);
	borderInput(b);

	std::cout << "Please, choose stopping criteria:" << std::endl;
	std::cout << "1. Difference in function values" << std::endl;
	std::cout << "2. Number of iteration steps from last imrpovement" << std::endl;
	std::cout << "3. Both" << std::endl;

	choice = 0;
	while (!((choice > 0) && (choice < 4))) {
		std::cout << "You need to choose an integer number from 1 to 3\n";
		while (!(std::cin >> choice)) {
			std::cin.clear();
			std::string line;
			std::getline(std::cin, line);
			std::cout << line << " - is not a number\n";
		}
	}

	switch (choice) {
	case 1: std::cout << "Please input error value: " << std::endl;
		while (eps <= 0) {
			while (!(std::cin >> eps)) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << line << " - is not a number\n";
			}
			if (eps <= 0)
				std::cout << "You need to input positive number. Try again.\n";
		}
		break;
	case 3: std::cout << "Please input error value: " << std::endl;
		while (eps <= 0) {
			while (!(std::cin >> eps)) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << line << " - is not a number\n";
			}
			if (eps <= 0)
				std::cout << "You need to input positive number. Try again.\n";
		}
	case 2: std::cout << "Please input max iterations number from last improvement: " << std::endl;
		improve = 0;
		while (improve <= 0) {
			while (!(std::cin >> improve)) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << line << " - is not a number\n";
			}
			if (improve <= 0)
				std::cout << "You need to input positive integer. Try again.\n";
		}
		break;
	}

	std::cout << "Please, choose optimization method:" << std::endl;
	std::cout << "1. Coordinate Descent" << std::endl;
	std::cout << "2. Random Search." << std::endl;
	delete popt;

	choice = 0;
	while (!((choice > 0) && (choice < 3))) {
		std::cout << "You need to choose an integer number from 1 to 2\n";
		while (!(std::cin >> choice)) {
			std::cin.clear();
			std::string line;
			std::getline(std::cin, line);
			std::cout << line << " - is not a number\n";
		}
	}
	switch (choice) {
	case 1: popt = new CoordDescent();
		break;
	case 2: std::cout << "Please input probability for local search: " << std::endl;
		prob = 0;
		while ((prob <= 0) || (prob >= 1)) {
			while (!(std::cin >> prob)) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << line << " - is not a number\n";
			}
			if ((prob <= 0) || (prob >= 1))
				std::cout << "You need to input number between 0 and 1. Try again.\n";
		}
		popt = new RandomSearch(prob);
		break;
	}

	std::cout << "Please, input starting point" << std::endl;
	std::vector<double> point(n);
	for (int i = 0; i < n; ++i) {
		std::cout << "Input " << i + 1 << " coordinate" << std::endl;
		point[i] = b.left[i] - 1;
		while ((point[i] < b.left[i]) || (point[i] > b.right[i])){
			while (!(std::cin >> point[i])) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << line << " - is not a number\n";
			}
			if ((point[i] < b.left[i]) || (point[i] > b.right[i]))
				std::cout << "Sorry, but your input is incorrect. Point should be inside domain borders. Try again.\n";
		}
	}
	try {
		popt->calculate(pfun, b, point, eps, improve);
	}
	catch (Exception& e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
	popt->output();
	return 0;
}


// Optimization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "F.h"
#include "Functions.h"

int main()
{
	double eps;
	int minfound;
	int error;
	std::vector<double> point(2);
	std::vector<double> border(4);
	std::cout << "Please, input epsilon" << std::endl;
	std::cin >> eps;
	std::cout << "Please, input starting point" << std::endl << "First coordinate: ";
	std::cin >> point[0];
	std::cout << "Second coordinate: ";
	std::cin >> point[1];
	std::cout << std::endl << "Please, set the rectangular domain" << std::endl;
	std::cout << "First coordinate range: ";
	std::cin >> border[0];
	std::cin >> border[1];
	std::cout << std::endl << "Second coordinate range: ";
	std::cin >> border[2];
	std::cin >> border[3];
	std::vector<double> res(point);

	minfound = CoordinateDescent(f1, eps, res, border);
	if (minfound)
		std::cout << "(" << res[0] << "," << res[1] << ")" << std::endl;
	
	res = point;
	error = RandomSearch(f1, eps, res, border);
	std::cout << "(" << res[0] << "," << res[1] << ")" << std::endl;
	if (error)
		std::cout << "Couldnt reach given accuracy = " << eps << std::endl;
    return 0;
}


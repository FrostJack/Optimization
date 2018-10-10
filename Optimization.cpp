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
	minfound = CoordinateDescent(f1, eps, point, border);
	if (minfound)
		std::cout << point[0] << " " << point[1] << std::endl;
    return 0;
}


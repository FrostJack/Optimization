// Optimization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Functions.h"
#include "TwoDim.h"

int main()
{
	double eps;
	int minfound;
	int error;
	int n;
	std::vector<double> point(2);
	std::vector<double> border(4);
	std::cout << "Please, input epsilon" << std::endl;
	std::cin >> eps;
	std::cout << "Please, input starting point" << std::endl << "First coordinate: ";
	std::cin >> point[0];
	std::cout << "Second coordinate: ";
	std::cin >> point[1];
	std::vector<double> res(point);
    return 0;
}


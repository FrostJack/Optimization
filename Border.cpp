#include "stdafx.h"
#include "Border.h"
#include <iostream>
#include <string>

void borderInput(Border &b) {
	std::cout << "Please, set the rectangular domain" << std::endl;
	for (int i = 0; i < b.n; ++i) {
		std::cout << "Input two coordinates for " << i + 1 << " coordinate range" << std::endl;
		std::cout << "Input left border\n";
		while (!(std::cin >> b.left[i])){
			std::cin.clear();
			std::string line;
			std::getline(std::cin, line);
			std::cout << line << " - is not a number\n";
		}
		std::cout << "Input right border\n";
		b.right[i] = b.left[i] - 1;
		while (b.right[i] < b.left[i]) {
			while (!(std::cin >> b.right[i])) {
				std::cin.clear();
				std::string line;
				std::getline(std::cin, line);
				std::cout << line << " - is not a number\n";
			}
			if (b.right[i] < b.left[i])
				std::cout << "Sorry, but your input is incorrect. Right side of a border should not be less than left side. Try again.\n";
		}
	}
}

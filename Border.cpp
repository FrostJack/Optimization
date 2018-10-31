#include "stdafx.h"
#include "Border.h"
#include <iostream>

void borderInput(Border &b) {
	std::cout << "Please, set the rectangular domain" << std::endl;
	for (int i = 0; i < b.n; ++i) {
		std::cout << "Input two coordinates for " << i + 1 << " coordinate range" << std::endl;
		std::cin >> b.left[i];
		std::cin >> b.right[i];
	}
}

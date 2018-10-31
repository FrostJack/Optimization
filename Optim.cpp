#include "stdafx.h"
#include "Optim.h"
#include <iostream>
#include <iomanip>

void Optim::output() {
	std::cout << "Optimization was completed within " << steps << " steps." << std::endl;
	std::cout << "Result point: x(" << std::fixed << std::setprecision(5);
	for (int i = 0; i < ans.size() - 1; ++i)
		std::cout << ans[i] << ", ";
	std::cout << ans[ans.size() - 1] << ")" << std::endl;
	std::cout << "Function value f(x) = " << f_ans  << std::endl;
}

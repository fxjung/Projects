#include "timer.hpp"
#include <iostream>
#include <ctime>

timer::timer(int number) {
	name = number;
	start = clock();
	std::clog << "Starting timer " << name << "..." << std::endl;
}

timer::~timer() {
	int passed_time = clock() - start;
	std::clog << "Timer " << name << " was destroyed after " << (float)1000*passed_time/CLOCKS_PER_SEC << "ms." << std::endl;
}
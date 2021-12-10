#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include "App.h"



int main() {

	std::string path = "numbers.txt";

	App a {2, {1, 0, 1}, {1, 0, 0}, 2, 0.01, 100};


	a.euler_solver();
	// a.pr_print();
	a.print_to_file(path);
	a.get_plot_image();


}
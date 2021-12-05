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

	App a {2, {1, 0, 1}, {1, 0, 0}, 0, 0.01, 20};


	a.analytical_solver(0.01);
	// a.pr_print();
	a.print_to_file(path);


}
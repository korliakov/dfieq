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

	App a {3, {1, 0.01, 10, 10}, {1, 0, 0}, 0.01, 500};


	a.rk4_solver();
	a.pr_print();
	a.print_to_file(path);


}
#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
/*
Header file. Here you can announce your class and methods;
*/


// template <typename T> //float, double etc. 
class App {

private:

	int eq_ord; //порядок уравнения
	std::vector<double> coefs; 

	std::vector<std::vector<double>> var; //vector var contains t, x, x', x'' ...
	std::vector<double> initial_cond; //initial conditions, t=0, x(0), x'(0) ...
	
	double delta; //iteration step for time
	double time; //time-coordinate of last point

public:


	void euler_solver();
	void heun_solver();
	void rk4_solver();

	void analytical_solver();

	void print_to_file(std::string path);

	void resize_all();





};


#endif
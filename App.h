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

	int eq_ord; //equation order, number of highest derivative
	std::vector<double> coefs; //coefs for all parts of equation

	std::vector<std::vector<double>> var; //vector var contains x, x', x'' ..., x^(eq_ord), t
	std::vector<double> initial_cond; //initial conditions, x(0), x'(0) ...,
	int initial_cond_skip; //number of derivative which depends on others

	double delta; //iteration step for time
	double time; //time-coordinate of last point
	int N; //number of points

public:

	App(int eq_ord, std::vector<double> coefs , std::vector<double> initial_cond, double delta, double time); //fully defined at App.cpp; x(0), x'(0) ..., t=0, x(eq_ord) depends on others

	App(int eq_ord, std::vector<double> coefs , std::vector<double> initial_cond, int initial_cond_skip, double delta, double time); //x(0), x'(0) ..., t=0, x(initial_cond_skip) depends on others

	void euler_solver(); //done
	void heun_solver(); // done
	void rk4_solver(); //done
	void analytical_solver(double max_error); //done
	void print_to_file(std::string path); //done
	void get_plot_image();


	void fill_with_initial_cond(std::vector<double> &vec);
	void resize_all();


	//helping to debug functions
	void pr_print(); //fully defined at App.cpp; prints list of x coordinate







};


#endif
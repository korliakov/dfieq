#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include "App.h"

/*
.cpp file. Here you can define your methods
*/



App::App(int eq_ords, std::vector<double> coefss , std::vector<double> initial_conds, double deltas, double times) {
	this->eq_ord = eq_ords;
	this->coefs = coefss;
	this->initial_cond = initial_conds;
	this->delta = deltas;	
	this->time = times;
	this->N = int(time/delta);
	var.assign(eq_ords+2, std::vector<double> (this->N));
	std::cout << N;
}


void App::euler_solver() {

	std::vector<double> var_cur(eq_ord+2, 0); //current values of variables

	for (int i = 0; i < eq_ord; i++) {

		var_cur[i] = initial_cond[i]; // solved problem	
		var[i][0] = initial_cond[i];
				

	}


	var_cur[eq_ord] = 0;	
	var_cur[eq_ord+1] = 0;
	var[eq_ord][0] = 0;
	var[eq_ord+1][0] = 0;



	for (int i = 1; i < N; i++) {

		double last_derivative = 0;

		for (int j = 0; j < eq_ord; j++) {

			var_cur[j] = var[j][i-1] + var[j+1][i-1]*delta;


			last_derivative -= var[j][i-1] * (coefs[j]/coefs[eq_ord]);
		}


		var_cur[eq_ord] = last_derivative;
		var_cur[eq_ord + 1] += delta;

		for (int k = 0; k <= eq_ord+1; k++) {

			var[k][i] = var_cur[k];
		}

		var_cur.resize(0); //deleting all values

	}
}

void App::pr_print() {

	for (int i = 0; i < N; i++) {

		std::cout << var[0][i] << "\n";
	}


}

//it has a problem, i ll fix it

// void App::print_to_file(std::string path) {

// 	std::ofstream out;

// 	if (out.is_open()) {

// 		for (int j = 0; j < N; j++)  {
// 			for (int i = 0; i < eq_ord+2; i++) {

// 				out << var[i][j] << ' ';

// 			}
// 			out << "\n";
// 		}
// 	}


// }
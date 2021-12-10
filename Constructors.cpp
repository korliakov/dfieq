#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include "App.h"





App::App(int eq_ords, std::vector<double> coefss , std::vector<double> initial_conds, double deltas, double times) {
	this->eq_ord = eq_ords;
	this->coefs = coefss;
	this->initial_cond = initial_conds;
	this->delta = deltas;	
	this->time = times;
	this->N = int(time/delta);
	this->initial_cond_skip = eq_ord;
	var.assign(eq_ords+2, std::vector<double> (this->N));


	double last_derivative = 0;
	for (int i = 0; i < eq_ord; i++) {

		var[i][0] = initial_cond[i];
		last_derivative -= initial_cond[i] * (coefs[i]/coefs[eq_ord]);	

	}

	var[eq_ord][0] = last_derivative;
	var[eq_ord+1][0] = 0;
}


App::App(int eq_ords, std::vector<double> coefss , std::vector<double> initial_conds, int initial_cond_skips, double deltas, double times) {
	this->eq_ord = eq_ords;
	this->coefs = coefss;
	this->initial_cond = initial_conds;
	this->initial_cond_skip = initial_cond_skips;
	this->delta = deltas;	
	this->time = times;
	this->N = int(time/delta);
	var.assign(eq_ords+2, std::vector<double> (this->N));





	double except_derivative = 0;
	double a = coefs[initial_cond_skip];
	for (int i = 0; i < eq_ord; i++) {
		if (i != initial_cond_skip) {
			var[i][0] = initial_cond[i];
			except_derivative -= initial_cond[i] * (coefs[i]/a);
		}
			

	}

	var[initial_cond_skip][0] = except_derivative;
	var[eq_ord+1][0] = 0;
}






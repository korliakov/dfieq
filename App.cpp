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
	var.assign(eq_ords+2, std::vector<double> (this->N));
	std::cout << N;
}







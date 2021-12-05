#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include "App.h"


void App::fill_with_initial_cond(std::vector<double> &vec) {

	double except_derivative = 0;
	double a = coefs[initial_cond_skip];
	


	try
	{

		if (a == 0) {

			throw "You have zero coef in your equation in place of derivative which depends on others, can't solve it";
		}
		
		for (int i = 0; i < eq_ord+1; i++) {
			if (i != initial_cond_skip) {
				var[i][0] = initial_cond[i];
				vec[i] = initial_cond[i];
				except_derivative -= initial_cond[i] * (coefs[i]/a);
			}
			

		}
		vec[initial_cond_skip] = except_derivative;
		var[initial_cond_skip][0] = except_derivative;
		vec[eq_ord+1] = 0;
		var[eq_ord+1][0] = 0;
		
	}
	catch (const char* exception) 
	{

		std::cerr << "Error: " << exception << "\n";
	}








	}


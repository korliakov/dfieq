#include "App.h"


void App::heun_solver() {

    std::vector<double> var_cur(eq_ord+2, 0); //current values of variables

    for (int i = 0; i < eq_ord; i++) {

        var_cur[i] = initial_cond[i];
        var[i][0] = initial_cond[i];
    }



    var_cur[eq_ord] = 0; // we must change it
    var_cur[eq_ord+1] = 0;
    var[eq_ord][0] = 0;
    var[eq_ord+1][0] = 0;



    for (int i = 1; i < N; i++) {

        double last_derivative = 0;

        // counting simple prediction

        for (int j = 0; j < eq_ord; j++) {

            var_cur[j] = var[j][i-1] + var[j+1][i-1]*delta;



            last_derivative -= var_cur[j] * (coefs[j]/coefs[eq_ord]);
        }

        var_cur[eq_ord] = last_derivative;

        // counting p-c method
        last_derivative = 0;
        for (int j = 0; j < eq_ord; j++) {

            var_cur[j] = var[j][i-1] + 0.5*delta*(var[j+1][i-1]+var_cur[j+1]);



            last_derivative -= var_cur[j] * (coefs[j]/coefs[eq_ord]);
        }

        var_cur[eq_ord] = last_derivative;


        var_cur[eq_ord + 1] += delta;



        for (int k = 0; k <= eq_ord+1; k++) {

            var[k][i] = var_cur[k];
        }

        var_cur.resize(0); //deleting all values

    }
}


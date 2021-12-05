#include "App.h"
#include "Matrix.h"


void App::analytical_solver(double max_error) {

    std::vector<double> initial(eq_ord+2, 0); //current values of variables

    fill_with_initial_cond(initial);

    Matrix A = Matrix(eq_ord);
    for (int i = 1; i<eq_ord;i++){
        A.change(i-1,i,1.0);
    }
    for (int i = 0; i<eq_ord;i++){
        A.change(eq_ord-1,i,(-1.0)*(coefs[i]/coefs[eq_ord]));
    }
    //A.show();

    Matrix Exp = Matrix(eq_ord);

    Exp = A.exp(0, max_error);
    //Exp.show();

    for (int i = 0; i < N; i++) {
        std::vector<double> b;
        Exp = A.exp(i*delta, max_error);
        //Exp.show();
        b = Exp*initial;
        for (int j = 0; j < eq_ord; j++){
            var[j][i] = b[j];
        }
        var[eq_ord+1][i] = i*delta;
        double last_derivative = 0;
        for (int j = 0; j < eq_ord; j++){
            last_derivative -= var[j][i] * (coefs[j]/coefs[eq_ord]);
        }
        var[eq_ord][i] = last_derivative;

    }


}

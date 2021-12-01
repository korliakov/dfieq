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


template <typename T> //float, double etc. 
class App {

private:

int N; //порядок уравнения
std::vector<double> coefs; 

std::vector<std::vector<T>> var; //vector var contains t, x, x', x'' ...
std::vector<T> initial_cond; //initial conditions, t=0, x(0), x'(0) ...


public:






};


#endif
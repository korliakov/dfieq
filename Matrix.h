#ifndef DEFEQ1_MATRIX_H
#define DEFEQ1_MATRIX_H


#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>

class Matrix{
public:

    std::vector<std::vector<double>> matr;

    int size;

    std::vector<double> operator[](int k);

    Matrix operator+(Matrix obj);

    Matrix operator*(Matrix obj);

    Matrix operator*(double obj);

    Matrix& operator=(Matrix obj);

    Matrix exp(double t, double num);

    void change(int i, int j, double k);

    std::vector<double> operator*(std::vector<double> a);

    double norm();

    void show();

    Matrix(int s);

    Matrix(int s, double k);

    void make_ones();
};


#endif //DEFEQ1_MATRIX_H

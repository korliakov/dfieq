//
// Created by oksan on 04.12.2021.
//

#include "Matrix.h"





std::vector<double> Matrix::operator[](int k){
    return matr[k];
}

Matrix Matrix::operator+(Matrix obj){
    Matrix tmp(size,0.0);
    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            tmp.matr[i][j]=this->matr[i][j]+obj.matr[i][j];
    return tmp;
}


Matrix Matrix::operator*(Matrix obj){
    Matrix tmp(size,0);
    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            for(int k=0; k < size; k++)
                tmp.matr[i][j]+=this->matr[i][k]*obj.matr[k][j];
    return tmp;
}

Matrix Matrix::operator*(double obj){
    Matrix tmp(size);
    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            tmp.matr[i][j]=(this->matr[i][j])*obj;
    return tmp;
}

Matrix& Matrix::operator=(Matrix obj){
    Matrix tmp(obj.size);
    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            matr[i][j]=obj.matr[i][j];
    return *this;
}

void Matrix::show(){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            std::cout << matr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix::Matrix(int s, double k){
    size = s;
    matr.assign(size, std::vector<double> (size));
    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            matr[i][j]=k;
}

Matrix::Matrix(int s){
    size = s;
    matr.assign(size, std::vector<double> (size));
    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            matr[i][j]=0.0;
}

void Matrix::make_ones(){
    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            if (i==j){
                matr[i][j]=1.0;
            }
            else{
                matr[i][j]=0.0;
            }

}

Matrix Matrix::exp(double t, double min) {
    Matrix tmp = Matrix(size);
    Matrix res = Matrix(size,0.0);
    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            tmp.matr[i][j]=(this->matr[i][j])*t;

    Matrix curr_add = Matrix(size);
    curr_add.make_ones();
    int i = 0;
    while (curr_add.norm()>min*min){
        res = res + curr_add;
        curr_add = curr_add*tmp;
        curr_add = curr_add*(1.0/double(i+1));
        i++;
    }

    return res;

}

double Matrix::norm() {
    double max = 0.0;
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            if (matr[i][j]*matr[i][j] > max){
                max = matr[i][j]*matr[i][j];
            }
        }

    }
    return max;
}

void Matrix::change(int i, int j, double k) {
    this->matr[i][j] = k;
}

std::vector<double> Matrix::operator*(std::vector<double> a){
    std::vector<double> b;
    for (int i = 0; i<size;i++){
        double curr = 0.0;

        for (int j = 0; j<size; j++){
            curr+=matr[i][j]*a[j];
        }

        b.push_back(curr);
    }
    return b;
}
//
// Created by kpiek on 5/11/2020.
//

#ifndef MONITORING_SYSTEM_KPIEKORZ_FFT_H
#define MONITORING_SYSTEM_KPIEKORZ_FFT_H


#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

#define FALSE 0
#define TRUE 1

/* global constants */
#define pi 3.14159265358979323846
const complex<double> i(0,1);

void printlist(complex<double>* l, int N, bool extras);
void split(complex<double> *inputs, int N);
void fast_fourier(complex<double>* x, double N);
double magnitude(complex<double> p, int N);


#endif //MONITORING_SYSTEM_KPIEKORZ_FFT_H

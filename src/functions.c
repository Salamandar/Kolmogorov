#include "functions.h"

// Renvoie la valeur d'un lambda
float compute_lambda(int i) {
    if(i == 1) return 1.0;

    float lambda = 0;
    for(int r = 0; r < PREC_LAMBDA; ++r) {
        lambda += 1.0 / pow(BASE_DK, (i - 1.0)*(pow(DIMENSION, r))/(DIMENSION - 1.0));
    }
    return lambda;
}

float compute_ck(int k, int n) {
    float first = 0;
    for(int r = 0; r < PREC_LAMBDA; ++r)
        first += 1.0 / pow(BASE_DK, (pow(DIMENSION, r) - 1.0)/(DIMENSION - 1.0));

    float second = 0;
    for (int p = 1; p <= n; ++p)
        second += compute_lambda(p);
    return first*second;
}


float sigma(float x) {
    if (x<=0)
        return 0;
    else if (x>=1)
        return 1;
    else
        return x;
}

struct dk* sigmadk(struct dk* x) {
    return x;
}

struct dk* eta(struct dk* x) {
    return new_dk(0.5);
}

struct dk* theta(int d, int n, int k, int y) {
    float pomGamma = (pow(DIMENSION, k+1)-1)/(d-1);
    float valeurEta = 0;
}


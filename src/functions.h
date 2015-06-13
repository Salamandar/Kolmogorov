#include <math.h>
#include "main.h"
#include "dk.h"

float compute_lambda(int i);
float compute_ck(int k, int n);

float sigma(float x);
struct dk* sigmadk(struct dk*);

struct dk* eta(struct dk* x);
struct dk* theta(int d, int n, int k, int y);

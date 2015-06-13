#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "functions.h"


/**
 * Fonction Psi
 * Renvoie psi(x) avec x représenté sous sa forme
 * structurelle dk. Calcul en dimension d
 */
float psi(struct dk* nb, int k, int d) {
	int ik = nb->valeurs[k-1];
	if(k == 1) return val_dk(nb);
	else if(ik < BASE_DK-1) {
		add_dk(nb, -ik, k-1);
		return psi(nb, k-1, d) + ik/pow(BASE_DK, (pow(d, k)-1)/(d-1));
	}
	else {
		struct dk* nb2 = copy_dk(nb);
		add_dk(nb , -1, k-1);
		add_dk(nb2,  1, k-1);
		float tmp = .5 * (psi(nb, k, d) + psi(nb2, k-1, d));
		free_dk(nb2);
		return tmp;
	}
}

int main(int argc, char const *argv[]) {
	int d = 2;
	int m = 2*d;
	int gamma = 10;
	float b = 1.0/(gamma*(gamma-1));

	/*
	printf("Liste des lambdas :\n");
	for(int i = 1; i <= d; ++i) {
		printf("Lambda_%i = %f\n", i, compute_lambda(d, gamma, i));
	}
	*/

	for(float i = 0; i < 1; i += .001) {
		struct dk* val = new_dk(i);
		printf("%f\n", psi(val, PREC_DK, d));
		free_dk(val);
	}
	/*
	struct dk* test = new_dk(gamma, 10, 0.2986);
	print_dk(test);
	float tmp = val_dk(test);
	printf("psi(%8f) = %f\n", tmp, psi(test, test->prec, d));
	*/

	return 0;
}

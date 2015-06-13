#include "main.h"
/**
 * structure dk
 * représente un réel dans [0,1[ par un tableau 
 * de valeurs entières comprises entre 0 et la
 * base choisi avec une précision prec égale au
 * nombre de valeurs sauvegardées dans le tableau
 */
struct dk {
	int* valeurs;
};

/**
 * Nouveau dk
 * Renvoie la représentation du réel x sous
 * la forme d'une structure dk
 */
struct dk* new_dk(float x);

// Retourne une copie de dk
struct dk* copy_dk(struct dk*);

// Ajoute n/gamma^i à dk
void add_dk(struct dk*, int n, int i);

// Divise par une puissance de la base, donc décale dans le tableau (pow positive pour diviser)
void div_dk(struct dk*, int pow);

// Renvoie la valeur réel d'un dk
float val_dk(struct dk*);

// Affiche le dk
void print_dk(struct dk*);

// Libération mémoire
void free_dk(struct dk*);

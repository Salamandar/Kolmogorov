#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "dk.h"

// Des dk simplifiés, histoire de me dire que je sers à quelque chose :p

// nouveau dk
struct dk* new_dk(float x) {
    struct dk* tmp = malloc(sizeof(struct dk));
    tmp->valeurs = calloc(PREC_DK, sizeof(int));
    for(int i = 0; i < PREC_DK; ++i) {
        x *= BASE_DK;
        int flx = floor(x);
        tmp->valeurs[i] = flx;
        x -= flx;
    }
    return tmp;
}

// renvoie une copie de dk
struct dk* copy_dk(struct dk* s) {
    struct dk* tmp = malloc(sizeof(struct dk));
    tmp->valeurs = calloc(PREC_DK, sizeof(int));
    for(int i = 0; i < PREC_DK; ++i) {
        tmp->valeurs[i] = s->valeurs[i];
    }
    return tmp;
}

// ajoute n/gamma^i à dk avec n < gamma
void add_dk(struct dk* s, int n, int i) {
    if(i >= PREC_DK || i < 0) return;

    s->valeurs[i] += n;
    if(s->valeurs[i] < 0) {
        s->valeurs[i] = BASE_DK + s->valeurs[i];
        add_dk(s, -1, i-1);
    }
    else if(s->valeurs[i] >= BASE_DK) {
        s->valeurs[i] = s->valeurs[i] % BASE_DK;
        add_dk(s,  1, i-1);
    }
}

void div_dk(struct dk* s, int pow) {
    struct dk* tmp = malloc(sizeof(struct dk));
    tmp->valeurs = calloc(PREC_DK, sizeof(int));

}

// renvoie la valeur de dk en réel
float val_dk(struct dk* s) {
    float tmp = 0;
    float mult = BASE_DK;
    for(int i = 0; i < PREC_DK; ++i) {
        tmp += s->valeurs[i] / mult;
        mult *= BASE_DK;
    }
    return tmp;
}

// affiche le dk
void print_dk(struct dk* s) {
    printf("%9f (base %i, prec %i) : [", val_dk(s), BASE_DK, PREC_DK);
    for(int i = 0; i < PREC_DK; ++i) {
        printf("%i%s", s->valeurs[i], (i == PREC_DK-1 ? "]\n" : ", "));
    }
}

// libération mémoire
void free_dk(struct dk* s) {
    free(s->valeurs);
    free(s);
}




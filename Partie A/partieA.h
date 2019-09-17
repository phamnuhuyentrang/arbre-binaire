#ifndef PARTIEA_H
#define PARTIEA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct sommet sommet;

struct sommet{
    int cle;
    sommet* pere;
    sommet* gauche;
    sommet* droite;
};

typedef sommet* abre;

sommet* creerSommet(int val);
void insererSommet(abre som, int val);
void afficher(abre som);
int rechercheSommet(abre abr, int cle);
int tailleArbre(abre abr);
void deleteArb(sommet* s);

#endif //PARTIEA_H
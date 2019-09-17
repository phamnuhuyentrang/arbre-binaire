#ifndef PARTIEB_H
#define PARTIEB_H


#include <stdio.h>
#include <stdlib.h>

typedef struct SommetCompact sommet;

struct SommetCompact{
    int inf;
    int sup;
    sommet* pere;
    sommet* gauche;
    sommet* droite;
};

typedef sommet* ArbreCompact;

sommet* creerSommetCompact(int inf, int sup);
int min (int a, int b);
int max (int a, int b);
void insererElement(ArbreCompact som, int val);
void afficherArbreCompact(ArbreCompact som);
int rechercheElement(ArbreCompact abr, int val);
int tailleArbreCompact(ArbreCompact abr);
void deleteAbrCompact(ArbreCompact abr);

#endif //PARTIEB_H

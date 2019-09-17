#include "partieB.h"

sommet* creerSommetCompact(int inf, int sup){
	sommet* new = malloc(sizeof(sommet));
	if (new == NULL) return NULL;
	new->inf = inf;
	new->sup = sup;
	new->pere = NULL;
	new->gauche = NULL;
	new->droite = NULL;
	return new;
}

int min (int a, int b){
	if (a<b) return a;
	else return b;
}

int max (int a, int b){
	if (a>b) return a;
	else return b;
}

void insererElement(ArbreCompact som, int val){
	sommet* cree = creerSommetCompact(val, val);
    ArbreCompact it;
    ArbreCompact i;
    it = som;
    i = som;
    while (it!=NULL){
        i = it;
        if (i->sup + 1 < cree->inf){
            it=it->droite;
        }
        else if (cree->sup + 1 < i->inf){
            it=it->gauche;
        }
        else if (i->sup == cree->sup && i->inf == cree->inf) return;
        else {
        	i->inf = min(cree->inf,i->inf);
        	i->sup = max(cree->sup,i->sup);
            return;
        }
    }
    cree->pere = i;
    if(i==NULL){
        it=cree;
    }
    else {
        if(i->sup + 1 < cree->inf){
            i->droite=cree;
        }
        if (cree->sup + 1 < i->inf){
            i->gauche=cree;
        }
    }
}

void afficherArbreCompact(ArbreCompact som){
    if (som == NULL) return;
    else {
        afficherArbreCompact(som->gauche);
        printf("[%d,%d]\n", som->inf, som->sup);
        afficherArbreCompact(som->droite);
    }
}

int rechercheElement(ArbreCompact abr, int val){
    ArbreCompact aux;
    aux = abr;
    if (aux == NULL) return -1;
    while (aux != NULL) {
        if (aux-> sup + 1 <val){
            aux = aux->droite;
        }
        else if (val + 1 < aux->inf){
            aux = aux->gauche;
        }
        if (aux->sup >= val && aux->inf <=val) return 1;
        else return 0;
    }
    return 0;
}

int tailleArbreCompact(ArbreCompact abr) {
    if (abr == NULL) return 0;
    else return sizeof(sommet) + tailleArbreCompact(abr->gauche) + tailleArbreCompact(abr->droite);
}

void deleteAbrCompact(ArbreCompact abr){
    if (abr!=NULL)
    {
        deleteAbrCompact(abr->gauche);
        deleteAbrCompact(abr->droite);
        free(abr);
    }
}

#include "partieA.h"

sommet* creerSommet(int val){
    sommet* cree = malloc(sizeof(sommet));
    if (cree == NULL) return NULL;
    cree->cle = val;
    cree->pere = NULL;
    cree->gauche = NULL;
    cree->droite = NULL;
    return cree;
}

void insererSommet(abre som, int val){
    sommet* cree = malloc(sizeof(sommet));
    cree = creerSommet(val);
    abre it = malloc(sizeof(sommet));
    abre i = malloc(sizeof(sommet));
    it=som;
    i=som;
    while (it!=NULL){
        i = it;
        if (i->cle>val){
            it=it->gauche;
        }
        else if (i->cle<val){
            it=it->droite;
        }
        else return;
    }
    cree->pere = i;
    if(i==NULL){
        it=cree;
    }
    else {
        if(i->cle>val){
            i->gauche=cree;
        }
        else{
            i->droite=cree;
        }
    }
}

void afficher (abre som) {
    if (som == NULL) return;
    else {
        afficher(som->gauche);
        printf("%d\n",som->cle);
        afficher(som->droite);
    }
}

int rechercheSommet(abre abr, int cle) {
	abre aux = malloc(sizeof(sommet));
	aux = abr;
    if (aux == NULL) return -1;
	while (aux!=NULL){
		if (cle < aux->cle) {
			aux = aux->gauche;
		}
		else if (cle > aux->cle) {
			aux = aux->droite;
		}
        else return 1;
	}
	return 0;
}

int tailleArbre(abre abr){
    if (abr == NULL) return 0;
    else return sizeof(sommet) + tailleArbre(abr->gauche) + tailleArbre(abr->droite);
}

void deleteAbr(sommet *s){
    if (s!=NULL)
    {
        deleteAbr(s->gauche);
        deleteAbr(s->droite);
        free(s);
    }
}
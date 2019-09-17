#include "partieA.h"
int main()
{
   int choix;
   abre m;
   int val;
   for (;;) {
      printf("1. Creer un sommet.\n");
      printf("2. Inserer un sommet dans l'abre.\n");
      printf("3. Afficher l'abre.\n");
      printf("4. Rechecher un sommet dans l'abre. \n");
      printf("5. Calculer la taille de l'abre. \n");
      printf("6. Quitter. \n");
      printf("Votre choix: ");

      scanf("%d", &choix);
      printf("================================================================================\n");
      switch (choix){
            case 1:
                    printf("entrez la cle du sommet :");
                    scanf("%d",&val);
                    m=creerSommet(val);
                    break;
            case 2:
                    printf("entrez la cle du sommet :");
                    scanf("%d",&val);
                    insererSommet(m,val);
                    break;
            case 3:
            		afficher(m);
                    break;
            case 4:
                    printf("entrez la cle du sommet que vous cherchez :");
                    scanf("%d",&val);
                    if (rechercheSommet(m,val)==1){
                        printf("Le sommet existe dans l'abre \n");
                    } 
                    else {
                        printf("Le sommet n'existe pas \n");
                    }
                    break;
            case 5:
            		printf("La taille totale de l'abre: %d\n", tailleArbre(m));
                    break;
            case 6:
                    deleteArb(m);
                    exit(0);
break;
            default:
                    printf("\nMerci de resaissir le choix valide. \n");
	        break;
      }
   }

   return 0;
}

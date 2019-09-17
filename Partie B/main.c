#include "partieB.h"

int main()
{
   int choix;
   ArbreCompact m;
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
                    printf("entrez la valeur du sommet :");
                    scanf("%d",&val);
                    fflush(stdin);
                    m=creerSommetCompact(val,val);
                    break;
            case 2:
                    printf("entrez la valeur insere :");
                    scanf("%d",&val);
                    fflush(stdin);
                    insererElement(m,val);
                    break;
            case 3:
            		afficherArbreCompact(m);
                    break;
            case 4:
                    printf("entrez la cle du sommet que vous cherchez :");
                    scanf("%d",&val);
                    fflush(stdin);
                    if (rechercheElement(m,val)==1){
                        printf("Le sommet existe dans l'abre \n");
                    } else {printf("Le sommet n'existe pas \n");}
                    break;
            case 5:
            		printf("La taille totale de l'abre: %d\n", tailleArbreCompact(m));
                    break;
            case 6:
                    deleteAbrCompact(m);
                    exit(0);
break;
            default:
                    printf("\nMerci de resaissir le choix valide. \n");
	        break;
      }
   }

   return 0;
}


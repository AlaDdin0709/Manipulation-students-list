#include"project.h"
#include<stdlib.h>
#include<stdio.h>
#include <assert.h>
void main()
{
    struct liste* Liste;
	unsigned choix;
	int pos;
    char nom[20];

    printf("\n\n***********Projet Liste Unidirectionnelle***********\n\n");

    do
		{
            printf("*****************************************************\n");
            printf("1-initialiser la liste \n");
            printf("2-quitter\n");
            printf("*****************************************************\n\n");
			printf("Choix: \n");
			scanf("%u",&choix);
		}while(choix<=0 || choix>2);

		switch(choix)
		{
		        case 1 :
		            Liste=cree_liste();
                    break;
                case 2 :
                    exit(0);
        }
while(1)
{
if (Liste->dim==0)
{

		do
		{
            printf("*****************************************************\n");
            printf("1-Ajouter le premier element de la liste vide\n");
            printf("2-quitter\n");
            printf("*****************************************************\n\n");
			printf("Choix: \n");
			scanf("%u",&choix);
		}while(choix<=0 || choix>2);

		switch(choix)
		{
		        case 1 :
		            printf("saisir le nom a ajouter: \n\n");
                    scanf("%s",&nom);
                    inserer_vide(Liste,nom);
                    printf("le nom est cree\n\n");
                    break;
                case 2 :
                    exit(0);
        }
}
        else if(Liste->dim==1)
        {
           do
		{   printf("*****************************************************\n");
            printf("1-ajouter au debut \n");
            printf("2-ajouter a la fin\n");
            printf("3-afficher\n");
            printf("4-suppression de cette seul element\n");
            printf("5-quitter\n");
            printf("*****************************************************\n\n");
            printf("Choix: ");
			scanf("%u",&choix);
		}while(choix<=0 || choix>5);

		switch(choix)
		{
		        case 1 :
		            printf("saisir le nom à ajouter: \n");
			                scanf("%s",&nom);
                            inserer_debut(Liste,nom);
                            printf("l'ajout au debut a été effectué \n ");
                            break;

                case 2 :
                    printf("saisir le nom à ajouter: \n");
                            scanf("%s",&nom);
                            inserer_fin(Liste,nom);
                            printf("l'ajout a la fin a été effectué \n ");
                            break;
                case 3 :
                    afficher(Liste);
                     break;
                case 4 :
                     assert(!vide(Liste));
                            suppression_seul_element(Liste);
                            printf("la supression a été effectué,la liste est vide\n");
                            break;
                case 5 :
                    exit(0);
        }
        }

        else
        {
             do
		{
		    printf("*****************************************************\n");
            printf("1-ajouter au debut \n");
            printf("2-ajouter a la fin\n");
            printf("3-ajout dans une position\n");
            printf("4-afficher\n");
            printf("5-suppression la premiere element\n");
            printf("6-suppression la dernier element\n");
            printf("7-suppression une posision choisi\n");
            printf("8-suppression tout les element\n");
            printf("9-quitter\n");
            printf("*****************************************************\n\n");
            printf("Choix: ");
			scanf("%u",&choix);
		}while(choix<=0 || choix>9);

		switch(choix)
		{
		        case 1 :
		            printf("saisir le nom à ajouter: \n");
			                scanf("%s",&nom);
                            inserer_debut(Liste,nom);
                            printf("l'ajout au debut a été effectué \n ");
                            break;

                case 2 :
                    printf("saisir le nom à ajouter: \n");
                            scanf("%s",&nom);
                            inserer_fin(Liste,nom);
                            printf("l'ajout a la fin a été effectué \n ");
                            break;
                case 3 :
                     printf("saisir le nom à ajouter: \n");
                            scanf("%s",&nom);
                            do
                            {
                            printf("saisir la position que vous voulez: \n");
                            scanf("%d",&pos);
                            }while(pos<=1||pos>Liste->dim);

                     inserer_pos(Liste,nom,pos);
                     printf("l'ajout a la position a été effectué \n ");
                   break;
                case 4 :
                    afficher(Liste);
                     break;
                case 5 :
                     assert(!vide(Liste));
                            suppression_premier_element(Liste);
                            printf("la supression a été effectué,la premier element est suprimpee\n");
                            break;
                case 6 :
                    assert(!vide(Liste));
                            suppression_dernier_element(Liste);
                            printf("la supression a été effectué,le dernier element est suprimee\n");
                            break;
               case 7 :
                    assert(!vide(Liste));
                    do
                            {
                            printf("saisir la position que vous voulez: \n");
                            scanf("%d",&pos);
                            }while(pos<=1||pos>Liste->dim);

                            supprimer_element(Liste,pos);
                            printf("la supression a été effectué\n");
                            break;
                case 8 :
                    assert(!vide(Liste));
                            suppression_toute_liste(Liste);
                            printf("la supression a été effectué,la liste est vide\n");
                            break;
                case 9 :
                    exit(0);
        }

        }

}

}


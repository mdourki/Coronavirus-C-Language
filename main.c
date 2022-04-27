#include <stdio.h>
#include <stdlib.h>
#include "file.c"
#include "file.h"
#include <stdbool.h>

int main()
{
    int c;
    listePatients lp = NULL;
    listeHopitaux lh = NULL;
    listeDesLieux ll = NULL;
    listePersonneQuarantaine lpQ = NULL;

  do
  {
    printf("\tDHAINI AMINE && DOURKI MOHAMED 2APG2");
    printf(" \n\n\t\t ______________________MENU______________________\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 1-Ajouter un patient                           |\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 2-Afficher la liste des patient                |\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 3-Modifier l'etat d'un patient                 |\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 4-Supprimer une personne guerie                |\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 5-Ajouter un hopital                           |\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 6-Afficher la liste des hopitaux               |\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 7-Modifier un hopital                          |\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 8-Affecter un patient a un hopital             |\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 9-Ajouter un lieu                              |\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 10-Ajouter une personne en quarantaine         |\n");

    printf("\t\t|                                                |\n");

    printf("\t\t| 11-Quitter                                     |\n");

    printf("\t\t|________________________________________________|\n\n");

    do
    {
        printf("\t\tChoix : ");scanf("%d",&c);
    }while( c!=1 && c!=2 && c!=3 && c!=4 && c!=5 && c!=6 && c!=7 && c!=8 && c!=9 && c!=10 && c!=11);

    switch(c)
    {
        case 1:
            system("CLS");
            lp=AjouterPatient(lp);
            printf("\n");
            system("pause 1");
            system("CLS");
            break;
        case 2:
            system("CLS");
            AfficherListePatients(lp);
            printf("\n");
            system("pause 1");
            system("CLS");
            break;
        case 3:
            system("CLS");
            modifierEtatPatient(lp);
            printf("\n");
            system("pause 1");
            system("CLS");
            break;
        case 4:
            system("CLS");
            lp = personneGuerie(lp,lh);
            printf("\n");
            system("pause 1");
            system("CLS");
            break;
        case 5:
            system("CLS");
            lh = AjouterHopital(lh);
            printf("\n");
            system("pause 1");
            system("CLS");
            break;

        case 6:
            system("CLS");
            AfficherListeHopitaux(lh);
            printf("\n");
            system("pause 1");
            system("CLS");
            break;

        case 7:
            system("CLS");
            lh = ModifierHopital(lh);
            printf("\n");
            system("pause 1");
            system("CLS");
            break;

        case 8:
            system("CLS");
            lh = AffecterPatientHopital(lh , lp);
            printf("\n");
            system("pause 1");
            system("CLS");
            break;

        case 9:
            system("CLS");
            ll = AjouterLieu(ll);
            printf("\n");
            system("pause 1");
            system("CLS");
            break;

        case 10:
            system("CLS");
            lpQ = AjouterPersonneQuarantaine(lpQ , ll);
            printf("\n");
            system("pause 1");
            system("CLS");
            break;

        default:break;
    }

  }while(c!=11);

    return 0;
}

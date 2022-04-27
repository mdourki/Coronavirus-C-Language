#include "file.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Gérer une liste des patients avec plusieurs primitives */
listePatients AjouterPatient(listePatients lp)
{
   int c;//Choix
   int cpt = 0;//Compter 3 maladies
   patient *ptr = lp;

   patient *nv = (patient*)malloc(sizeof(patient));
   //Nom
   printf("\n\nLe nom du patient : ");
   rewind(stdin);
   gets(nv->Nom);
   //Prénom
   printf("\nLe prenom du patient : ");
   rewind(stdin);
   gets(nv->Prenom);
   //Adresse
   printf("\nL'adresse du patient : ");
   rewind(stdin);
   gets(nv->Adresse);
   //Age
   printf("\nL'age du patient : ");
   scanf("%d",&nv->age);
   //Maladies
   nv->lm = NULL;
   printf("\n******Maladies******");
   printf("\nAjoutez des maladies ?");
   printf("\n1-Oui\n2-Non");

   do
   {
     printf("\n\tchoix : ");
     scanf("%d",&c);
   }while(c!=1 && c!=2);


   if(c == 1)
   {
       while(cpt < 3)
       {
          nv->lm = AjouterMaladies(nv->lm);
          cpt++;
       }
   }

   //Personnes étaient en contact direct avec le patient
   nv->lp = NULL;

   printf("\n******Personnes etaient en contact direct avec le patient******");
   do
   {
     printf("\nAjoutez une personne ?");
     printf("\n1-Oui\n2-Non");
     do
      {
        printf("\n\tchoix : ");
        scanf("%d",&c);
      }while(c!=1 && c!=2);

      if(c == 1)
      {
          nv->lp = AjouterPersonne(nv->lp);
      }
   }while(c == 1);

   //contamination introduite
   printf("\n******Contamination introduite******");
   printf("\n1-Oui\n2-Contamination est locale");
     do
      {
        printf("\n\tchoix : ");
        scanf("%d",&c);
      }while(c!=1 && c!=2);

      if(c == 1)
      {
          nv->contamination = true;
      }
      if(c==2)
      {
          nv->contamination = false;
      }

   //Etat
   printf("\n******Etat du patient******");
    printf("\nChoisissez un des deux choix suivants : ");
    printf("\n1-Normal\n2-Critique");
    do
    {
      printf("\n\t\t\t choix : ");
      scanf("%d",&c);
    }while(c != 1 && c!=2);

    if(c == 1)
    {
      strcpy(nv->etat,"normal");
    }

    if(c==2)
    {
      strcpy(nv->etat,"critique");
    }

   nv->suivant = NULL;

   if(lp == NULL)
   {
       return nv;
   }

   while(ptr->suivant != NULL)
   {
        ptr = ptr->suivant;
   }

   ptr->suivant = nv;

   return lp;

}

void modifierEtatPatient(listePatients lp)
{
    int c;//choix
    patient p;
    patient *ptr;

    printf("\n******Etat du patient******");
    printf("\nInformations a propos du patient a modifier son etat : ");
      //Nom
      printf("\n\nLe nom du patient : ");
      rewind(stdin);
      gets(p.Nom);
      //Prénom
      printf("\nLe prenom du patient : ");
      rewind(stdin);
      gets(p.Prenom);
      //Adresse
      printf("\nL'adresse du patient : ");
      rewind(stdin);
      gets(p.Adresse);
      //Age
      printf("\nL'age du patient : ");
      scanf("%d",&p.age);

      ptr = RechercherPatient(lp , p);

  if(ptr != NULL)
  {

    printf("\nChoisissez un des deux choix suivants : ");
    printf("\n1-Normal\n2-Critique");
    do
    {
      printf("\n\t\t\t choix : ");
      scanf("%d",&c);
    }while(c != 1 && c!=2);

    if(c == 1)
    {
      strcpy(ptr->etat,"normal");
    }

    if(c==2)
    {
      strcpy(ptr->etat,"critique");
    }
  }
  else
  {
    printf("\nVotre patient n existe pas dans la liste");
  }

}

patient* RechercherPatient(listePatients lp , patient p)
{
    //return le pointeur qui pointe sur le patient trouvé
    //return NULL si patient n'existe pas ou la liste est vide

    patient *ptr = lp;

    if(lp==NULL)
    {
        return NULL;
    }

    else
    {


      while(ptr !=NULL)
      {

         if(strcmp(ptr->Nom , p.Nom) == 0 && strcmp(ptr->Prenom , p.Prenom) == 0 && strcmp(ptr->Adresse , p.Adresse) == 0 && ptr->age == p.age)
          {
              return ptr;
          }

          ptr = ptr->suivant;
      }

      return NULL;
    }
}

void AfficherListePatients(listePatients lp)
{
    patient *ptr = lp;
    int i = 1;

    if (lp == NULL)
    {
        printf("\nListe des patients est vide");
    }


    else
    {
       while(ptr != NULL)
       {
        printf("\n******Patient %d*******",i);
        printf("\nNom : %s" , ptr->Nom);
        printf("\nPrenom : %s" , ptr->Prenom);
        printf("\nAdresse : %s" , ptr->Adresse);
        printf("\nAge : %d" , ptr->age);
        printf("\n\n\tMaladies");
        AfficherListeMaladies(ptr->lm);
        printf("\n\n\tPersonnes etaient en contact direct avec le patient");
        AfficherPersonnes(ptr->lp);
        printf("\n\n\tContamination introduite");
        if(ptr->contamination)
        {
          printf("\nOui");
        }
        else
        {
           printf("\nContamination locale");
        }
        printf("\n\nEtat : %s" , ptr->etat);
        printf("\n");
        i++;
        ptr = ptr->suivant;
       }
    }
}

listeMaladies AjouterMaladies(listeMaladies lm)
{

   maladie *ptr = lm;

   maladie *nv = (maladie*)malloc(sizeof(maladie));


     printf("\nNom du maladie : ");
     rewind(stdin);
     gets(nv->nomDuMaladie);
     nv->suivant = NULL;

     if(lm == NULL)
     {
       return nv;
     }

     while(ptr->suivant != NULL)
     {
        ptr = ptr->suivant;
     }

     ptr->suivant = nv;
     return lm;
}

void AfficherListeMaladies(listeMaladies lm)
{
    maladie *ptr = lm;
    int i = 1;

    if (lm == NULL)
    {
        printf("\nCe patient n'a aucume maladie chronique");
    }

    else
    {
       while(ptr != NULL)
       {
        printf("\nMaladie %d : %s",i,ptr->nomDuMaladie);
        i++;
        ptr = ptr->suivant;
       }
    }
}

listePersonnes AjouterPersonne(listePersonnes lp)
{
   personne *ptr= lp;
   personne *nv = (personne*)malloc(sizeof(personne));

   printf("\nNom : ");
   rewind(stdin);
   gets(nv->Nom);
   printf("\nPrenom : ");
   rewind(stdin);
   gets(nv->Prenom);
   printf("\nAdresse : ");
   rewind(stdin);
   gets(nv->Adresse);
   printf("\nAge : ");
   scanf("%d",&nv->age);
   nv->suivant = NULL;

   if(lp == NULL)
     {
       return nv;
     }

     while(ptr->suivant != NULL)
     {
        ptr = ptr->suivant;
     }

     ptr->suivant = nv;
     return lp;
}

void AfficherPersonnes(listePersonnes lp)
{
   personne *ptr = lp;
   int i = 1;

   if(lp == NULL)
   {
       printf("\nCe patient n'a ete en contact avec aucune personne");
   }

   else
   {
       while(ptr != NULL)
       {
           printf("\n\n\tPersonne %d",i);
           printf("\nNom : %s" , ptr->Nom);
           printf("\nPrenom : %s" , ptr->Prenom);
           printf("\nAdresse : %s" , ptr->Adresse);
           printf("\nAge : %d" , ptr->age);
           ptr = ptr->suivant;
           i++;
       }
   }
}

listePatients SupprimerPatient(listePatients lp , patient *ptr)
{
    patient *cpt = lp ;

  if(lp == ptr)
  {
       cpt = lp->suivant;
      free(lp);
      return cpt;
  }

  else
  {
       while(cpt ->suivant != ptr)
      {
        cpt = cpt->suivant;
      }
      cpt->suivant = ptr->suivant;
       free(ptr);
       return lp;
  }
}

listePatients personneGuerie(listePatients lp , listeHopitaux lh)
{
   int c;//choix
    patient p;
    patient *ptr;
    patient *ptr2;
    patient *ptrS;
    hopital *ptrH = lh;

    printf("\n******Supprimer une personne guerie******");
    printf("\nInformations a propos du patient a chercher : ");
    //Nom
      printf("\n\nLe nom du patient : ");
      rewind(stdin);
      gets(p.Nom);
      //Prénom
      printf("\nLe prenom du patient : ");
      rewind(stdin);
      gets(p.Prenom);
      //Adresse
      printf("\nL'adresse du patient : ");
      rewind(stdin);
      gets(p.Adresse);
      //Age
      printf("\nL'age du patient : ");
      scanf("%d",&p.age);

      ptr = RechercherPatient(lp , p);
      ptrS = ptr;

  if(ptr != NULL)
  {
    printf("\nCette personne a guerie ?");
    printf("\n1-Oui\n2-Non");
    do
    {
      printf("\n\t\t\t choix : ");
      scanf("%d",&c);
    }while(c != 1 && c!=2);

    if(c == 1)
    {
        //Chercher l'hôpital où il est ce patient
        while(ptrH != NULL)
        {
           ptr2 = RechercherPatient(ptrH->lpH , p);
           if(ptr2 != NULL)
           {
               break;
           }
           else
           {
               ptrH = ptrH->suivant;
           }
        }

      //supprimer cette personne de la liste
      lp = SupprimerPatient(lp , ptr);

      if( strcmp(ptr2->etat , "normal") == 0 )
      {
         ptrH->nbrLitsAilleurs++;
      }

      if( strcmp(ptr2->etat , "critique") == 0 )
      {
          ptrH->nbrLitsRea++;
      }

      ptrH->nbrSallesCorona++;
      ptrH->lpH = SupprimerPatient(ptrH->lpH , ptr2);
    }
  }
  else
  {
    printf("\nVotre patient n existe pas dans la liste");
  }

  return lp;
}

/* Gérer une liste des hôpitaux avec plusieurs primitives */

listeHopitaux AjouterHopital(listeHopitaux lh)
{
   hopital *ptr = lh;

   hopital *nv = (hopital*)malloc(sizeof(hopital));

     printf("\n\n******Ajouter hopital******");
     printf("\nNom de l'hopital : ");
     rewind(stdin);
     gets(nv->Nom);
     printf("\nAdresse de l'hopital : ");
     rewind(stdin);
     gets(nv->Adresse);
     do
     {
        printf("\nNombre de lits en reanimation : ");
        scanf("%d",&nv->nbrLitsRea);
     }while(nv->nbrLitsRea < 0);

     do
     {
        printf("\nNombre de lits ailleurs : ");
        scanf("%d",&nv->nbrLitsAilleurs);
     }while(nv->nbrLitsAilleurs < 0);

     do
     {
        printf("\nNombre de salles de corona : ");
        scanf("%d",&nv->nbrSallesCorona);
     }while(nv->nbrSallesCorona < 0);

     do
     {
        printf("\nNombre de salles de dialyse  : ");
        scanf("%d",&nv->nbrSallesDialyse);
     }while(nv->nbrSallesDialyse < 0);

     do
     {
        printf("\nNombre de medecins specialises : ");
        scanf("%d",&nv->nbrMedecinsSpecialises);
     }while(nv->nbrMedecinsSpecialises < 0);

     do
     {
        printf("\nNombre de paramedicaux  : ");
        scanf("%d",&nv->nbrParamedicaux);
     }while(nv->nbrParamedicaux < 0);

     nv->lpH = NULL;

     nv->suivant = NULL;

     if(lh == NULL)
     {
       return nv;
     }

     while(ptr->suivant != NULL)
     {
        ptr = ptr->suivant;
     }

     ptr->suivant = nv;
     return lh;
}

void AfficherListeHopitaux(listeHopitaux lh)
{
  hopital *ptr = lh;
    int i = 1;

    if (lh == NULL)
    {
        printf("\nListe des hopitaux est vide");
    }

    else
    {
       while(ptr != NULL)
       {
        printf("\n************Hopital %d************",i);
        printf("\nNom : %s" , ptr->Nom);
        printf("\nAdresse : %s" , ptr->Adresse);
        printf("\nNombre de lits en reanimation : %d" , ptr->nbrLitsRea);
        printf("\nNombre de lits ailleurs : %d" , ptr->nbrLitsAilleurs);
        printf("\nNombre de salles de corona : %d" , ptr->nbrSallesCorona);
        printf("\nNombre de salles de dialyse  : %d" , ptr->nbrSallesDialyse);
        printf("\nNombre de medecins spesialises : %d" , ptr->nbrMedecinsSpecialises);
        printf("\nNombre de paramedicaux  : %d" , ptr->nbrParamedicaux);
        printf("\n\tListe des patients");
        AfficherListePatients(ptr->lpH);
        printf("\n");
        i++;
        ptr = ptr->suivant;
       }
    }
}

hopital* RechercherHopital(listeHopitaux lh , hopital h)
{
    //return le pointeur qui pointe sur l'hôpital trouvé
    //return NULL si l'hôpital n'existe pas ou la liste est vide

    hopital *ptr = lh;

    if(lh==NULL)
    {
        return NULL;
    }

    else
    {
      while(ptr !=NULL)
      {

         if(strcmp(ptr->Nom , h.Nom) == 0 && strcmp(ptr->Adresse , h.Adresse) == 0)
          {
              return ptr;
          }

          ptr = ptr->suivant;
      }

      return NULL;
    }
}

listeHopitaux ModifierHopital(listeHopitaux lh)
{
    hopital h;
    hopital *ptr;

   printf("\n\n******Modification d'un hopital******");
   printf("\nNom de l'hopital a modifier : ");
   rewind(stdin);
   gets(h.Nom);
   printf("\nAdresse de l'hopital a modifier : ");
   rewind(stdin);
   gets(h.Adresse);

   ptr = RechercherHopital(lh , h);

  if(ptr != NULL)
  {
     printf("\nNouveau nom : ");
     rewind(stdin);
     gets(ptr->Nom);
     printf("\nNouvel adresse : ");
     rewind(stdin);
     gets(ptr->Adresse);
     do
     {
        printf("\nNombre de lits en reanimation : ");
        scanf("%d",&ptr->nbrLitsRea);
     }while(ptr->nbrLitsRea < 0);

     do
     {
        printf("\nNombre de lits ailleurs : ");
        scanf("%d",&ptr->nbrLitsAilleurs);
     }while(ptr->nbrLitsAilleurs < 0);

     do
     {
        printf("\nNombre de salles de corona : ");
        scanf("%d",&ptr->nbrSallesCorona);
     }while(ptr->nbrSallesCorona < 0);

     do
     {
        printf("\nNombre de salles de dialyse  : ");
        scanf("%d",&ptr->nbrSallesDialyse);
     }while(ptr->nbrSallesDialyse < 0);

     do
     {
        printf("\nNombre de medecins spesialises : ");
        scanf("%d",&ptr->nbrMedecinsSpecialises);
     }while(ptr->nbrMedecinsSpecialises < 0);

     do
     {
        printf("\nNombre de paramedicaux  : ");
        scanf("%d",&ptr->nbrParamedicaux);
     }while(ptr->nbrParamedicaux < 0);
  }

  else
  {
    printf("\nVotre hopital n existe pas dans la liste");
  }

   return lh;
}

listeHopitaux AffecterPatientHopital(listeHopitaux lh , listePatients lp)
{
    patient p;
    hopital h;
    patient *ptrP;
    hopital *ptrH;

    printf("\n\n******Affectation d'un patient a un hopital******");
    printf("\n\tInformations a propos du patient a affecter : ");
      //Nom
      printf("\n\nLe nom du patient : ");
      rewind(stdin);
      gets(p.Nom);
      //Prénom
      printf("\nLe prenom du patient : ");
      rewind(stdin);
      gets(p.Prenom);
      //Adresse
      printf("\nL'adresse du patient : ");
      rewind(stdin);
      gets(p.Adresse);
      //Age
      printf("\nL'age du patient : ");
      scanf("%d",&p.age);

      ptrP = RechercherPatient(lp , p);

  if(ptrP != NULL)
  {

         printf("\n\tInformations a propos de l'hopital ou vous voulez affecter ce patient : ");
         printf("\nNom de l'hopital : ");
         rewind(stdin);
         gets(h.Nom);
         printf("\nAdresse de l'hopital : ");
         rewind(stdin);
         gets(h.Adresse);

         ptrH = RechercherHopital(lh , h);

      if(ptrH != NULL)
      {
        if( ptrH->nbrSallesCorona >= 1 && ptrH->nbrLitsRea >= 1 && ptrH->nbrLitsAilleurs >= 1 )
        {
              ptrH->nbrSallesCorona--;
              if(strcmp(ptrP->etat , "normal") == 0)
             {
                ptrH->nbrLitsAilleurs --;
             }

             if(strcmp(ptrP->etat , "critique") == 0)
             {
                ptrH->nbrLitsRea --;
             }

             //Ajouter patient a la liste des hopitaux
             ptrH->lpH = AjouterPatientListeHopitaux(ptrH->lpH , ptrP);
        }
        else
        {
            printf("\nImpossible d'ajouter ce patient a cet hopital");
            printf("\nVerifier le nombre de lits ou de salles");
        }

      }
      else
      {
          printf("\nVotre hopital n'existe pas dans la liste des hopitaux");
      }
  }

  else
  {
    printf("\nVotre patient n'existe pas dans la liste des patients");
  }

      return lh;
}

/* Ajouter un patient à la liste des patients d'un hôpital */
listePatients AjouterPatientListeHopitaux(listePatients lp , patient *p)
{
   patient *ptr = lp;
   patient *nv = (patient*)malloc(sizeof(patient));

   strcpy(nv->Nom , p->Nom);
   strcpy(nv->Prenom , p->Prenom);
   strcpy(nv->Adresse , p->Adresse);
   nv->age = p->age;
   nv->lm = p->lm;
   nv->lp = p->lp;
   nv->contamination = p->contamination;
   strcpy(nv->etat , p->etat);

   nv->suivant = NULL;

   if(lp == NULL)
   {
       return nv;
   }

   while(ptr->suivant != NULL)
   {
        ptr = ptr->suivant;
   }

   ptr->suivant = nv;

   return lp;
}


/* Gestion des personnes en quarantaine */

listePersonneQuarantaine AjouterPersonneQuarantaine(listePersonneQuarantaine lpq , listeDesLieux ll)
{
   int c;//Choix
   int cpt = 0;//Compter 3 maladies
   personneQuarantaine *ptr = lpq;
   Lieu *ptrL;
   Lieu l;

   personneQuarantaine *nv = (personneQuarantaine*)malloc(sizeof(personneQuarantaine));
   //Nom
   printf("\n\nLe nom du patient : ");
   rewind(stdin);
   gets(nv->Nom);
   //Prénom
   printf("\nLe prenom du patient : ");
   rewind(stdin);
   gets(nv->Prenom);
   //Adresse
   printf("\nL'adresse du patient : ");
   rewind(stdin);
   gets(nv->Adresse);
   //Age
   printf("\nL'age du patient : ");
   scanf("%d",&nv->age);
   //Maladies
   nv->lm = NULL;
   printf("\n******Maladies******");
   printf("\nAjoutez des maladies ?");
   printf("\n1-Oui\n2-Non");

   do
   {
     printf("\n\tchoix : ");
     scanf("%d",&c);
   }while(c!=1 && c!=2);


   if(c == 1)
   {
       while(cpt < 3)
       {
          nv->lm = AjouterMaladies(nv->lm);
          cpt++;
       }
   }

   //Personnes étaient en contact direct avec le patient
   nv->lp = NULL;

   printf("\n******Personnes etaient en contact direct avec le patient******");
   do
   {
     printf("\nAjoutez une personne ?");
     printf("\n1-Oui\n2-Non");
     do
      {
        printf("\n\tchoix : ");
        scanf("%d",&c);
      }while(c!=1 && c!=2);

      if(c == 1)
      {
          nv->lp = AjouterPersonne(nv->lp);
      }
   }while(c == 1);

   //Contamination introduite
   printf("\n******Contamination introduite******");
   printf("\n1-Oui\n2-Contamination est locale");
     do
      {
        printf("\n\tchoix : ");
        scanf("%d",&c);
      }while(c!=1 && c!=2);

      if(c == 1)
      {
          nv->contamination = true;
      }
      if(c==2)
      {
          nv->contamination = false;
      }

    //Provenance
    printf("\n\nProvenance : ");
    rewind(stdin);
    gets(nv->provenance);

    //Date du début du confinement
    printf("\n\tDate debut du confinement");
    nv->dateDebut = lireDate();

    //Date de fin du confinement
    printf("\n\tDate de fin du confinement");
    nv->dateFin = lireDate();

    //Affectation du cette personne a un lieu

         printf("\n\tInformations a propos du lieu ou vous voulez affecter ce patient : ");
         printf("\nAdresse de ce lieu :");
         rewind(stdin);
         gets(l.Adresse);

         ptrL = RechercherLieu(ll , l);

      if(ptrL != NULL)
      {
          if( strcmp(ptrL->l , "Hotel gere par l'etat") == 0 && ptrL->placesDispo < 1)
          {
            printf("\nImpossible d'affecter cette personne a ce lieu");
            printf("\nVerifier le nompbre de places disponibles dans ce lieu");
          }
          else
          {
            ptrL->placesDispo--;
            // Ajouter cette personne a la liste des personnes en quarantine d'un lieu
            ptrL->lpq = AjouterPatientListeLieu(ptrL->lpq , nv);
          }
      }
      else
      {
          printf("\nCe lieu n'existe pas dans la liste des lieux");
      }

   nv->suivant = NULL;

   if(lpq == NULL)
   {
       return nv;
   }

   while(ptr->suivant != NULL)
   {
        ptr = ptr->suivant;
   }

   ptr->suivant = nv;

   return lpq;
}

Date lireDate()
{
   Date d;

   do
   {
      printf("\nJour : ");
      scanf("%d" , &d.jj);
      printf("\nMois : ");
      scanf("%d" , &d.mm);
      printf("\nAnnee : ");
      scanf("%d" , &d.aaaa);

      if(!verifierDate(d))
      {
          printf("\nDate non valide");
      }
   }while(!verifierDate(d));


   return d;
}

bool verifierDate(Date d)
{
   //return true si date est valide
   //return false si date est non valide

   if(d.mm == 1 || d.mm == 3 || d.mm == 5 || d.mm == 7 || d.mm == 8 || d.mm == 10 || d.mm == 12)
   {
      if(d.jj > 0 && d.jj <=31)
      {
         return true;
      }
   }

   else if(d.mm == 4 || d.mm == 6 || d.mm == 9 || d.mm == 11)
   {
      if(d.jj > 0 && d.jj <31)
      {
         return true;
      }
   }

   else if(d.mm == 2)
   {
       if(d.jj == 29)
       {
          if(d.aaaa % 4 == 0)
          {
              return true;
          }
       }

       else if(d.jj > 0 && d.jj < 29)
       {
           return true;
       }
   }

   return false;
}

listeDesLieux AjouterLieu(listeDesLieux ll)
{
    int c;//choix
   Lieu *ptr = ll;

   Lieu *nv = (Lieu*)malloc(sizeof(Lieu));


    printf("\nChoisissez un des deux choix suivants : ");
    printf("\n1-Maison du patient\n2-Hotel gere par l'etat");
    do
    {
      printf("\n\t\t\t choix : ");
      scanf("%d",&c);
    }while(c != 1 && c!=2);

    if(c == 1)
    {
      strcpy(nv->l,"Maison du patient");
    }

    if(c==2)
    {
      strcpy(nv->l,"Hotel gere par l'etat");
    }

    printf("\nAdresse du lieu : ");
    rewind(stdin);
    gets(nv->Adresse);

    do
    {
      printf("\nCapacite de ce lieu : ");
      scanf("%d" , &nv->capacite);
    }while(nv->capacite < 1);

    do
    {
      printf("\nPlaces disponibles dans ce lieu : ");
      scanf("%d" , &nv->placesDispo);
    }while(nv->placesDispo > nv->capacite);

     nv->lpq = NULL;

     nv->suivant = NULL;

     if(ll == NULL)
     {
       return nv;
     }

     while(ptr->suivant != NULL)
     {
        ptr = ptr->suivant;
     }

     ptr->suivant = nv;
     return ll;
}

Lieu* RechercherLieu(listeDesLieux ll , Lieu l)
{
    //return le pointeur qui pointe sur le lieu trouvé
    //return NULL si le lieu n'existe pas ou la liste est vide

    Lieu *ptr = ll;

    if(ll==NULL)
    {
        return NULL;
    }

    else
    {
      while(ptr !=NULL)
      {

         if(strcmp(ptr->Adresse , l.Adresse) == 0)
          {
              return ptr;
          }

          ptr = ptr->suivant;
      }

      return NULL;
    }
}

/* Ajouter un patient a la liste des personnes en quarantine d'un lieu */
listePersonneQuarantaine AjouterPatientListeLieu(listePersonneQuarantaine lpq , personneQuarantaine *p)
{
   personneQuarantaine *ptr = lpq;
   personneQuarantaine *nv = (personneQuarantaine*)malloc(sizeof(personneQuarantaine));

   strcpy(nv->Nom , p->Nom);
   strcpy(nv->Prenom , p->Prenom);
   strcpy(nv->Adresse , p->Adresse);
   nv->age = p->age;
   nv->lm = p->lm;
   nv->lp = p->lp;
   nv->contamination = p->contamination;
   strcpy(nv->provenance , p->provenance);
   //Date début de confinement
   nv->dateDebut.aaaa = p->dateDebut.aaaa;
   nv->dateDebut.mm = p->dateDebut.mm;
   nv->dateDebut.jj = p->dateDebut.jj;

   //Date fin de confinement
   nv->dateFin.aaaa = p->dateFin.aaaa;
   nv->dateFin.mm = p->dateFin.mm;
   nv->dateFin.jj = p->dateFin.jj;

   if(lpq == NULL)
   {
       return nv;
   }

   while(ptr->suivant != NULL)
   {
        ptr = ptr->suivant;
   }

   ptr->suivant = nv;

   return lpq;
}

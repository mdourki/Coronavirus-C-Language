#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include <stdbool.h>

/* Liste des maladies chroniques */
typedef struct
{
   char nomDuMaladie[10];
   struct maladie *suivant;
}maladie;

typedef maladie* listeMaladies;

/* Liste des personnes étaient en contact direct avec le patient */
typedef struct
{
    char Nom[10];
    char Prenom[10];
    char Adresse[30];
    int age;
    struct personne *suivant;
}personne;

typedef personne* listePersonnes;

/* Patient */
typedef struct
{
   char Nom[10];
   char Prenom[10];
   char Adresse[30];
   int age;
   listeMaladies lm;//Liste des maladies chroniques
   listePersonnes lp;//Liste des personnes étaient en contact direct avec le patient
   bool contamination;//vrai si oui, faux si la contamination est locale
   char etat[9];
   struct patient *suivant;
}patient;

typedef patient* listePatients;


/* Hôpital */

typedef struct
{
    char Nom[10];
    char Adresse[30];
    int nbrLitsRea;
    int nbrLitsAilleurs;
    int nbrSallesCorona;
    int nbrSallesDialyse;
    int nbrMedecinsSpecialises;
    int nbrParamedicaux;
    listePatients lpH;//Liste des patients dans l'hôpital
    struct hopital *suivant;
}hopital;

typedef hopital* listeHopitaux;

/* Date */
typedef struct
{
  int jj,mm,aaaa;
}Date;

/* Personne en quarantaine */
typedef struct
{
   char Nom[10];
   char Prenom[10];
   char Adresse[30];
   int age;
   listeMaladies lm;//Liste des maladies chroniques
   listePersonnes lp;//Liste des personnes étaient en contact direct avec cette personne
   bool contamination;//vrai si oui, faux si la contamination est locale
   char provenance[10];
   Date dateDebut;//Date du début du confinement
   Date dateFin;//Date du début du confinement
   struct personneQuarantaine *suivant;
}personneQuarantaine;

/* Liste des personne en quarantaine */
typedef personneQuarantaine* listePersonneQuarantaine;

/* Lieu */
typedef struct
{
    char l[30];//Chez lui ou lieu géré par l’état comme les hôtels
    char Adresse[30];
    int capacite;
    int placesDispo;
    listePersonneQuarantaine lpq;//Liste des personnes dans ce lieu
    struct Lieu *suivant;
}Lieu;

/* Liste des lieux */
typedef Lieu* listeDesLieux;



/* Gérer une liste des patients avec plusieurs primitives */
listePatients AjouterPatient(listePatients lp);
void modifierEtatPatient(listePatients lp);
patient* RechercherPatient(listePatients lp , patient p);
void AfficherListePatients(listePatients lp);
listeMaladies AjouterMaladies(listeMaladies lm);
void AfficherListeMaladies(listeMaladies lm);
listePersonnes AjouterPersonne(listePersonnes lp);
void AfficherPersonnes(listePersonnes lp);
listePatients SupprimerPatient(listePatients lp , patient *ptr);
listePatients personneGuerie(listePatients lp , listeHopitaux lh);

/* Gérer une liste des hôpitaux avec plusieurs primitives */
listeHopitaux AjouterHopital(listeHopitaux lh);
void AfficherListeHopitaux(listeHopitaux lh);
hopital* RechercherHopital(listeHopitaux lh , hopital h);
listeHopitaux ModifierHopital(listeHopitaux lh);
listeHopitaux AffecterPatientHopital(listeHopitaux lh , listePatients lp);
listePatients AjouterPatientListeHopitaux(listePatients lp , patient *p);

/* Gestion des personnes en quarantaine */
listePersonneQuarantaine AjouterPersonneQuarantaine(listePersonneQuarantaine lpq , listeDesLieux ll);
Date lireDate();
bool verifierDate(Date d);
listeDesLieux AjouterLieu(listeDesLieux ll);
Lieu* RechercherLieu(listeDesLieux ll , Lieu l);
listePersonneQuarantaine AjouterPatientListeLieu(listePersonneQuarantaine lpq , personneQuarantaine *p);


#endif // FILE_H_INCLUDED

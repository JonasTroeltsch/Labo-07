/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Non du labo    : Labo 7 Matrices
Auteur(s)      : Jonas Troeltsch et Vincent Bruzzese
Date creation  : 07.12.2021
But            :
Remarque(s)    :
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include "vecteurs.h"

using namespace std;
using Ligne = vector<int>;
using Matrice = vector<Ligne>;

int main() {
   Ligne l1 = {1,2,3,4,5};
   Matrice m1 = {l1,l1,l1,l1,l1};

   Matrice matrice;

   cout<<"la matrice est regulière (0 = non, 1 = oui):"<< estReguliere(matrice)
   <<endl;
   cout<< "la matrice est carre (0 = non, 1 = oui):"<<estCarre(matrice)<<endl;

   cout<< " la longueur minimum des vecteurs d’une matrice est de : " <<minCol
   (matrice)<<endl;

   cout<< "la somme des lignes est : "<<sommeLigne(matrice)<<endl;
   cout<< "la somme des collonnes est : "<<sommeColonne(matrice)<<endl;

   cout<<"le vecteur dont la somme des valeurs est la plus faible "
         ":"<<endl<<vectSommeMin
   (matrice)<<endl;

   shuffleMatrice(matrice);
   cout<<"La matrice mélangé aléatoirement"<<endl<<matrice<<endl;

   sortMatrice(matrice);
   cout<<"la matrice trié dans l’ordre croissant en fonction de "
         "l’élément min d’un vecteur."<<endl<<matrice<<endl;
   cout<<endl;



 return EXIT_SUCCESS;
}


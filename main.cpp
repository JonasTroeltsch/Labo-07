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

   Matrice matrice = {  {1,2}
                        ,{1,3}
                        ,{1,3}};

   cout<< estReguliere(matrice)<<endl;
   cout<< estCarre(matrice)<<endl;

 return EXIT_SUCCESS;
}


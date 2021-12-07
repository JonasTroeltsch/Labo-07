/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Non du labo    : Labo 7 Matrices
Auteur(s)      : Jonas Troeltsch
Date creation  : 07.12.2021
But            :
Remarque(s)    :
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {

using Ligne = vector<int>;
using Matrice = vector<Ligne>;

 return EXIT_SUCCESS;
}

bool estCarre(vector<vector<int>> matrice){

   return matrice.size() == matrice.at(0).size();
}
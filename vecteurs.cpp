/*
-----------------------------------------------------------------------------------
Nom du fichier : vecteurs.cpp
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

bool estCarre(vector<vector<int>> matrice){

   return matrice.size() == matrice.at(0).size();
}

void afficherVectorInt(vector <int> ligne){
    cout<<"(";
    for (size_t i = 0 ; i < ligne.size() ; ++i){
        cout<<ligne[i]; (i+1)==ligne.size()?cout<<")":cout<<",";
    }
    //cout<<")";
}

void afficherMatriceInt(vector <vector <int>> matrice){

    //cout<<"[";
    for (size_t i = 0 ; i < matrice.size() ; ++i ){
        i==0?cout<<"[":cout<<" ";
        afficherVectorInt(matrice[i]); (i+1)==matrice.size()?cout<<"]":cout<<","<<endl;
    }
    //cout<<"]";
}

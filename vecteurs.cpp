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
#include <algorithm>
#include "vecteurs.h"

using namespace std;

bool size_compare(const vector<int>& ligne1,const vector<int>& ligne2){
   return ligne1.size() < ligne2.size();
}

bool size_equal(const vector<int>& ligne1,const vector<int>& ligne2){
   return ligne1.size() == ligne2.size();
}

bool estReguliere(vector<vector<int>> matrice){
   return min_element(matrice.begin(),matrice.end(), size_compare) == max_element
   (matrice.begin(),matrice.end(), size_compare);
}
bool estCarre(vector<vector<int>> matrice){
   if(estReguliere(matrice)){
      return matrice.size() == matrice.at(0).size();
   }
   return false;
}

void afficherVectorInt(vector <int> ligne){
    cout<<"(";
    for (vector<int>::iterator it = ligne.begin() ; it!= ligne.end() ; ++it){
        cout<<*it; (it+1)==ligne.end()?cout<<")":cout<<",";
    }
}

void afficherMatriceInt(vector <vector <int>> matrice){
    for (vector<vector<int>>::iterator it = matrice.begin() ; it != matrice.end() ; ++it ){
        it==matrice.begin()?cout<<"[":cout<<" ";
        afficherVectorInt(*it); (it+1)==matrice.end()?cout<<"]":cout<<","<<endl;
    }
}

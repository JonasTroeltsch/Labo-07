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
#include <chrono>
#include <random>
#include "vecteurs.h"

using namespace std;

using Ligne = vector<int>;
using Matrice = vector<Ligne>;

bool size_compare(const vector<int>& ligne1,const vector<int>& ligne2){
   return ligne1.size() < ligne2.size();
}

bool estReguliere(vector<vector<int>> matrice){
   if(matrice.empty()){
      return true;
   }
   return min_element(matrice.begin(),matrice.end(), size_compare) == max_element
   (matrice.begin(),matrice.end(), size_compare);
}
bool estCarre(vector<vector<int>> matrice){
   if(matrice.empty()){
      return true;
   }
   if(estReguliere(matrice)){
      return matrice.size() == matrice.front().size();
   }
   return false;
}


size_t minCol(const vector<vector<int>>& matrice){
   if(matrice.empty()){
      return 0;
   }
   return min_element(matrice.begin(),matrice.end(), size_compare)->size();
}
size_t maxCol(const vector<vector<int>>& matrice){
   if(matrice.empty()){
      return 0;
   }
   return min_element(matrice.begin(),matrice.end(), size_compare)->size();
}
void shuffleMatrice(vector <vector <int>>& matrice){
   if(matrice.empty()){
      return;
   }
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

   shuffle (matrice.begin(), matrice.end(), std::default_random_engine(seed));
}
vector<int> sommeLigne(const vector<vector<int>>& matrice){
   vector<int> VecteurReturn;
   if(matrice.empty()){
      return VecteurReturn;
   }
   for(vector<vector<int>>::const_iterator iter = matrice.begin() ; iter !=
                                                                    matrice.end() ; ++iter)
      VecteurReturn.push_back( accumulate( iter->begin() , iter->end() , 0));
   return VecteurReturn;
}
vector<int> sommeColonne (const Matrice& matrice){
   vector<int> VecteurReturn(maxCol(matrice));
   for(vector<vector<int>>::const_iterator it = matrice.begin() ; it != matrice
   .end() ; ++it)
      for(vector<int>::const_iterator jt = it->begin() ; jt != it->end() ; ++ jt)
         VecteurReturn[distance(it->begin(), jt)] += *jt ;
   return VecteurReturn;
}
void sortMatrice(vector <vector <int>>& matrice){
   sort(matrice.begin(),matrice.end());
}

vector<int> vectSommeMin(const vector<vector<int>>& matrice){
   vector<int> vectMin;
   if(matrice.empty()){
      return vectMin;
   }
   vector<int> vectSommeLigne = sommeLigne(matrice);

   std::vector<int>::iterator result = std::min_element(vectSommeLigne.begin(), vectSommeLigne.end());
   vectMin = matrice.at(std::distance(vectSommeLigne.begin(), result));

   return vectMin;
}

ostream& operator << (ostream& NewStream, const Ligne& v) {
   cout << "(";
   for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
      if (iter != v.begin())
         NewStream << ", ";
      NewStream << *iter;
   }
   cout << ")";
   return NewStream;
}


ostream& operator << (ostream& NewStream, const Matrice& m) {
   cout << "[";
   for (vector<vector<int>>::const_iterator iter = m.begin() ; iter != m.end(); ++iter) {
      if (iter != m.begin())
         NewStream << endl << " ";
      NewStream << *iter;
   }
   cout << "]";
   return NewStream;
}

/*
-----------------------------------------------------------------------------------
Nom du fichier : librairieMatrice.cpp
Non du labo    : Labo 7 Matrices
Auteur(s)      : Jonas Troeltsch et Vincent Bruzzese
Date creation  : 07.12.2021
But            : une librairie mettant à disposition les éléments nécessaires à une
               : manipulation facilitées de vecteurs et de matrices d’entiers
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
#include "librairieMatrices.h"

using namespace std;

using Ligne = vector<int>;
using Matrice = vector<Ligne>;

ostream& operator << (ostream& NewStream, const Ligne& l) {
   cout << "(";
   for (Ligne::const_iterator iter = l.begin(); iter != l.end(); ++iter) {
      if (iter != l.begin())
         NewStream << ", ";
      NewStream << *iter;
   }
   cout << ")";
   return NewStream;
}


ostream& operator << (ostream& NewStream, const Matrice& m) {
   cout << "[";
   for (Matrice::const_iterator iter = m.begin() ; iter != m.end(); ++iter) {
      if (iter != m.begin())
         NewStream << endl << " ";
      NewStream << *iter;
   }
   cout << "]";
   return NewStream;
}


bool size_compare(const Ligne& ligne1,const Ligne& ligne2){
   return ligne1.size() < ligne2.size();
}

bool estReguliere(Matrice matrice){
   if(matrice.empty()){
      return true;
   }
   return min_element(matrice.begin(),matrice.end(), size_compare) == max_element
   (matrice.begin(),matrice.end(), size_compare);
}
bool estCarre(Matrice matrice){
   if(matrice.empty()){
      return true;
   }
   if(estReguliere(matrice)){
      return matrice.size() == matrice.front().size();
   }
   return false;
}


size_t minCol(const Matrice& matrice){
   if(matrice.empty()){
      return 0;
   }
   return min_element(matrice.begin(),matrice.end(), size_compare)->size();
}

size_t maxCol(const Matrice& matrice){
   if(matrice.empty()){
      return 0;
   }
   return max_element(matrice.begin(),matrice.end(), size_compare)->size();
}

Ligne sommeLigne(const Matrice& matrice){
   Ligne VecteurReturn;
   if(matrice.empty()){
      return VecteurReturn;
   }
   for(Matrice::const_iterator iter = matrice.begin() ; iter !=
                                                        matrice.end() ; ++iter)
      VecteurReturn.push_back( accumulate( iter->begin() , iter->end() , 0));
   return VecteurReturn;
}

Ligne sommeColonne (const Matrice& matrice){
   Ligne VecteurReturn(maxCol(matrice));
   for(Matrice::const_iterator it = matrice.begin() ; it != matrice
      .end() ; ++it)
      for(Ligne::const_iterator jt = it->begin() ; jt != it->end() ; ++ jt)
         VecteurReturn[distance(it->begin(), jt)] += *jt ;
   return VecteurReturn;
}

Ligne vectSommeMin(const Matrice& matrice){
   Ligne vectMin;
   if(matrice.empty()){
      return vectMin;
   }
   Ligne vectSommeLigne = sommeLigne(matrice);

   Ligne::iterator result = std::min_element(vectSommeLigne.begin(), vectSommeLigne.end());
   vectMin = matrice.at(std::distance(vectSommeLigne.begin(), result));

   return vectMin;
}


void shuffleMatrice(Matrice& matrice){
   if(matrice.empty()){
      return;
   }
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

   shuffle (matrice.begin(), matrice.end(), std::default_random_engine(seed));
}

void sortMatrice(Matrice& matrice){
   sort(matrice.begin(),matrice.end());
}



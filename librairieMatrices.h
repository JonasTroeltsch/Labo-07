/*
-----------------------------------------------------------------------------------
Nom du fichier : librairieMatrice.h
Non du labo    : Labo 7 Matrices
Auteur(s)      : Jonas Troeltsch et Vincent Bruzzese
Date creation  : 07.12.2021
But            : une librairie mettant à disposition les éléments nécessaires à une
               : manipulation facilitées de vecteurs et de matrices d’entiers
Remarque(s)    :
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO_07_LIBRAIRIEMATRICES_H
#define LABO_07_LIBRAIRIEMATRICES_H

using Ligne = std::vector<int>;
using Matrice = std::vector<Ligne>;

// nom         operator <<
// but         Affichage d'une ligne (vector<int>)
// param       NewStream
// param       l        la ligne (vector<int>)
// return      std::ostream&
// exception   n/a
std::ostream& operator << (std::ostream& NewStream, const Ligne& l);

// nom         operator <<
// but         Affichage d'un matrice (vector<vector<int>>)
// param       NewStream
// param       m        la matrice (vector<vector<int>>)
// return      std::ostream&
// exception   n/a
std::ostream& operator << (std::ostream& NewStream, const Matrice& m);

// nom         size_compare
// but         compare la taille de deux vecteurs
// param       Ligne1         le premier vecteur
// param       ligne2         le deuxieme vecteur
// return      bool taille ligne1 plus petit que taille ligne2
// exception   n/a
bool size_compare(const Ligne& ligne1,const Ligne& ligne2);

// nom         estCarre
// but         verifie si la matrice est carré
// param       matrice  la matrice que l'on doit verifier
// return      true si elle est carre false sinon
// exception   n/a
bool estCarre(Matrice matrice);

// nom         estReguliere
// but         verifie si la matrice est reguliere
// param       matrice  la matrice que l'on doit verifier
// return      true si elle est reguliere false sinon
// exception   n/a
bool estReguliere(Matrice matrice);

// nom         minCol
// but         trouve la taille du plus petit vecteur de la matrice
// param       matrice
// return      la taille du plus petit vecteur de la matrice
// exception   n/a
size_t minCol(const Matrice& matrice);

// nom         maxCol
// but         trouve la taille du plus grand vecteur de la matrice
// param       matrice
// return      la taille du plus grand vecteur de la matrice
// exception   n/a
size_t maxCol(const Matrice& matrice);

// nom         sommeLigne
// but         Retourne un vecteur contenant la somme des valeurs de chacune des
//             lignes
//
// param       matrice
// return      vecteur contenant la somme des valeurs de chacune des lignes
// exception   n/a
Ligne sommeLigne(const Matrice& matrice);

// nom         sommeColonne
// but         Retourne un vecteur contenant la somme des valeurs de chacune des
//             collones
//
// param       matrice
// return      vecteur contenant la somme des valeurs de chacune des collones
// exception   n/a
Ligne sommeColonne (const Matrice& Matrice);

// nom         vectSommeMin
// but         Retour le vecteur d’une matrice dont la somme des valeurs
//             est la plus faible
// param       matrice
// return      le vecteur d’une matrice dont la somme des valeurs est la plus faible
// exception   n/a
Ligne vectSommeMin(const Matrice& matrice);

// nom         shuffleMatrice
// but         mélange une matrice sans modifier les lignes
// param       matrice
// return      n/a
// exception   n/a
void shuffleMatrice(Matrice& matrice);

// nom         sortMatrice
// but         Trier dans l’ordre croissant une matrice en fonction de l’élément
//             min d’un vecteur.
// param       matrice
// return      n/a
// exception   n/a
void sortMatrice(Matrice& matrice);

#endif //LABO_07_LIBRAIRIEMATRICES_H

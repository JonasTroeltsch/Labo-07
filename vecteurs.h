
#ifndef LABO_07_VECTEURS_H
#define LABO_07_VECTEURS_H

using Ligne = std::vector<int>;
using Matrice = std::vector<Ligne>;

bool estCarre(Matrice matrice);

bool estReguliere(Matrice matrice);

size_t minCol(const Matrice& matrice);

void shuffleMatrice(Matrice& matrice);

void sortMatrice(Matrice& matrice);

Ligne vectSommeMin(const Matrice& matrice);

Ligne sommeLigne(const Matrice& matrice);

Ligne sommeColonne (const Matrice& Matrice);

std::ostream& operator << (std::ostream& NewStream, const Ligne& v);

std::ostream& operator << (std::ostream& NewStream, const Matrice& m);
#endif //LABO_07_VECTEURS_H

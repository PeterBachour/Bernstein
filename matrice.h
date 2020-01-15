#ifndef _Matrice_h
#define _Matrice_h

#include "Polynome.h"

#include <cmath>
#include <iostream>

double factoriel(int val);
double coeffBinomial(int k, int n);
vector<vector<double> > matriceReduite(vector<vector<double> > mat, int ligne, int colonne=0);
bool estCarre(vector<vector<double> > matrice);
double determinant(vector<vector<double> > matrice);
vector<vector<double> > matriceTranslatee (vector<vector<double> > matrice);
vector<vector<double> > comatrice (vector<vector<double> > matrice);
vector<vector<double> > matriceInverse(vector<vector<double> > matrice);

#endif



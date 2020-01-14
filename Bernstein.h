#ifndef _Bernstein_h
#define _Bernstein_h

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
vector<double> canonicToBernstein(Polynome canonic);
vector<vector<double> > PtsDeControle(vector<double> coeffDeBernstein, double imin, double imax);
// vector<double> CastelJau(vector<vector<double> > PtsDeControles, double imin = 0, double imax = 1);
// vector<double> ChangementIntervalle(vector<double> coeffDeBernstein, double a, double b);
// vector<double> Bezier(vector<vector<double> > PtsDeControles, double imin, double imax);
// double Bezier(vector<vector<double> > PtsDeControles, double imin, double imax, double precision, bool inverse, bool signe);
// vector<vector<double> > CastelJau(vector<vector<double> > PtsDeControles, double intMin, double intMax);
double calculate(double u, vector<vector<double> > PtsDeControles, double precision);
// vector<double> returnVector();
vector<double> ChangementIntervalle(vector<double> coeffCanonic, bool inverse, bool signe);
vector<double> CastelJau(vector<vector<double> > PtsDeControles,  double precision,bool inverse, bool signe);



#endif



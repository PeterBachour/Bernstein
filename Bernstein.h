#ifndef _Bernstein_h
#define _Bernstein_h

#include "Polynome.h"
#include "matrice.h"


#include <cmath>
#include <iostream>

vector<double> canonicToBernstein(Polynome canonic);
vector<vector<double> > PtsDeControle(vector<double> coeffDeBernstein);
vector<double> ChangementIntervalle(vector<double> coeffCanonic, bool inverse, bool signe);
vector<double> BezierCurve(vector<vector<double>> ptsDeControles, double precision, double inverse, bool negatif);
vector<double> Bernstein(vector<double> v, double precision);

#endif



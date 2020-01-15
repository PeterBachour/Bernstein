#ifndef _Bernstein_h
#define _Bernstein_h

#include "Polynome.h"
#include "matrice.h"


#include <cmath>
#include <iostream>

vector<double> canonicToBernstein(Polynome canonic);
vector<vector<double> > PtsDeControle(vector<double> coeffDeBernstein, double imin, double imax);
vector<double> ChangementIntervalle(vector<double> coeffCanonic, bool inverse, bool signe);
vector<double> CastelJau(vector<vector<double> > PtsDeControles,  double precision,bool inverse, bool signe);
vector<double> Bernstein(vector<double> v, double precision);

#endif



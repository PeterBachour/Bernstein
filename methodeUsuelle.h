#ifndef _methodeUsuelle_h
#define _methodeUsuelle_h

#include <vector>
#include <cmath>
using namespace std;


vector<double> polynome3(vector<double> coeff);
vector<double> polynome4(vector<double> coeff);
double calculPoly(double polynome[6], int degree, double x);
double newton(double polynome[6], int degree, double x0);
vector<double> polynome5(vector<double> coeff);


#endif



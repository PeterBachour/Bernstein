#ifndef _Polynome_h
#define _Polynome_h

#include <vector>

using namespace std;

class Polynome{
private: 
	vector<double> m_coefficients; //coefficients du polynome, on commence par le degree le plus bas
	int m_degree; //degree du polynome
public:
	Polynome(vector<double> t_coefficients); //constructeur de base
	//getters
	vector<double> getCoefficients();
	int getDegree();
};

#endif
#ifndef _Polynome_h
#define _Polynome_h

#include <vector>

using namespace std;

class Polynome{
private: 
	vector<double> m_coefficients; 
	int m_degree; 
public:
	Polynome(vector<double> t_coefficients); 
	//getters
	vector<double> getCoefficients();
	int getDegree();
};

#endif
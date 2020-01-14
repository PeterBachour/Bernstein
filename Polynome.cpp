#include "Polynome.h"

Polynome::Polynome(vector<double> t_coefficients){
	m_coefficients = t_coefficients;
	m_degree = m_coefficients.size()-1;
}

vector<double> Polynome::getCoefficients(){
	return m_coefficients;
}

int Polynome::getDegree(){
	return m_degree;
}
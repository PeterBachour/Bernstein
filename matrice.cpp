#include "matrice.h"

double factoriel(int val){
	double fact=1;
	for(int i=val; i>=1; i--){
		fact *= i;
	}
	return fact;
}

double coeffBinomial(int k, int n){
	return (factoriel(n))/(factoriel(k)*(factoriel(n-k)));
}

vector<vector<double> > matriceReduite(vector<vector<double> > mat, int ligne, int colonne){
	vector<vector<double> > reduite = mat;

	reduite.erase(reduite.begin()+ligne);

	for(double i=0; i<reduite.size(); i++){
		reduite[i].erase(reduite[i].begin() + colonne);
	}
	
	return reduite;
}

bool estCarre(vector<vector<double> > matrice){
	for(double i=0; i<matrice.size()-1; i++){ //on verifie si la matrice est carre ou pas
		if(matrice[i].size()!=matrice[i+1].size())
			return false;
	}
	return true;
}

vector< vector<double> > getMinimo( vector< vector<double> > src, int I, int J, int ordSrc ) {
  vector< vector<double> > minimo( ordSrc-1, vector<double> (ordSrc-1,0));

  int rowCont = 0;
  for( int i=0; i < ordSrc; i++)
  {
    int colCont = 0;
    if ( i != I ) { 

      for ( int j=0; j < ordSrc; j++)
      { 
        if ( j != J ) { 
          minimo[rowCont][colCont] = src[i][j];
          colCont++; }
      };

      rowCont++; }
  };
  return minimo;
}

double calcDet(vector< vector<double> > src, double ord) {
  if ( ord == 2 ) {

    double mainDiag = src[0][0] * src[1][1];
    double negDiag = src[1][0] * src[0][1];

    return mainDiag - negDiag; }
  
  else {

    double det = 0;
    for( int J = 0; J < ord; J++) 
    {
      vector< vector<double> > min = getMinimo( src, 0, J, ord);

      if ( (J % 2) == 0 ) { det += src[0][J] * calcDet( min, ord-1); }
      else { det -= src[0][J] * calcDet( min, ord-1); }
    };
    // cout << "det" << det << endl;
    return det;
  }
}

double determinant(vector<vector<double> > matrice){
	return calcDet(matrice, matrice.size());
}

vector<vector<double> > matriceTranslatee (vector<vector<double> > matrice){

	vector<vector<double> > transl = matrice;
	for(double i=0; i<matrice.size(); i++){
		for(double j=0; j<matrice.size(); j++){
			transl[j][i] = matrice[i][j];
		}
	}
	return transl;
}

vector<vector<double> > comatrice (vector<vector<double> > matrice){
	vector<vector<double> > comat = matrice;
	for(double i=0; i<matrice.size(); i++){
		for(double j=0; j<matrice.size(); j++){
			comat[i][j]= pow(-1,i+j) *determinant(matriceReduite(matrice, i, j));
		}
	}
	return comat;
}

vector<vector<double> > matriceInverse(vector<vector<double> > matrice){
	double det = determinant(matrice);
	vector<vector<double> > matricecomat = comatrice(matrice);
	vector<vector<double> > matriceT = matriceTranslatee(matricecomat);
	if(det != 0) {
		for(double i=0; i<matriceT.size(); i++){
			for(double j=0; j<matriceT.size(); j++){
				matrice[i][j]= (1/det)*matriceT[i][j];
			}
		}
	}
	return matrice;
}
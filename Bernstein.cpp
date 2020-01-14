#include "Bernstein.h"

// vector<double> my_results;

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

vector<double> canonicToBernstein(Polynome canonic){
	int degree = canonic.getDegree()+1;
	vector<double> res;
	vector<vector<double> > M;

	for(int i=0; i<degree; i++){ //initialise la matrice a 0

		vector<double> v;
		for (int j = 0; j < degree; j++)
			v.push_back(0);
		M.push_back(v);
	}

	for(int i=0; i<degree; i++){ //on ajoute les coefficients 
		for(int j=0; j<degree; j++){
			if(i>=j)
				M[i][j]=coeffBinomial(j,degree-1)*coeffBinomial(i-j,degree-j-1)*pow(-1,i-j);
		}
	}

	M = matriceInverse(M);
	double r = 0;
	vector<double> resultat;
	for(int i=0; i< degree; i++){
		r = 0;
		for(int j=0; j<degree; j++){
			r += M[i][j]* canonic.getCoefficients()[j];
		}
		res.push_back(r);
	}
	return res;
}

vector<vector<double> > PtsDeControle(vector<double> coeffDeBernstein, double imin, double imax){
	double degree = coeffDeBernstein.size()-1;

	double total = (imax - imin)/degree;

	vector<vector<double> > res;
	vector<double> v;
	
	for(int i=0; i<=degree; i++){ 
		v.push_back((imin + (i*total)));
		v.push_back(coeffDeBernstein[i]);
		res.push_back(v);
		v.clear();
	}
	return res;
}

// vector<double> ChangementIntervalle(vector<double> coeffDeBernstein, double a, double b){

// 	double degree = coeffDeBernstein.size()-1;
// 	vector<vector<double> > M;

// 	if(degree == 5)
// 	{
// 		M = {
// 			{b*b*b*b*b, - 5*b*b*b*b*a, 10*b*b*b*a*a, -10*b*b*a*a*a, 5*b*a*a*a*a, -a*a*a*a*a},
// 			{-5*b*b*b*b, 5*b*b*b*b+20*b*b*b*a, -20*b*b*b*a - 30*b*b*a*a, 30*a*a*b*b + 20*a*a*a*b, -20*a*a*a*b - 5*a*a*a*a, 5*a*a*a*a},
// 			{10*b*b*b, -30*b*b*a -20*b*b*b, 10*b*b*b+60*b*b*a+30*b*a*a, -30*a*b*b - 60*a*a*b -10 *a*a*a, 20*a*a*a + 30 *a*a*b, -10*a*a*a},
// 			{-10*b*b, 20*b*a + 30*b*b, -30*b*b-60*b*a - 10*a*a, 30*a*a + 10*b*b +60 *a*b,- 20*b*a - 30 *a*a, 10*a*a},
// 			{5*b, -20*b-5*a, 30*b +20*a, -30*a - 20*b, 20*a + 5*b, -5*a},
// 			{-1, 5, -10, 10, -5, 1}
// 		};
// 	}else if(degree == 4){	
// 		M = {
// 			{b * b * b * b, -4.0 * a * b * b * b, 6.0 * a * a * b * b, -4.0 * a * a * a * b, a * a * a * a},
// 			{ -4.0 * b * b * b, 4.0 * b * b * b + 12.0 * a * b * b, -12.0 * a * b * b - 12.0 * a * a * b, 4.0 * a * a * a + 12.0 * a * a * b, -4.0 * a * a * a},
// 			{6.0 * b * b, -12.0 * b * b - 12.0 * a * b, 6.0 * a * a + 6 * b * b + 12.0 * a * b,  -12.0 * a * a - 12.0 * a * b, 6.0 * a * a},
// 			{ -4.0 * b,  4.0 * a + 12 * b, -12.0 * a - 12.0 * b , 12.0 * a + 4.0 * b, -4.0 * a},
// 			{1,-4,6,-4,1}
// 		};
// 	}
// 	else if(degree == 3) {
// 		M = {
// 			{b*b*b,			-3.0 * b * b*a, 				3.0 * b * a * a , 		 			-a * a * a},
// 			{-3.0 * b * b , 3.0 * b * b + 6.0 * b * a, 		-3.0 * a * a - 6.0 * b * a, 		3.0 * a * a},
// 			{ 3.0 * b,		-6.0 * b - 3.0 * a,		 		3.0 * b + 6.0 * a,  				-3.0 * a },
// 			{ -1,			3.0,							-3.0								,1 }
			
// 		};
// 	}
// 		// for(double i=0; i<M.size(); i++){
// 		// 	for(double j=0; j<M.size(); j++){
// 		// 		cout << M[i][j] << " ";
// 		// 	}
// 		// 	cout << endl;
// 		// }
// 		// 	cout <<"--------------------------------------------------------------------------------"<< endl;


// 	for(double i=0; i<M.size(); i++){
// 		for(double j=0; j<M.size(); j++){
// 			M[i][j]= M[i][j]/(pow((b-a),degree));
// 		}
// 	}

// 		// 	for(double i=0; i<M.size(); i++){
// 		// 	for(double j=0; j<M.size(); j++){
// 		// 		cout << M[i][j] << " ";
// 		// 	}
// 		// 	cout << endl;
// 		// }
// 		// 	cout <<"--------------------------------------------------------------------------------"<< endl;

	
// 	M = matriceInverse(M);

// 	// for(double i=0; i<M.size(); i++){
// 	// 		for(double j=0; j<M.size(); j++){
// 	// 			cout << M[i][j] << " ";
// 	// 		}
// 	// 		cout << endl;
// 	// 	}
// 	// 		cout <<"--------------------------------------------------------------------------------"<< endl;

// 	vector<double> resultat;
// 	double r = 0;
// 	for(int i=0; (unsigned)i< M.size(); i++){
// 		for(int j=0; (unsigned)j<M.size(); j++){
// 			r += M[i][j]*coeffDeBernstein[j];
// 		}
// 		resultat.push_back(r);
// 		r = 0;
// 	}


// 	// for(double i =0;i < resultat.size();i++){
// 	// 	cout << resultat[i] << endl;
// 	// }


// 	return resultat;
// }

// double Bezier(vector<vector<double> > PtsDeControles, double imin, double imax,double precision, bool inverse, bool signe)
// {
// 	double degree = PtsDeControles.size() -1;
// 	vector<vector<double> > D1, D2 ;
// 	double a = imin;
// 	double b = imax;
// 	double moitie = (b+a)/2;
// 	double resA = calculate(a, PtsDeControles, precision);
// 	// double resB = calculate(b, PtsDeControles, precision);
// 	vector<double> ret;

// 	// if(res == 0){
// 	// 	return moitie;
// 	// }

// 	// resultat2.push_back(moitie);
// 	if(degree == 5){
// 		D1 = {
// 			{1,0,0,0,0,0},
// 			{0.5,0.5,0,0,0,0},
// 			{0.25,0.5,0.25,0,0,0},
// 			{0.125,0.375,0.375,0.125,0,0},
// 			{0.0625,0.25,0.375,0.25,0.0625,0},
// 			{0.03125,0.15625,0.3125,0.3125,0.15625,0.03125}
// 		};	 

// 		D2 = {
// 			{0.03125,0.15625,0.3125,0.3125,0.15625,0.03125 },
// 			{0,0.0625,0.25,0.375,0.25,0.0625},
// 			{0,0,0.125,0.375,0.375,0.125},
// 			{0,0,0,0.25,0.5,0.25},
// 			{0,0,0,0,0.5,0.5},
// 			{0,0,0,0,0,1} 
// 		};
// 	}
// 	else if(degree == 4){
// 		D1 = {
// 			{1,0,0,0,0},
// 			{0.5,0.5,0,0,0},
// 			{0.125,0.125,0.25,0,0},
// 			{0.0208333,0.0208333,0.0416667,0.125,0},
// 			{0.00260417,0.00260417,0.00520833,0.015625,0.0625}
// 		};

// 		D2 ={
// 			{0.0625,0.015625,0.00520833,0.00260417,0.00260417},
// 			{0,0.125,0.0416667,0.0208333,0.0208333},
// 			{0,0,0.25,0.125,0.125},
// 			{0,0,0,0.5,0.5},
// 			{0 ,0 ,0 ,0,1}
// 		};
// 	}
// 	else if (degree ==3){
// 		D1 = {
// 			{1,0,0,0}, 
// 			{0.5,0.5,0,0}, 
// 			{0.25,0.5,0.25,0}, 
// 			{0.125,0.375,0.375,0.125} 
// 		};

// 		D2 ={
// 			{0.125,0.375,0.375,0.125},
// 			{0,0.25,0.5,0.25},
// 			{0,0,0.5,0.5},
// 			{0 ,0 ,0 ,1}
// 		};
// 	}


// 	// double yMAX = PtsDeControles[degree][1];
// 	// double yMIN = PtsDeControles[0][1];
// 	// cout << yMAX << "\t\t\t\t" << yMIN << "\t\t\t\t"  << a <<  "\t\t\t\t" << b << endl;
// 	// cout << "------------------------------------------------------------------------------------------" << endl;

// 	vector<vector<double> > PtsDeControles1;
// 	vector<vector<double> > PtsDeControles2;

// 	double r1 = 0;
// 	double r2 = 0;
// 	double r3 = 0;
// 	double r4 = 0;

// 	for(double i=0; i< D1.size(); i++){
// 		vector<double> resultat;
// 		vector<double> resultat1;
// 		for(double j=0; j<D1.size(); j++){

// 			r1 += D1[i][j]*PtsDeControles[j][0];
// 			r2 += D1[i][j]*PtsDeControles[j][1];
// 			r3 += D2[i][j]*PtsDeControles[j][0];
// 			r4 += D2[i][j]*PtsDeControles[j][1];

// 		}
// 		// cout << r1 << "  " << r2 << "  " << endl;
// 		// cout << r3 << "  " << r4 << "  " << endl; 
// 		resultat.push_back(r1);
// 		resultat.push_back(r2);
// 		resultat1.push_back(r3);
// 		resultat1.push_back(r4);
// 		PtsDeControles1.push_back(resultat);
// 		PtsDeControles2.push_back(resultat1);
// 		r1 = 0;
// 		r2 = 0;
// 		r3 = 0;
// 		r4 = 0;
// 	}

// 	double yMAX1 = PtsDeControles1[degree][1];
// 	double yMIN1 = PtsDeControles1[0][1];

// 	double produit1 = yMAX1*yMIN1;
// 	// double produit = yMAX*yMIN;

// 	// cout << yMAX1 << "\t\t\t\t" << yMIN1 << "\t\t\t\t"  << a <<  "\t\t\t\t" << b << endl;
// 	// cout << "------------------------------------------------------------------------------------------" << endl;

// 	double yMAX2 = PtsDeControles2[degree][1];
// 	double yMIN2 = PtsDeControles2[0][1];

// 	// cout << yMAX2 << "\t\t\t\t" << yMIN2 << "\t\t\t\t"  << a <<  "\t\t\t\t" << b << endl;
// 	// cout << "------------------------------------------------------------------------------------------" << endl;

// 	double produit2 = yMAX2*yMIN2;

// 	// if((produit1 == 0 || produit2 == 0 )&& moitie == 0){
// 	// 	my_results.push_back(0);
// 	// 	// cout << "DONEEE " << 0 << endl << endl;
// 	// }
// 	if(resA == 0){
// 		if(a == 0 && inverse && !signe)
// 		{
// 			a = 1;
// 		}
// 		if(a == 0 && inverse && signe)
// 		{
// 			a = -1;
// 		}
// 		if(a != 0 && inverse && !signe){
// 			a=1/a;
// 		}
// 		if(a != 0 && inverse && !signe){
// 			a=-1/a;
// 		}
// 		// cout << "DONEEE a " << a << endl << endl;
// 		my_results.push_back(a);
// 		return a;
// 		// cout << "DONEEE " << moitie << endl << endl;
// 	}
// 	// if(resB == 0){
// 	// 	if(b == 0 && inverse)
// 	// 	{
// 	// 		b = 0;
// 	// 	}
// 	// 	else if(inverse){
// 	// 		b=1/b;
// 	// 	}
// 	// 	cout << "DONEEE b " << b << endl << endl;
// 	// 	my_results.push_back(b);
// 	// 	return b;
// 	// 	// cout << "DONEEE " << moitie << endl << endl;
// 	// }


// 	if(produit1 < 0){
// 		return Bezier(PtsDeControles1, a, moitie, precision, inverse, signe);
// 	}

// 	if(produit2 < 0)
// 		return Bezier(PtsDeControles2, moitie, b, precision, inverse, signe);	
// }

// vector<double> returnVector(){
// 	return my_results;
// } 

vector<double> CastelJau(vector<vector<double> > PtsDeControles,  double precision,bool inverse, bool negatif){
	vector<double> res;
	double x = 0 , y=0;
	double size = PtsDeControles.size()-1;
	double u = 0.0;
	double imax = 1;
	while(u<=imax){
		for(int i = 0; i<= size; i++){
			y += coeffBinomial(i,size) * pow( (1-u) , size-i) * pow(u,i) * PtsDeControles[size-i][1];
		}
		if(y <= precision && y >= -precision){
			for(int i = 0; i< size; i++){
				x += coeffBinomial(i,size)*pow((1-u), size-i)*pow(u,i)*PtsDeControles[size-i][0];
			}	
			if(x == 0 && inverse && !negatif)
			{
				x = 1;
			}
			if(x == 0 && inverse && negatif)
			{
				x = -1;
			}
			if(x != 0 && inverse){
				x=1/x;
			}
			if(negatif){
				x = - x;
			}
			// cout << "DONEEE a " << a << endl << endl;
			if(x <= 0.0001 && x >= -0.0001){
				x =0;
			}
			u += 0.005;
			res.push_back(x);
		}
		y=0.0;
		x=0.0;
		u += 0.00001;
	}	
	return res;
}

double calculate(double u, vector<vector<double> > PtsDeControles, double precision){
	double y = 0;
	double size = PtsDeControles.size()-1;

	for(int i = 0; i<= size; i++){
		y += coeffBinomial(i,size) * pow( (1-u), size-i) * pow(u,i) * PtsDeControles[size-i][1];
	}
	if(y <= precision && y >= -precision){
		y = 0;
	}
	return y;
}


vector<double> ChangementIntervalle(vector<double> coeffCanonic, bool inverse, bool signe){ //on passe de [0, 1] a [-1 0], [1, inf] ou [-inf, -1]
	vector<double> newcoeffCanonic = coeffCanonic;

	if(inverse){
		for(unsigned i=0; i<coeffCanonic.size(); i++){
			newcoeffCanonic[i] = coeffCanonic[coeffCanonic.size()-i-1];
		}
	}
	if(signe){
		for(unsigned i=1; i<coeffCanonic.size(); i++){
			if(i%2 == 1)
				newcoeffCanonic[i] = -newcoeffCanonic[i];
		}
	}
	return newcoeffCanonic;
}





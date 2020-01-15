#include "Bernstein.h"

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

vector<double> Bernstein(vector<double> v, double precision){
	vector<double> res;
	vector<double> CoeffDeBernstein = canonicToBernstein(ChangementIntervalle(v, false, false));
    vector<vector<double> > PtsdeControles = PtsDeControle(CoeffDeBernstein, 0, 1); 
	res = CastelJau(PtsdeControles, precision, false, false);


    vector<double> CoeffDeBernstein1 = canonicToBernstein(ChangementIntervalle(v, true, false));
    vector<vector<double> > PtsdeControles1 = PtsDeControle(CoeffDeBernstein1, 0, 1); 
	vector<double> res1 = CastelJau(PtsdeControles1, precision, true, false);
	res.insert(res.end(), res1.begin(), res1.end());

    
    vector<double> CoeffDeBernstein2 = canonicToBernstein(ChangementIntervalle(v, false, true));
    vector<vector<double> > PtsdeControles2 = PtsDeControle(CoeffDeBernstein2, 0, 1); 
	vector<double> res2 = CastelJau(PtsdeControles2, precision, false, true);
	res.insert(res.end(), res2.begin(), res2.end());


    vector<double> CoeffDeBernstein3 = canonicToBernstein(ChangementIntervalle(v, true, true));
    vector<vector<double> > PtsdeControles3 = PtsDeControle(CoeffDeBernstein3, 0, 1); 
	vector<double> res3 = CastelJau(PtsdeControles3, precision, true, true);
	res.insert(res.end(), res3.begin(), res3.end());

	sort( res.begin(), res.end() );
	res.erase( unique( res.begin(), res.end() ), res
		.end() );


	return res;
}
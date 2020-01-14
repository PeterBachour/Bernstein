/********************************************************/
/*                    projetMathbernstein.cc            */
/********************************************************/
/********************************************************/ 
/*                    PeterBACHOUR                      */

#include <stdlib.h>
#define Pi 3.141592654
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

#include "Polynome.h"
#include "Bernstein.h"

vector<double> polynome3(double a,double b,double c, double d);
vector<double> polynome4(double a,double b,double c, double d, double e);

int main(){
	vector<double> v;
    v.push_back(-6);
    v.push_back(3);
    v.push_back(9);
	v.push_back(-14);
	v.push_back(-2);

	Polynome p(v);

	vector<double> CoeffDeBernstein = canonicToBernstein(p);
    vector<vector<double> > PtsdeControles = PtsDeControle(CoeffDeBernstein, 0, 1); 

    // for(double i=0; i<PtsdeControles.size(); i++){
    //  for(double j=0; j<2; j++){
    //      cout << PtsdeControles[i][j] << " ";
    //  }
    //  cout << endl;
    // }

    // cout 	vector<vector<double> > PtsdeControles1 = PtsDeControle(CoeffDeBernsteinIntervalle, 0, 1); 

	// for(double i=0; i<PtsdeControles.size(); i++){
	// 	for(double j=0; j<2; j++){
	// 		cout << PtsdeControles[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
    double precision = 0.0001;

	vector<double> res = CastelJau(PtsdeControles, precision, false, false);


    // Bezier(PtsdeControles, 0,1, 0.00000001, false, false);

    // vector<double> res = returnVector();
    cout << "Il y a " << res.size() << " solutions dans [0,1] :" << endl;
    for(double i = 0; i < res.size();i++)
    {
        cout << "x" << i+1 << " = " << res[i] << endl;
    }
	cout <<endl<< endl;


    vector<double> CoeffDeBernstein1 = canonicToBernstein(ChangementIntervalle(v, true, false));
    vector<vector<double> > PtsdeControles1 = PtsDeControle(CoeffDeBernstein1, 0, 1); 
    vector<double> res1 = CastelJau(PtsdeControles1, precision, true, false);

    // Bezier(PtsdeControles1, 0,1, 0.00000001, true, false);
    
    vector<double> CoeffDeBernstein2 = canonicToBernstein(ChangementIntervalle(v, false, true));

    

    vector<vector<double> > PtsdeControles2 = PtsDeControle(CoeffDeBernstein2, 0, 1); 
    vector<double> res2 = CastelJau(PtsdeControles2, precision, false, true);

    // Bezier(PtsdeControles2, 0,1, 0.00000001, false, true);

    vector<double> CoeffDeBernstein3 = canonicToBernstein(ChangementIntervalle(v, true, true));

    

    vector<vector<double> > PtsdeControles3 = PtsDeControle(CoeffDeBernstein3, 0, 1); 
    vector<double> res3 = CastelJau(PtsdeControles3, precision, true, true);
    // Bezier(PtsdeControles3, 0,1, 0.00000001, true, true);

    // vector<double> res = returnVector();
    // res = returnVector();
    cout << "Il y a " << res1.size() << " solutions dans [1,+inf[:" << endl;
    for(double i = 0; i < res1.size();i++)
    {
        cout << "x" << i+1 << " = " << res1[i] << endl;
    }
    cout <<endl<< endl;
    cout << "Il y a " << res2.size() << " solutions dans [-1,0] :" << endl;
    for(double i = 0; i < ChangementIntervalle(v, true, false).size();i++)
    {
        cout << "coeff" << i+1 << " = " << ChangementIntervalle(v, false, true)[i] << endl;
    }
    cout <<endl<< endl;
    for(double i = 0; i < res2.size();i++)
    {
        cout << "x" << i+1 << " = " << res2[i] << endl;
    }
    cout <<endl<< endl;
    cout << "Il y a " << res3.size() << " solutions dans [-inf, -1] :" << endl;
    for(double i = 0; i < ChangementIntervalle(v, true, true).size();i++)
    {
        cout << "coeff" << i+1 << " = " << ChangementIntervalle(v, true, true)[i] << endl;
    }
    cout <<endl<< endl;
    for(double i = 0; i < res3.size();i++)
    {
        cout << "x" << i+1 << " = " << res3[i] << endl;
    }
    cout <<endl<< endl;



	double x,y,z,t,o;
    string choice;

    cout<<"Bonjour et bon travail"<<endl;
    cout<< endl;
    cout<< endl;
    cout << "Please choose what method you want to use:" << endl;
    cout << "1 - Méthode de résolution d'équation polynomial de degré 3." << endl;
    cout << "2 - Méthode de résolution d'équation polynomial de degré 4." << endl;
    cout << "3 - Méthode de Bernstein avec le degré 3." << endl;
    cout << "4 - Méthode de Bernstein avec le degré 4." << endl;
    cout << "5 - Méthode de Bernstein avec le degré 5." << endl;
    cin>>choice;
    if(choice == "1"){
        cout  << "Vous avez choisi de résoudre une équation polynomial de degré 3 donc enter your coefficient : "<<endl;
        cout << "a = ";
        cin>>x;
        cout << "b = ";
        cin>>y;
        cout << "c = ";
        cin>>z;
        cout << "d = ";
        cin>>t;
        vector<double> res = polynome3(x,y, z, t); 
        if(res.size() != 0) {

            cout << "Il y a " << res.size() << " solutions dans R :" << endl;
            for(double i = 0; i < res.size();i++)
            {
                cout << "x" << i+1 << " = " << res[i] << endl;
            }
        }
        else{
            cout << "Pas de solution dans R" << endl;
        }
    }
    else if (choice == "2"){
        cout  <<"Vous avez choisi de résoudre une équation polynomial de degré 4 donc enter your coefficient : "<<endl;
        cout << "a = ";
        cin>>x;
        cout << "b = ";
        cin>>y;
        cout << "c = ";
        cin>>z;
        cout << "d = ";
        cin>>t;
        cout << "e = ";
        cin>>o;
        vector<double> res = polynome4(x,y, z, t,o);
        if(res.size() != 0) {
            cout << "Il y a " << res.size() << " solutions dans R :" << endl;
            for(double i = 0; i < res.size();i++)
            {
                cout << "x" << i+1 << " = " << res[i] << endl;
            }
        }
        else{
            cout << "Pas de solution dans R" << endl;
        }
    }
	return 0;
}

vector<double> polynome3(double a,double b,double c, double d)
{   
    std::vector<double> result;
    b /= a;
    c /= a;
    d /= a;
    
    double disc, q, r, dum1, s, t, term1, r13;
    q = (3.0*c - (b*b))/9.0;
    r = -(27.0*d) + b*(9.0*c - 2.0*(b*b));
    r /= 54.0;
    disc = q*q*q + r*r;
    term1 = (b/3.0);
    
    double x1, x2, x3;

    if (disc > 0)   // One root real, two are complex
    {
        s = r + sqrt(disc);
        s = s<0 ? -cbrt(-s) : cbrt(s);
        t = r - sqrt(disc);
        t = t<0 ? -cbrt(-t) : cbrt(t);
        x1 = -term1 + s + t;
        result.push_back(x1);
        return result;
    } 
    // The remaining options are all real
    else if (disc == 0)  // All roots real, at least two are equal.
    { 
        r13 = r<0 ? -cbrt(-r) : cbrt(r);
        x1 = -term1 + 2.0*r13;
        x3 = x2 = -(r13 + term1);
    }
    // Only option left is that all roots are real and unequal (to get here, q < 0)
    else
    {
        q = -q;
        dum1 = q*q*q;
        dum1 = acos(r/sqrt(dum1));
        r13 = 2.0*sqrt(q);
        x1 = -term1 + r13*cos(dum1/3.0);
        x2 = -term1 + r13*cos((dum1 + 2.0*M_PI)/3.0);
        x3 = -term1 + r13*cos((dum1 + 4.0*M_PI)/3.0);
    }
    
    result.push_back(x1);
    result.push_back(x2);
    result.push_back(x3);
    return result;
}

vector<double> polynome4(double a,double b,double c, double d, double e){
   
    vector<double> result;
    double x1,x2,x3,x4;

    if(a == 0) return polynome3(b,c,d,e);

    double A = (-3*b*b)/(8*a*a) + c/a;
    double B = pow(b,3)/(8*a*a*a) - (b*c)/(2*a*a) + d/a;
    double C = - (3*b*b*b*b)/(256*a*a*a*a) + (c*b*b)/(16*a*a*a) - (d*b)/(4*a*a) + e/a;

    if(B == 0){
        double delta = A*A - 4*C;

        if(delta>0)
        {
            double Y1=(-1*A+sqrt(delta))/2;
            double Y2=(-1*A-sqrt(delta))/2;

            if(Y1 > 0){
                
                x1 = sqrt(Y1) - ((b)/(4*a));
                x2 = -sqrt(Y1) - ((b)/(4*a));

            } else if (Y1 == 0){
                
                x1=x2 = - ((b)/(4*a));
            
            }

            if (Y2 > 0)
            {
                x3 = sqrt(Y2) - ((b)/(4*a));
                x4 = -sqrt(Y2) - ((b)/(4*a));
            
            } else if (Y2 == 0){
                
                x3=x4 = - ((b)/(4*a));
            
            }

            if (Y1 < 0 && Y2 < 0){
                cout << "Pas de solution dans R. " << endl;
            }

            result.push_back(x1);
            result.push_back(x2);
            result.push_back(x3);
            result.push_back(x4);

            return result;
            // 4 solutions pour x
        }
        else if(delta==0)
        {   
            double Y = -A/2;

            if( Y > 0){
                x1 = x2 = sqrt(Y) - ((b)/(4*a));
                x3 = x4 = -sqrt(Y) - ((b)/(4*a));
            } else if (Y == 0) {
                x1 = x2 = x3 = x4 = - ((b)/(4*a));
            }
            else {
                cout << "Pas de solution dans R. " << endl;
            }
            result.push_back(x1);
            result.push_back(x2);
            result.push_back(x3);
            result.push_back(x4);

            return result;
            // 2 solutions pour x
        }
        else {
            cout << "Pas de solution dans R. " << endl;
        }
    }

    if (B != 0){
        double lambda = polynome3(8,-4*A, -8*C, 4*A*C - B*B)[0];

        double x1 = (-sqrt(2*lambda-A) + sqrt(-2*lambda - A + (2*B)/(sqrt(2*lambda - A))))/2 - ((b)/(4*a));
        double x2 = (-sqrt(2*lambda-A) - sqrt(-2*lambda - A + (2*B)/(sqrt(2*lambda - A))))/2 - ((b)/(4*a));
        double x3 = (sqrt(2*lambda-A) + sqrt(-2*lambda - A - (2*B)/(sqrt(2*lambda - A))))/2 - ((b)/(4*a));
        double x4 = (sqrt(2*lambda-A) - sqrt(-2*lambda - A - (2*B)/(sqrt(2*lambda - A))))/2 - ((b)/(4*a));
        
        if(!isnan(x1))
            result.push_back(x1);
        if(!isnan(x2))
            result.push_back(x2);
        if(!isnan(x3))
            result.push_back(x3);
        if(!isnan(x4))
            result.push_back(x4);
    }
    return result;
}

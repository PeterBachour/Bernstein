/********************************************************/
/*                    projetMathbernstein.cc            */
/********************************************************/
/********************************************************/ 
/*                    PeterBACHOUR                      */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Bernstein.h"
#include "methodeUsuelle.h"

int main(){

	cout << endl;
	cout << endl;
    cout << "Le but de ce code est la résolution, dans R, d'équations polynomiales de degré 3 à 5 en comparant" << endl <<"le solveur de Bernstein aux méthodes usuelles." << endl;
    cout << "Code conçu par BACHOUR Peter et ATANGANA Oliver." << endl;
    double precision = 0;
	double a =0,b=0,c=0,d=0,e=0,f=0;
    string degree;
    string choice;
    vector<double> resUsuelle;
    vector<double> resBernstein;
    bool undo = true;
    bool first = true;
    bool tolerance = true;
    bool testing = true;
    bool otherTest = true;

    cout << endl;
    while(testing){
    	undo = true;
    	first = true;
    	tolerance = true;
    	testing = false;
    	otherTest = true;
        cout << "Veuillez choisir parmi les deux options ci-dessous:" << endl;
        cout << "1- Exemple pertinent." << endl;
        cout << "2- Tester le code à l'aide d'une saisie au clavier." << endl;
        cout << endl;
        cin >> choice;
        cout << endl;
        int d1 = choice.compare("1"); 
        int d2 = choice.compare("2"); 
        while (d1 != 0 && d2 != 0){
            cout << endl;
            cout << "Veuillez choisir une option s'il vous plait:" << endl;
            cout << "1- Exemple pertinent." << endl;
        	cout << "2- Tester le code à l'aide d'une saisie au clavier." << endl;
            cin >> degree;
            d1 = degree.compare("1"); 
            d2 = degree.compare("2");  
        }
        if(d1 == 0){
            while(otherTest)
            {
                otherTest = false;
                cout << "Vous avez choisi le test d'exemple pertinent." << endl;
                cout << "1- Vous voulez tester avec des exemples de degré 3" << endl;
                cout << "2- Vous voulez tester avec des exemples de degré 4" << endl;
                cout << "3- Vous voulez tester avec des exemples de degré 5" << endl;
                cout << endl;
                cin>>choice;
                cout << endl;
                int t1 = choice.compare("1"); 
                int t2 = choice.compare("2"); 
                int t3 = choice.compare("3"); 

                while (t1 != 0 && t2 != 0 && t3 != 0){
		            cout << endl;
		            cout << "Veuillez choisir une option s'il vous plait:" << endl;
	                cout << "1- Vous voulez tester avec des exemples de degré 3" << endl;
	                cout << "2- Vous voulez tester avec des exemples de degré 4" << endl;
	                cout << "3- Vous voulez tester avec des exemples de degré 5" << endl;
		            cin >> choice;
	                t1 = choice.compare("1"); 
					t2 = choice.compare("2"); 
	                t3 = choice.compare("3");  
	        	}
                if(t1 == 0){
                    cout << "--> Exemple de degré 3 numero 1: " << endl;
                    cout << endl;
                    double a = -1;
                    double b = 8;
                    double c = 1;
                    double d = -1;
                    double prec = 0.001;
                    cout << "L'équation est de la forme: f(x)= " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << ". " << endl;
                    cout << "Résolution de f(x)=0 dans R avec une approximation de " << prec << "." << endl;
                    cout << endl;

                    vector<double> v;
                    v.push_back(d);
                    v.push_back(c);
                    v.push_back(b);
                    v.push_back(a);

                    resUsuelle = polynome3(v); 
                    int size = resUsuelle.size();
                    cout << "Il y a " << size << " solution(s) dans R pour votre équation." << endl;
                    cout << endl;
                    resBernstein = Bernstein(v, prec);
                    if(resBernstein.size() != 0){
                        cout << "Voici les solutions dans R avec la méthode usuelle:" << endl;
                        for(int i = 0; i < size ;i++)
                        {
                            cout << "x" << i+1 << " = " << resUsuelle[i] << endl;
                        }
                        cout << endl;
                        cout << "Voici les solutions dans R avec la méthode de Bernstein:" << endl;
                        for(int i = 0; i < size;i++)
                        {
                            cout << "x" << i+1 << " = " << resBernstein[i] << endl;
                        }
                    }
                    else {
                        cout << "Pas de solution dans R." << endl;
                    }
                    cout << endl << endl;
                    cout << "--> Exemple de degré 3 numero 2: " << endl;
                    cout << endl;
                    a = 1;
                    b = 2;
                    c = 3;
                    d = 4;
                    prec = 0.0001;
                    cout << "L'équation est de la forme: f(x)= " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << ". " << endl;
                    cout << "Résolution de f(x)=0 dans R avec une approximation de " << prec << "." << endl;
                    cout << endl;

                    vector<double> v1;
                    v1.push_back(d);
                    v1.push_back(c);
                    v1.push_back(b);
                    v1.push_back(a);

                    resUsuelle = polynome3(v1); 
                    size = resUsuelle.size();
                    cout << "Il y a " << size << " solution(s) dans R pour votre équation." << endl;
                    cout << endl;
                    resBernstein = Bernstein(v1, prec);
                    if(resBernstein.size() != 0){
                        cout << "Voici les solutions dans R avec la méthode usuelle:" << endl;
                        for(int i = 0; i < size;i++)
                        {
                            cout << "x" << i+1 << " = " << resUsuelle[i] << endl;
                        }
                        cout << endl;
                        cout << "Voici les solutions dans R avec la méthode de Bernstein:" << endl;
                        for(int i = 0; i < size;i++)
                        {
                            cout << "x" << i+1 << " = " << resBernstein[i] << endl;
                        }
                    }
                    else {
                        cout << "Pas de solution dans R." << endl;
                    }
                }
                if(t2 == 0){
                    cout << "--> Exemple de degré 4 numero 1: " << endl;
                    cout << endl;
                    double a = -1;
                    double b = 2;
                    double c = 3;
                    double d = -4;
                    double e = -0.5;
                    double prec = 0.001;
                    cout << "Votre équation est de la forme: f(x)= " << a << "x^4 + " << b << "x^3 + " << c << "x^2 + " << d << "x + " << e << ". " << endl;
                    cout << "Résolution de f(x)=0 dans R avec une approximation de " << prec << "." << endl;
                    cout << endl;

                    vector<double> v;
                    v.push_back(e);
                    v.push_back(d);
                    v.push_back(c);
                    v.push_back(b);
                    v.push_back(a);

                    resUsuelle = polynome4(v); 
                    int size = resUsuelle.size();
                    cout << "Il y a " << size << " solution(s) dans R pour votre équation." << endl;
                    cout << endl;
                    resBernstein = Bernstein(v, prec);
                    if(resBernstein.size() != 0){
                        cout << "Voici les solutions dans R avec la méthode usuelle:" << endl;
                        for(int i = 0; i < size ;i++)
                        {
                            cout << "x" << i+1 << " = " << resUsuelle[i] << endl;
                        }
                        cout << endl;
                        cout << "Voici les solutions dans R avec la méthode de Bernstein:" << endl;
                        for(int i = 0; i < size;i++)
                        {
                            cout << "x" << i+1 << " = " << resBernstein[i] << endl;
                        }
                    }
                    else {
                        cout << "Pas de solution dans R." << endl;
                    }
                    cout << endl << endl;
                    cout << "--> Exemple de degré 4 numero 2: " << endl;
                    cout << endl;
                    a = 1;
                    b = 8;
                    c = 3;
                    d = 9;
                    e = -5;
                    prec = 0.0001;
                    cout << "Votre équation est de la forme: f(x)= " << a << "x^4 + " << b << "x^3 + " << c << "x^2 + " << d << "x + " << e << ". " << endl;
                    cout << "Résolution de f(x)=0 dans R avec une approximation de " << prec << "." << endl;
                    cout << endl;

                    vector<double> v1;
                    v1.push_back(e);
                    v1.push_back(d);
                    v1.push_back(c);
                    v1.push_back(b);
                    v1.push_back(a);

                    resUsuelle = polynome4(v1); 
                    size = resUsuelle.size();
                    cout << "Il y a " << size << " solution(s) dans R pour votre équation." << endl;
                    cout << endl;
                    resBernstein = Bernstein(v1, prec);
                    if(resBernstein.size() != 0){
                        cout << "Voici les solutions dans R avec la méthode usuelle:" << endl;
                        for(int i = 0; i < size;i++)
                        {
                            cout << "x" << i+1 << " = " << resUsuelle[i] << endl;
                        }
                        cout << endl;
                        cout << "Voici les solutions dans R avec la méthode de Bernstein:" << endl;
                        for(int i = 0; i < size;i++)
                        {
                            cout << "x" << i+1 << " = " << resBernstein[i] << endl;
                        }
                    }
                    else {
                        cout << "Pas de solution dans R." << endl;
                    }
                }
                if(t3 == 0){
                    cout << "--> Exemple de degré 5 numero 1: " << endl;
                    cout << endl;
                    double a = -2;
                    double b = 2;
                    double c = 5;
                    double d = -8;
                    double e = 9;
                    double f = 3;
                    double prec = 0.001;
                    cout << "Votre équation est de la forme: f(x)= " << a << "x^5 + " << b << "x^4 + " << c << "x^3 + " << d << "x^2 + " << e << "x + " << f << ". " << endl;
                    cout << "Résolution de f(x)=0 dans R avec une approximation de " << prec << "." << endl;
                    cout << endl;

                    vector<double> v;
                    v.push_back(f);
                    v.push_back(e);
                    v.push_back(d);
                    v.push_back(c);
                    v.push_back(b);
                    v.push_back(a);

                    resUsuelle = polynome5(v); 
                    int size = resUsuelle.size();
                    cout << "Il y a " << size << " solution(s) dans R pour votre équation." << endl;
                    cout << endl;
                    resBernstein = Bernstein(v, prec);
                    if(resBernstein.size() != 0){
                        cout << "Voici les solutions dans R avec la méthode usuelle:" << endl;
                        for(int i = 0; i < size;i++)
                        {
                            cout << "x" << i+1 << " = " << resUsuelle[i] << endl;
                        }
                        cout << endl;
                        cout << "Voici les solutions dans R avec la méthode de Bernstein:" << endl;
                        for(int i = 0; i < size;i++)
                        {
                            cout << "x" << i+1 << " = " << resBernstein[i] << endl;
                        }
                    }
                    else {
                        cout << "Pas de solution dans R." << endl;
                    }
                    cout << endl << endl;
                    cout << "--> Exemple de degré 5 numero 2: " << endl;
                    cout << endl;
                    a = 1;
                    b = -4;
                    c = 2;
                    d = 2;
                    e = -4;
                    f = 6;
                    prec = 0.0001;
                    cout << "Votre équation est de la forme: f(x)= " << a << "x^5 + " << b << "x^4 + " << c << "x^3 + " << d << "x^2 + " << e << "x + " << f << ". " << endl;
                    cout << "Résolution de f(x)=0 dans R avec une approximation de " << prec << "." << endl;
                    cout << endl;

                    vector<double> v1;
                    v1.push_back(f);
                    v1.push_back(e);
                    v1.push_back(d);
                    v1.push_back(c);
                    v1.push_back(b);
                    v1.push_back(a);

                    resUsuelle = polynome5(v1); 
                    size = resUsuelle.size();
                    cout << "Il y a " << size << " solution(s) dans R pour votre équation." << endl;
                    cout << endl;
                    resBernstein = Bernstein(v1, prec);
                    if(resBernstein.size() != 0){
                        cout << "Voici les solutions dans R avec la méthode usuelle:" << endl;
                        for(int i = 0; i < size;i++)
                        {
                            cout << "x" << i+1 << " = " << resUsuelle[i] << endl;
                        }
                        cout << endl;
                        cout << "Voici les solutions dans R avec la méthode de Bernstein:" << endl;
                        for(int i = 0; i < size;i++)
                        {
                            cout << "x" << i+1 << " = " << resBernstein[i] << endl;
                        }
                    }
                    else {
                        cout << "Pas de solution dans R." << endl;
                    }
                }
                cout << endl;
                cout << "Est ce que vous souhaitez tester un autre degré? (o/n)" << endl;
                cin>>choice;
                if(choice == "o")
                    otherTest = true;
                else{
                    otherTest = false;
                }
            }
        }
        if(d2 ==0)
            while(first){
            first = false;
            undo = true;
            tolerance = true;
            cout << "Vous avez choisi la saisie au clavier." << endl;
            cout << "Veuillez saisir le degré du pôlynome que vous souhaitez résoudre:" << endl;
            cout << endl;
            cin >> degree;
            cout << endl;

            int d3 = degree.compare("3"); 
            int d4 = degree.compare("4"); 
            int d5 = degree.compare("5"); 
            while (d3 != 0 && d4 != 0 && d5 != 0){
                cout << endl;
                cout << "Veuillez saisir un degré entre 3 et 5:" << endl;
                cin >> degree;
                d3 = degree.compare("3"); 
                d4 = degree.compare("4"); 
                d5 = degree.compare("5"); 
            }
            if(d3 == 0){
                while(undo){
                    tolerance = true;
                    cout  << "Vous avez choisi de résoudre une équation polynomial de degré 3 donc entrez les coefficients du pôlynome : "<<endl;
                    cout << "a = ";
                    cin>>a;
                    cout << "b = ";
                    cin>>b;
                    cout << "c = ";
                    cin>>c;
                    cout << "d = ";
                    cin>>d;

                    cout << "Votre équation est de la forme: f(x)= " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << ". " << endl;
                    cout << "Vous souhaitez résoudre f(x)=0 dans R." << endl;
                    cout << endl;

                    vector<double> v;
                    v.push_back(d);
                    v.push_back(c);
                    v.push_back(b);
                    v.push_back(a);

                    while(tolerance){
                        resUsuelle = polynome3(v);  
                        int size = resUsuelle.size();
                        cout << "Il y a " << size << " solution(s) dans R pour votre équation." << endl;
                        cout << endl;

                        cout << endl << "Veuillez saisir la tolérance d'erreur que vous souhaitez:" << endl;
                        cin>>precision;
                        cout << "Votre tolérance d'erreur est: " << precision << endl;
                        cout << endl;
                        resBernstein = Bernstein(v, precision);

                        if(resBernstein.size() != 0){
                            cout << "Voici les solutions dans R avec la méthode usuelle:" << endl;
                            for(int i = 0; i < size;i++)
                            {
                                cout << "x" << i+1 << " = " << resUsuelle[i] << endl;
                            }
                            cout << endl;
                            cout << "Voici les solutions dans R avec la méthode de Bernstein:" << endl;
                            for(int i = 0; i < size;i++)
                            {
                                cout << "x" << i+1 << " = " << resBernstein[i] << endl;
                            }
                        }
                        else {
                            cout << "Pas de solution dans R." << endl;
                        }
                        cout << endl;
                        cout << "Est ce que vous souhaitez changer la tolérance d'erreur? (o/n)" << endl;
                        cin>>choice;
                        if(choice == "o")
                            tolerance = true;
                        else{
                            tolerance = false;
                        }
                    }
                    cout << "Est ce que vous souhaitez changer vos coefficients? (o/n)" << endl;
                    cin>>choice;
                    if(choice == "o")
                        undo = true;
                    else{
                        undo = false;
                    }
                }
                cout << endl;
                cout << "Est ce que vous souhaitez changer de degré? (o/n)" << endl;
                cin>>choice;
                if(choice == "o")
                    first = true;
                else{
                    first = false;
                }
            }
            if(d4 == 0){
                while(undo){
                    tolerance = true;
                    cout  << "Vous avez choisi de résoudre une équation polynomial de degré 3 donc entrez les coefficients du pôlynome : "<<endl;
                    cout << "a = ";
                    cin>>a;
                    cout << "b = ";
                    cin>>b;
                    cout << "c = ";
                    cin>>c;
                    cout << "d = ";
                    cin>>d;
                    cout << "e = ";
                    cin>>e;
                    cout << "Votre équation est de la forme: f(x)= " << a << "x^4 + " << b << "x^3 + " << c << "x^2 + " << d << "x + " << e << ". " << endl;
                    cout << "Vous souhaitez résoudre f(x)=0 dans R." << endl;
                    cout << endl;
                    vector<double> v;
                    v.push_back(e);
                    v.push_back(d);
                    v.push_back(c);
                    v.push_back(b);
                    v.push_back(a);

                    while(tolerance){
                        resUsuelle = polynome4(v); 
                        int size = resUsuelle.size();
                        cout << "Il y a " << size << " solution(s) dans R pour votre équation." << endl;
                        cout << endl;

                        cout << endl << "Veuillez saisir la tolérance d'erreur que vous souhaitez:" << endl;
                        cin>>precision;
                        cout << "Votre tolérance d'erreur est: " << precision << endl;
                        cout << endl;
                        resBernstein = Bernstein(v, precision);

                        if(resBernstein.size() != 0){
                            cout << "Voici les solutions dans R avec la méthode usuelle:" << endl;
                            for(int i = 0; i < size;i++)
                            {
                                cout << "x" << i+1 << " = " << resUsuelle[i] << endl;
                            }
                            cout << endl;
                            cout << "Voici les solutions dans R avec la méthode de Bernstein:" << endl;
                            for(int i = 0; i < size;i++)
                            {
                                cout << "x" << i+1 << " = " << resBernstein[i] << endl;
                            }
                        }
                        else {
                            cout << "Pas de solution dans R." << endl;
                        }
                        cout << endl;
                        cout << "Est ce que vous souhaitez changer la tolérance d'erreur? (o/n)" << endl;
                        cin>>choice;
                        if(choice == "o")
                            tolerance = true;
                        else{
                            tolerance = false;
                        }
                    }
                    cout << "Est ce que vous souhaitez changer vos coefficients? (o/n)" << endl;
                    cin>>choice;
                    if(choice == "o")
                        undo = true;
                    else{
                        undo = false;
                    }
                }
                cout << endl;
                cout << "Est ce que vous souhaitez changer de degré? (o/n)" << endl;
                cin>>choice;
                if(choice == "o")
                    first = true;
                else{
                    first = false;
                }
            }
            if(d5 == 0){
                while(undo){
                    tolerance = true;
                    cout  << "Vous avez choisi de résoudre une équation polynomial de degré 3 donc entrez les coefficients du pôlynome : "<<endl;
                    cout << "a = ";
                    cin>>a;
                    cout << "b = ";
                    cin>>b;
                    cout << "c = ";
                    cin>>c;
                    cout << "d = ";
                    cin>>d;
                    cout << "e = ";
                    cin>>e;
                    cout << "f = ";
                    cin>>f;
                    cout << "Votre équation est de la forme: f(x)= " << a << "x^5 + " << b << "x^4 + " << c << "x^3 + " << d << "x^2 + " << e << "x + " << f << ". " << endl;
                    cout << "Vous souhaitez résoudre f(x)=0 dans R." << endl;
                    cout << endl;
                    vector<double> v;
                    v.push_back(f);
                    v.push_back(e);
                    v.push_back(d);
                    v.push_back(c);
                    v.push_back(b);
                    v.push_back(a);

                    while(tolerance){
                        resUsuelle = polynome5(v); 
                        cout << endl << "Veuillez saisir la tolérance d'erreur que vous souhaitez:" << endl;
                        cin>>precision;
                        cout << "Votre tolérance d'erreur est: " << precision << endl;
                        cout << endl;
                        resBernstein = Bernstein(v, precision);
                        int size = resBernstein.size();
                        cout << "Il y a " << size << " solution(s) dans R pour votre équation." << endl;
                        cout << endl;

                        if(resBernstein.size() != 0){
                            cout << "Voici les solutions dans R avec la méthode usuelle:" << endl;
                            for(int i = 0; i < size;i++)
                            {
                                cout << "x" << i+1 << " = " << resUsuelle[i] << endl;
                            }
                            cout << endl;
                            cout << "Voici les solutions dans R avec la méthode de Bernstein:" << endl;
                            for(int i = 0; i < size;i++)
                            {
                                cout << "x" << i+1 << " = " << resBernstein[i] << endl;
                            }
                        }
                        else {
                            cout << "Pas de solution dans R." << endl;
                        }
                        cout << endl;
                        cout << "Est ce que vous souhaitez changer la tolérance d'erreur? (o/n)" << endl;
                        cin>>choice;
                        if(choice == "o")
                            tolerance = true;
                        else{
                            tolerance = false;
                        }
                    }

                    cout << "Est ce que vous souhaitez changer vos coefficients? (o/n)" << endl;
                    cin>>choice;
                    if(choice == "o")
                        undo = true;
                    else{
                        undo = false;
                    }
                }
                cout << endl;
                cout << "Est ce que vous souhaitez changer de degré? (o/n)" << endl;
                cin>>choice;
                if(choice == "o")
                    first = true;
                else{
                    first = false;
                }
    	    }
        }
        cout << endl;
        cout << "Est ce que vous souhaitez retourner au menu principal? (o/n)" << endl;
        cin>>choice;
        cout << endl;
        if(choice == "o")
            testing = true;
        else{
            testing = false;
        }
    }
    return 0;
}
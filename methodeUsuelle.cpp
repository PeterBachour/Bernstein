#include "methodeUsuelle.h"
#define Pi 3.141592654

vector<double> polynome3(vector<double> coeff){
    std::vector<double> result;
    double a = coeff[3];
    double b = coeff[2]/a;
    double c = coeff[1]/a;
    double d = coeff[0]/a;
    
    double disc, q, r, dum1, s, t, term1, r13;
    q = (3.0*c - (b*b))/9.0;
    r = -(27.0*d) + b*(9.0*c - 2.0*(b*b));
    r /= 54.0;
    disc = q*q*q + r*r;
    term1 = (b/3.0);
    
    double x1, x2, x3;
    if (disc > 0)
    {
        s = r + sqrt(disc);
        s = s<0 ? -cbrt(-s) : cbrt(s);
        t = r - sqrt(disc);
        t = t<0 ? -cbrt(-t) : cbrt(t);
        x1 = -term1 + s + t;
        result.push_back(x1);
        return result;
    } 
    else if (disc == 0)  
    { 
        r13 = r<0 ? -cbrt(-r) : cbrt(r);
        x1 = -term1 + 2.0*r13;
        x3 = x2 = -(r13 + term1);
    }
    else 
    {
        q = -q;
        dum1 = q*q*q;
        dum1 = acos(r/sqrt(dum1));
        r13 = 2.0*sqrt(q);
        x1 = -term1 + r13*cos(dum1/3.0);
        x2 = -term1 + r13*cos((dum1 + 2.0*Pi)/3.0);
        x3 = -term1 + r13*cos((dum1 + 4.0*Pi)/3.0);
    }
    
    result.push_back(x1);
    result.push_back(x2);
    result.push_back(x3);
	sort( result.begin(), result.end() );
    return result;
}

vector<double> polynome4(vector<double> coeff){
   
    double a = coeff[4];
    double b = coeff[3];
    double c = coeff[2];
    double d = coeff[1];
    double e = coeff[0];
    vector<double> result;
    double x1,x2,x3,x4;

    vector<double> coeff3;

   
    if(a == 0) {
        coeff3.push_back(e);
        coeff3.push_back(d);
        coeff3.push_back(c);
        coeff3.push_back(b);
        return polynome3(coeff3);
    }

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

            result.push_back(x1);
            result.push_back(x2);
            result.push_back(x3);
            result.push_back(x4);
			sort( result.begin(), result.end() );
            return result;
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
            
            result.push_back(x1);
            result.push_back(x2);
            result.push_back(x3);
            result.push_back(x4);
			sort( result.begin(), result.end() );
            return result;
        }
    }

    if (B != 0){
        coeff3.push_back(4*A*C - B*B);
        coeff3.push_back(-8*C);
        coeff3.push_back(-4*A);
        coeff3.push_back(8);
        

        double lambda = polynome3(coeff3)[0];

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
    sort( result.begin(), result.end() );
    return result;
}
double calculPoly(double polynome[6], int degree, double x)
{
    double P = 0.0, S = 0.0;
    int cpt;
    for(cpt = degree; cpt >= 0; cpt--)
    {
        S = polynome[cpt] * pow(x, cpt);
        P = P + S;
    }
    return P;
}

double newton(double polynome[6], int degree, double x0)
{
    double polynomeDeriv[6] = {0.0};
    int cpt, p;
    double xi, P = 0.0, P2 = 0.0, Pverif, Pverif2, Xi;
    xi = x0;
    int n = 0;

    p = degree - 1;
    for(cpt = p; cpt > 0; cpt--)
    {
        polynomeDeriv[cpt - 1] = polynome[cpt] * cpt;
    }

    do
    {
        n += 1;
        P = calculPoly(polynome, degree, xi);
        P2 = calculPoly(polynomeDeriv, p, xi);
        if(P < 0.0 && P2 < 0.0)
        {
            xi = xi + P / P2;
        }
        else
        {
            xi = xi - P / P2;
        }
        Pverif = P * pow(10.0, 7.0);
        Pverif2 = P * pow(10.0, 6.0);
        if(Pverif < 0.0)
        {
            Pverif = -Pverif;
        }

        if(Pverif2 < 0.0)
        {
            Pverif2 = -Pverif2;
        }

        if(xi < 0.0)
        {
            Xi = -xi;
        }
        else
        {
            Xi = xi;
        }

        if(Xi > 1000)
        {
            xi = -x0;
        }
    } while((Pverif > 1.0 && Pverif2 >= 0) && n < 10000);

    // printf("P = %lf\r\nP2 = %lf\r\nx%i = %lf\r\n\n", P, P2, n, xi);
    return xi;
}
vector<double> polynome5(vector<double> coeff)
{
	vector<double> res;
	double a = coeff[5];
    double b = coeff[4];
    double c = coeff[3];
    double d = coeff[2];
    double e = coeff[1];
    double f = coeff[0];
    vector<double> result;
    // Division des coefficients par a si a != 1
    if(a != 1.0)
    {
        b /= a;
        c /= a;
        d /= a;
        e /= a;
        f /= a;
        a /= a;
    }

    double x0, equation[6] = {f, e, d, c, b, a};
    x0 = newton(equation, 5, 0.5);

    double polynome[5];
    /* Factorisation par la méthode de Horner */
    polynome[4] = a ;
    polynome[3] = b + polynome[4] * x0;
    polynome[2] = c + polynome[3] * x0;
    polynome[1] = d + polynome[2] * x0;
    polynome[0] = e + polynome[1] * x0;


    vector<double> coeff4;
    coeff4.push_back(polynome[0]);
    coeff4.push_back(polynome[1]);
    coeff4.push_back(polynome[2]);
    coeff4.push_back(polynome[3]);
    coeff4.push_back(polynome[4]);
    res = polynome4(coeff4);
    res.push_back(x0);
    sort( res.begin(), res.end() );

    return res;

}



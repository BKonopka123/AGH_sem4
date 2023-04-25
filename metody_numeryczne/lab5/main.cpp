#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "/usr/include/gsl/gsl_deriv.h"

#define IT_MAX 100

//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out

struct my_f_params { double a; double b; double k; };

double my_f(double d, void * p);
double newton(double d, void * p,  gsl_function F);
void newton4(double d, void * p,  gsl_function F, std::fstream &plik);


int main()
{

    std::fstream plik;
	plik.open("out.txt");

    gsl_function F;
    F.function = &my_f;

    //ZAD 1
    double d = 1;
    double a = 2.0;
    double b = 2.0;
    double k = 0.25;
    struct my_f_params params = {a, b, k};
    plik << "ZADANIE 1\nD: " << newton(d, &params ,F) << std::endl;

    //ZAD 2
    plik << "\nZADANIE 2 " << std::endl;
    double moment= 0.0;

    double c=2.0;
    while(c<=10.0)
    {
        a=c;
        b=c;
        d=c/2.0;
        k=0.25;
        struct my_f_params params = {a, b, k};
        plik << "C: " << c << "\t\tB: " << c - newton(d, &params ,F)<< "\t\tD: " << newton(d, &params ,F) << std::endl;
        
        if(c- 2*newton(d, &params ,F) <= 0.0000000001 && c- 2*newton(d, &params ,F) >= 0.0)
            moment = c;
        c+=0.01;
    }

    //ZAD 3
    plik << "\nZADANIE 3\nC: " << moment << std::endl;

    //ZAD 4
    plik << "\nZADANIE 4\n";
    c=2.0;
    a=c;
    b=c;
    k=0.25;
    params = {a, b, k};

    double i=0.2;
    for(i; i<1.9; i+=0.2)
    {
        d=i;
        plik << "od D= " << i << std::endl; 
        newton4(d, &params ,F, plik);
        plik << std::endl;
    }

    plik.close();
    return 0;
}

double my_f(double d, void * p)
{
    struct my_f_params * params = (struct my_f_params *)p;
    double a = (params->a);
    double b = (params->b);
    double k = (params->k);
    return (d/ ( (a-d) * (b-d) )) - k;
}

double newton(double d, void * p, gsl_function F)
{
    struct my_f_params * params_temp = (struct my_f_params *)p;
    double a = (params_temp->a);
    double b = (params_temp->b);
    double k = (params_temp->k);
    
    struct my_f_params params = {a, b, k};
    F.params = &params;

    double result, abserr;

    double i=1.0;
    while(i >= 0.000001)
    {
        gsl_deriv_central (&F, d, 1e-12, &result, &abserr);
        double temp=d;
        d =d - my_f(d, &params) / result;
        i=abs(d-temp);
    }
    return d; 
}

void newton4(double d, void * p,  gsl_function F, std::fstream &plik)
{
    struct my_f_params * params_temp = (struct my_f_params *)p;
    double a = (params_temp->a);
    double b = (params_temp->b);
    double k = (params_temp->k);
    
    struct my_f_params params = {a, b, k};
    F.params = &params;

    double result, abserr;
     
    int krok = 1;
    double i=1.0;
    while(i >= 0.000001)
    {
        double temp=d;
        gsl_deriv_central (&F, d, 1e-12, &result, &abserr);
        d =d - my_f(d, &params) / result;

        i=abs(d-temp);

        plik.width(15);
        plik << krok << "\t";
        krok++;
        plik.width(15);
        plik << d << "\t";
        plik.width(15);
        plik << i << "\t";
        plik.width(15);
        plik << my_f(d, &params) << "\t";
        plik.width(15);
        plik << result << std::endl;   
    } 
}
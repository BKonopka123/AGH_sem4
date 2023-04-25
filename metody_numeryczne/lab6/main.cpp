#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "/usr/include/gsl/gsl_deriv.h"

#define M 101


//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out

double my_f1(double x);
double my_f2(double x);
double my_f3(double x);
gsl_vector * lagrange(gsl_vector *x, gsl_vector *y, gsl_vector *x2, int N);
gsl_vector * czybyszew(double x_min, double x_max, int N);

int main(void)
{
    std::fstream plik;
	plik.open("out.txt");

    double (*(funkcje[]))(double) = {my_f1, my_f2, my_f3};

    for(int z=0; z<3; z++)
    {    
        plik.width(30);
        plik << "WYKRES " << z << "\n\n\n";
        
        double krok[4] = {2.5, 1.0, 0.7142857143, 0.5};
        int krok_w = 0;

        for(int N=5; N<21; N+=5)
        {
            
            plik << "*********************************DLA " << N << " WEZLOW*********************************\n\n";

            gsl_vector *x = gsl_vector_calloc(N);
            gsl_vector *y = gsl_vector_calloc(N);
            gsl_vector *x2 = gsl_vector_calloc(M);
            gsl_vector *y2 = gsl_vector_calloc(M);

            double b=-5.0;
            for(int i=0; i<N; i++)
            {
                gsl_vector_set(x,i,b);
                b+=krok[krok_w];
                if(!(N%2) && b==0)
                    b+=krok[krok_w];      
            }

            for(int i=0; i<N; i++)
            {
                gsl_vector_set(y, i, (funkcje[z])(gsl_vector_get(x,i)));
            }

            double a=-5.0;
            for(int  i=0; i<M; i+=1)
            {
                gsl_vector_set(x2, i, a);
                a+=0.1;
            }


            plik << "LAGRANGE\n";

            y2 = lagrange(x, y, x2, N);
            for(int  i=0; i<M; i+=1)
            {
                plik.width(15);
                plik << gsl_vector_get(x2,i) << "\t";
                plik.width(15);
                plik << gsl_vector_get(y2,i);
                plik << std::endl;
            }

            plik << "\nCZYBYSZEW\n";

            gsl_vector *x_opt = gsl_vector_calloc(N);
            x_opt = czybyszew(gsl_vector_get(x,0), gsl_vector_get(x,N-1), N);

            for(int i=0; i<N; i++)
            {
                gsl_vector_set(y, i, (funkcje[z])(gsl_vector_get(x_opt,i)));
            }

            y2 = lagrange(x_opt, y, x2, N);
            for(int  i=0; i<M; i+=1)
            {
                plik.width(15);
                plik << gsl_vector_get(x2,i) << "\t";
                plik.width(15);
                plik << gsl_vector_get(y2,i);
                plik << std::endl;
            }

            plik << std::endl << std::endl;
            krok_w++;
        }

        plik << "\n\n\n";
    }
    plik.close();
    return 0;
}

double my_f1(double x)
{
    return exp(0-(x*x));
}

double my_f2(double x)
{
    if(x<0)
        return -1;
    else
        return 1;
}

double my_f3(double x)
{
    return cos(2*x);
}

gsl_vector * lagrange(gsl_vector *x, gsl_vector *y, gsl_vector *x2, int N)
{
    gsl_vector *temp = gsl_vector_calloc(M);
    for(int k=0; k<M; k++)
    {
        double w=0;
        for(int i=0; i<N; i++)
        {
            double gora = 1;
            double dol = 1;
            for(int j=0; j<N; j++)
            {
                if(j != i)
                {
                    gora *= (gsl_vector_get(x2,k) - gsl_vector_get(x,j));
                    //std::cout << gora << " ";
                    dol *= (gsl_vector_get(x,i) - gsl_vector_get(x,j));
                }
            }
            w+=gsl_vector_get(y,i)*(gora/dol);
            //std::cout << w << std::endl;
        }
        gsl_vector_set(temp, k, w);
    }
    return temp;
}

gsl_vector * czybyszew(double x_min, double x_max, int N)
{
    gsl_vector *temp = gsl_vector_calloc(N);
    for(int i=0; i<N; i++)
    {
        double w;
        w = 0.5*((x_max-x_min) * cos(M_PI * (2*i +1)/(2*(N-1) +2)) + x_max + x_min);
        gsl_vector_set(temp, i, w);
    }
    return temp;
}
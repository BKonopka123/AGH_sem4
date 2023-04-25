#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include <iostream>
#include <fstream>
#include <cmath>
 

int main()
{
    //wersja GSL

    //dane
    int n=4; // rozmiar tablicy
    gsl_matrix *A = gsl_matrix_calloc(n, n); //tablcia A
    gsl_matrix *ACPY = gsl_matrix_calloc(n, n);
    gsl_permutation *p = gsl_permutation_calloc(n); //permutacja p
    int signum;

    //otwarcie pliku
    std::ofstream zapis; 
    zapis.open("dane.txt");
    
    //*****************************************************************ZAD 1
    zapis << "ZAD1\nmacierz A: \n";
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            double a = i+j+2;
            double b= 1/a;
            gsl_matrix_set(A, i, j, b);
            
            zapis.width(15);
            zapis << gsl_matrix_get(A, i, j) << "\t";
        }
        zapis << std::endl;
    }
    
    gsl_matrix_memcpy(ACPY,A);
    gsl_linalg_LU_decomp(ACPY, p, &signum);
    zapis << std::endl;

    zapis << "Macierz LU:\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {  
                zapis.width(15);
                zapis << gsl_matrix_get(ACPY, i, j) << "\t";
        }
        zapis << std::endl;
    }
    
    //*****************************************************************ZAD 2
    double wyz=1;
    
    zapis << "\nZAD 2\nDiagonala macierzy U: \n";
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) 
            {    
                zapis.width(15);
                zapis << gsl_matrix_get(ACPY, i, j) << "\t";
                
                wyz*= gsl_matrix_get(ACPY, i, j);
            }
        }
    }
    
    zapis.width(15);
    zapis << std::endl << "Wyznacznik macierzy A:\n"<< wyz << std::endl;
    
    //*****************************************************************ZAD 3
    gsl_vector *b[n];
    gsl_vector *x[n]; 
    gsl_matrix *AOD = gsl_matrix_calloc(n, n);

    for(int i=0; i<n; i++)
    {
        b[i] = gsl_vector_calloc(n);
        x[i] = gsl_vector_calloc(n);
        
        for(int j=0; j<n; j++)
        {
            if(i==j)
                gsl_vector_set(b[i], j, 1);
            else
                gsl_vector_set(b[i], j, 0);
        }
        
        gsl_linalg_LU_solve(ACPY, p, b[i], x[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            double temp =  gsl_vector_get(x[i], j);
            gsl_matrix_set(AOD, j, i, temp);
        }
    }

    zapis << "\nZAD 3\nOdwrocona macierz A: \n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {  
                zapis.width(15);
                zapis << gsl_matrix_get(AOD, i, j) << "\t";
        }
        zapis << std::endl;
    }

    //*****************************************************************ZAD 4
    gsl_matrix *C = gsl_matrix_calloc(n, n);
    
    for(int i=0; i<n ; i++)
    {
        for(int j=0; j<n ; j++)
        {
            gsl_matrix_set(C, i, j, 0);
            double temp =  gsl_matrix_get(C, i, j);
            for (int k=0; k<n; k++)
            {
                temp += gsl_matrix_get(A, i, k) * gsl_matrix_get(AOD, k, j); 
            }
            gsl_matrix_set(C, i, j, temp);
        }
    }

    zapis << "\nZAD 4\nIloczyn macierzy A i A ^ -1 \n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {  
                zapis.width(15);
                zapis << gsl_matrix_get(C, i, j) << "\t";
        }
        zapis << std::endl;
    }

    //*****************************************************************ZAD 5
    double na[n];
    double naod[n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            na[i]+=fabs(gsl_matrix_get(A, i, j));
            naod[i]+=fabs(gsl_matrix_get(AOD, i, j));
        }
    }
    
    double maksna=na[0];
    double maksnaod=naod[0];
    for(int i=0; i<n; i++)
    {
        if(na[i]>maksna)
        {
            maksna = na[i];
        }
        if(naod[i]>maksnaod)
        {
            maksnaod = naod[i];
        }
    } 
    double cond = maksna * maksnaod;
    zapis << "\nZAD 5\nWskaznik uwarunkowania macierzy: \n" << cond;

    zapis.close();
    return 0;
}
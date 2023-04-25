#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#define N 9 //zeby do pliku zapisalo dla n=99 wystarczy tu zmienic define na 99!

//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out

double lambda(double x);
void save_matrix(std::fstream &file , gsl_matrix *A, const char * str);
gsl_matrix * multiply(const gsl_matrix *A,const gsl_matrix *B);
double vector_norm(gsl_matrix * X);
void rotate_vector(gsl_matrix **X);
gsl_matrix * iter(gsl_matrix * A, gsl_matrix *B, std::fstream &file);

int main()
{   
    std::fstream plik;
	plik.open("out.txt");
    
    //centymetry
    int x=0;
    gsl_matrix * A = gsl_matrix_calloc(N,N);
    for(int i = 0; i < N; i++)
	{
            x=(i+1)*(100/(N+1));
            gsl_matrix_set(A,i,i,0-lambda(x-0.5)-lambda(x+0.5));
            if(i != N-1)    
                gsl_matrix_set(A,i,i+1,lambda(x+0.5));
            if(i != N-1)
                gsl_matrix_set(A,i+1,i,lambda(x+0.5));        
    }
    //save_matrix(plik,A,"macierz A");

    gsl_matrix * B = gsl_matrix_calloc(N,1);
    gsl_matrix_set(B,0,0,0-lambda(0.5*(100/(N+1)))*1000);
    gsl_matrix_set(B,N-1,0,0-lambda((N+0.5)*(100/(N+1)))*100);
    
    //save_matrix(plik,B,"wektor B");

    gsl_matrix * T = iter(A,B, plik);

    //save_matrix(plik,T,"wektor rozwiazan T");

    gsl_matrix_free(A);
	gsl_matrix_free(B);
    gsl_matrix_free(T);

    plik.close();

    return 0;
}

double lambda(double x)
{
    if(x>=0 && x<40)
        return 0.3;
    else if(x>=40 && x<70)
        return 0.2;
    else
        return 0.1;
}

void save_matrix(std::fstream &file, gsl_matrix *A, const char * str)
{
    file << str << std::endl;
    for(int i = 0; i < A->size1; i++)
    {
        for(int j = 0; j < A->size2; j++)
        {
            file.width(10);
            file << gsl_matrix_get(A, i, j) << "\t";
        }
        file << "\n";
    }
    file << "\n";
}

gsl_matrix * multiply(const gsl_matrix *A,const gsl_matrix *B)
{ 
    if(A->size2 != B->size1)
    {
        std::cout << "zle wymiary";
        return nullptr; 
    }
    gsl_matrix *C = gsl_matrix_calloc(A->size1, B->size2);
    for (int i = 0; i < A->size1; i++)
    {
        for (int j = 0; j < B->size2; j++)
        {
            double temp = gsl_matrix_get(C,i,j);
            for (int k=0; k < A->size2; k++)
            {
                temp += gsl_matrix_get(A,i,k) * gsl_matrix_get(B,k,j);
            }
            gsl_matrix_set(C,i,j, temp);
        }
    }
    return C;
}


double vector_norm(gsl_matrix * X)
{
	double norm = 0.;
	for(int i = 0; i < X->size1; i++)
		norm += gsl_matrix_get(X,i,0)*gsl_matrix_get(X,i,0);
	return norm;

}

void rotate_vector(gsl_matrix **X)
{
	gsl_matrix *new_X;
	if((*X)->size1 > (*X)->size2)
	{
		
		new_X = gsl_matrix_calloc((*X)->size2,(*X)->size1);
		for(short i = 0; i < (*X)->size1; i++)
			gsl_matrix_set(new_X,0,i,gsl_matrix_get(*X,i,0));

	}
	else if((*X)->size1 < (*X)->size2)
	{
		new_X = gsl_matrix_calloc((*X)->size2,(*X)->size1);
		for(short i = 0; i < (*X)->size2; i++)
			gsl_matrix_set(new_X,i,0,gsl_matrix_get(*X,0,i));
	}
	else
		return;
	gsl_matrix_free(*X);
	*X = new_X;

}

gsl_matrix * iter(gsl_matrix * A, gsl_matrix *B, std::fstream &file)
{
    gsl_matrix *r_k = gsl_matrix_calloc(B->size1,1); //wektor reszt
	gsl_matrix *t_k = gsl_matrix_calloc(B->size1,1); //wektor rozwiązań
    for(int i=0; i<B->size1; i++)
    {
        gsl_matrix_set(t_k,i,0,1);
    }

	gsl_matrix *temp = gsl_matrix_calloc(B->size1,1); // {r_k^t}*{r_k}
	gsl_matrix *temp_2; // A*r_k
	gsl_matrix *temp_3; // {r_k^t}*{A}*{r_k}
	double alpha = 0.;
	int i = 0;
	do
	{
		double vec_norm_sqr = 0.;

		for(short i = 0; i < B->size1; i++) //r_k
		{
			temp = multiply(A,t_k); // A*x_k
			gsl_matrix_set(r_k,i,0,gsl_matrix_get(B,i,0) - gsl_matrix_get(temp,i,0));
			gsl_matrix_free(temp);
            
		}
		for(short i = 0; i < B->size1; i++)
		{
			temp_2 = multiply(A,r_k);
			rotate_vector(&r_k);
			temp_3 = multiply(r_k,temp_2);
			rotate_vector(&r_k);
			alpha = vector_norm(r_k)/gsl_matrix_get(temp_3,0,0); 
			gsl_matrix_free(temp_2);
			gsl_matrix_free(temp_3);

		}
		for(short i = 0; i < B->size1; i++)	
		{
			gsl_matrix_set(t_k,i,0,gsl_matrix_get(t_k,i,0) + alpha*gsl_matrix_get(r_k,i,0));
		}
        file << vector_norm(t_k) << std::endl;
		i++;
        std::cout<< i <<std::endl;
	} while(sqrt(vector_norm(r_k)) > 0.000001 && i < 60000); //tu musi być 600 bo inaczej program za dlugo sie kompiluje, trzeba poczekac chwile
	gsl_matrix_free(r_k);

	return t_k;
}
#include <iostream>
#include <algorithm>
#include "cronometro.h"

void printvec(int *v,int *vf)
{
    int i = 0;
    while((v+i)!=vf) {std::cout<<*(v+i)<<" ";++i;}
    std::cout<<std::endl;
}

void burbujeo(int v[],int i,int j)
{
    int aux;
    for(int k = j-1; k > i; --k)
    {
        if(v[k] < v[k-1])
        {
            aux = v[k];
            v[k] = v[k-1];
            v[k-1] = aux;
        }
    }
}

void ord_intercambio(int v[],int n)
{
    for(int i = 0;i < n;++i) burbujeo(v,i,n);
}

int main()
{
    cronometro c;
    const double e_abs = 0.01;
    const double e_rel = 0.005;
    int n = 20000;
    for(int i = 1000; i <= n; i = i + 1000)
    {
        long r = 0;
        int v[i];
        int vcp[i];
        for(int j = 0;j < i;++j) v[j] = j;
        std::random_shuffle(v,v+i);
        c.activar();
        do
        {
            memcpy(vcp,v,sizeof(v));
            ord_intercambio(vcp,i);
            r++;
        }while(c.tiempo() < e_abs/(e_abs+e_rel));
        c.parar();
        double t = c.tiempo()/r;
        std::cout<<i<<" elementos -> "<<t<<" segundos"<<std::endl;
    }
}
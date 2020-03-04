#include <iostream>
#include <algorithm>
#include <cstring>
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

bool iguales(int v1[],int v2[],int n)
{
    for(int i = 0;i < n; i++)
    {
        if(v1[i] != v2[i]) return false;
    }
    return true;
}

int main()
{
    int n=13;
    cronometro c;
    int v[n];
    int v1[n];
    int vs[n];
    for(int i = 0;i < n;++i) v[i] = i;
    memcpy(vs,v,sizeof(v));
    c.activar();
    do
    {
        memcpy(v1,v,sizeof(v));
        ord_intercambio(v1,n);
        if(!iguales(vs,v1,n)) {std::cout<<"error";}
    }
    while(std::next_permutation(v,v+n));
    c.parar();
    std::cout<<c.tiempo()<<" Segundos"<<std::endl;
    return 0;
}
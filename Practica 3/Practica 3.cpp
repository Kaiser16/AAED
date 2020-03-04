#include <iostream>
#include <ctime>
#include "cronometro.h"
#include <algorithm>
#include <cstdlib>

using namespace std;

///////////////////////////////////
void insercion(int v[],int j)
{
    int x = v[j];
    while(j > 0 && x < v[j-1])
    {
        v[j] = v[j-1];
        j--;
    }
    v[j] = x;
}

void ord_inserccion(int v[],int n)
{
    for(int i = 1;i < n ;i++) insercion(v,i);
}
///////////////////////////////////
int posicion_minimo(int v[],int i,int j)
{
    int p = i;
    int m = v[i];
    for(int k = i+1;k < j;++k)
    {
        if(v[k] < m)
        {
            p = k;
            m = v[k];
        }
    }
    return p;
}

void ord_seleccion(int v[],int n)
{
    int p,m,aux;
    for(int i = 0;i < n;i++)
    {
        p = posicion_minimo(v,i,n);
        aux = v[p];
        v[p] = v[i];
        v[i] = aux;
    }
}
///////////////////////////////////
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
///////////////////////////////////

void pruebas(int n,int tipo)
{
    cronometro c;
    int v[n];
    for(int i = 0;i < n;i++) v[i] = i;
    const size_t a = sizeof v / sizeof *v;
    random_shuffle(v,v+a);
    //for(int aut:v)cout<<aut<<" ";
    cout<<endl;
    c.activar();
    if(tipo == 1) ord_intercambio(v,n);
    if(tipo == 2) ord_seleccion(v,n);
    if(tipo == 3) ord_inserccion(v,n);
    c.parar();
    if(tipo == 1) cout<<"|INTERCAMBIO|"<<endl;
    if(tipo == 2) cout<<"|SELECCION|"<<endl;
    if(tipo == 3) cout<<"|INSERCION|"<<endl;
    cout<<n<<" Numeros: "<<c.tiempo()<<endl;//<<endl;
    /*for(int aut:v)cout<<aut<<" ";
    cout<<"\n"<<endl;*/
}

int main()
{
    srand(time(0));
    //for(int i = 1000;i <= 20000;i += 1000) pruebas(i);
    for(int j = 1; j <= 3;++j) 
    {
        for(int i = 1000;i <= 20000;i += 1000) pruebas(i,j);
    }
    return 0;
}
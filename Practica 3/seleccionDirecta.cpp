#include <iostream>
#include <ctime>
#include "cronometro.h"
#include <algorithm>
#include <cstdlib>

using namespace std;

void seleccionDirecta(int v[],int n)
{
    int p,m,aux;
    for(int i = 0;i < n;i++)
    {
        p = i;
        m = v[i];
        for(int j = i+1;j < n;j++)
        {
            if(v[j] < m)
            {
                p = j;
                m = v[j];
            }
        }
        v[p] = v[i];
        v[i] = m;
    }
}

void pruebas(int n)
{
    cronometro c;
    int v[n];
    for(int i = 0;i < n;i++) v[i] = i;
    const size_t a = sizeof v / sizeof *v;
    random_shuffle(v,v+a);
    /*for(int aut:v)cout<<aut<<" ";
    cout<<endl;*/
    c.activar();
    seleccionDirecta(v,n);
    c.parar();
    //for(int aut:v)cout<<aut<<" ";
    cout<<n<<" Numeros: "<<c.tiempo()<<endl;
}

int main()
{
    srand(time(0));
    for(int i = 1000;i <= 20000;i += 1000) pruebas(i);
    return 0;
}
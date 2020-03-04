#include <iostream>
#include <cmath>
#include "cronometro.h"

inline double cuadrado2(double x){return x*x;}
inline double cuadrado(double x){return pow(x,2);}

int main()
{
    using namespace std;
    double t;
    cronometro c;
    cronometro d;
    cronometro e;
    double x;
    long interaciones = 0;
    c.activar();
    while(c.tiempo() < 1){
        x = cuadrado(x);
        interaciones++;
    }
    c.parar();
    cout<<" Numero de iteraciones en "<<c.tiempo()<<" segundo "<<interaciones<<endl;

    interaciones = 0;
    d.activar();
    while(d.tiempo() < 1){
        x = cuadrado(x);
        interaciones++;
    }
    d.parar();
    cout<<" Numero de iteraciones en "<<d.tiempo()<<" segundo "<<interaciones<<endl;
    return 0;
}
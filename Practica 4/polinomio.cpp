#include "polinomio.h"

polinomio::polinomio(unsigned gradoMax)
{
    vec = new double[gradoMax];
    for(int i = 0; i < gradoMax;++i)
        vec[i] = 0;
    gradMax = gradoMax;
    gradop = 0;
}

unsigned polinomio::grado() const
{
    return gradop;
}

double polinomio::coeficiente(unsigned n) const
{
    if(n > gradMax)
        return 0;
    else
        return vec[n];
}

void polinomio::coeficiente(unsigned n,double c)
{
    if(n > gradop)
        gradop = n;
    vec[n] = c;
}
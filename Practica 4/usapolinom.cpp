#include "usapolinom.h"
#include <ostream>


polinomio operator+(const polinomio &a,const polinomio &b)
{
    int g;
    if(a.grado() > b.grado()) g = a.grado();
    else g = b.grado();
    polinomio c(g);
    for(int i = 0;i <= g; i++) 
        c.coeficiente(i,a.coeficiente(i)+b.coeficiente(i));
    return c;
}

polinomio operator*(const polinomio &a,const polinomio &b)
{
    polinomio c(a.grado()+b.grado());
    for(int i = a.grado();i >= 0; i--)
    {
        for(int j = b.grado();j >= 0;j--) 
            c.coeficiente(j+i,c.coeficiente(j+i)+a.coeficiente(i)*b.coeficiente(j));
    }
    return c;
}

polinomio operator-(const polinomio &a)
{
    polinomio c(a.grado());
    for(int i = 0;i <= a.grado();i++)
        c.coeficiente(i,-a.coeficiente(i));
    return c;
}

polinomio operator-(const polinomio &a, const polinomio &b)
{
    return a+(-b);
}

polinomio derivada(polinomio a)
{
    polinomio c(a.grado()-1);
    for(int i = a.grado()-1; i >= 0; i--)
        c.coeficiente(i,a.coeficiente(i+1)*(i+1));
    return c;
}

polinomio crear()
{
    int g;
    using namespace std;
    cout<<"Introduce e grado del polinomio: ";
    cin>>g;
    polinomio c(g);
    for(int i = g; i >= 0;--i)
    {
        cout<<" Introduce el valor de x^"<<i<<": ";
        cin>>g;
        c.coeficiente(i,g);
    }
    return c;
}

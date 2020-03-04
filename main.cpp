#include <iostream>
#include "listaenla.h"


std::ostream &operator<<(std::ostream &os, const Pila<int>& Q)
{
    Pila<int> P(Q);
    while(!P.vacia())
    {
        os << P.tope() << " ";
        P.pop();
    }
    return os;
}

int main()
{
    Pila<int> p;
    for(int i = 0; i < 10; ++i)
        p.push(i);
    std::cout<<p<<std::endl;
}
#include <iostream>
#include "listaenla.h"

void printlist(Lista<int> &l)
{
    for(Lista<int>::posicion p = l.primera(); p != l.fin(); p = p->sig)
        std::cout<<l.elemento(p)<<" ";
    std::cout<<std::endl;
}

int main()
{
    Lista<int> l;
    for(int i = 0; i < 10; ++i)
        l.insertar(i,l.fin());
    printlist(l);
    std::cout<<l.elemento(l.buscar(5));
    while(l.primera() != l.fin())
    {
        l.eliminar(l.anterior(l.fin()));
        printlist(l);
    }
    return 0;
}
#include <iostream>
#include "pilabicola.h"

int main()
{
    Pila<int> p;
    std::cout<<p.vacia()<<std::endl;
    p.push(5);
    std::cout<<p.tope()<<std::endl;
    p.push(4);
    p.pop();
    std::cout<<p.tope()<<std::endl;
    std::cout<<p.llena()<<std::endl;
}
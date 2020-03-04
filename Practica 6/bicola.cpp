#include<iostream>
#include "bicola.h"

void printcola(Cola<int> c)
{
    while(!c.vacia())
    {
        std::cout<<c.frente()<<" ";
        c.pop_front();
    }
    std::cout<<std::endl;
}

int main()
{
    Cola<int> c;
    for(int i = 0; i < 10; ++i)
        c.push_back(i);
    printcola(c);
    std::cout<<c.frente()<<std::endl;
    std::cout<<c.final()<<std::endl;
}
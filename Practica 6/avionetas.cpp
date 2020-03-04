#include <iostream>
#include "colavec.h"

void printcola(Cola<int> c)
{
    while(!c.vacia())
    {
        std::cout<<c.frente()<<" ";
        c.pop();
    }
    std::cout<<std::endl;
}

bool aterrizar(int x,Cola<int> &c)
{
    bool exito = true;
    if(c.llena()) 
        exito = false;
    else
        c.push(x);
    printcola(c);
    return exito;
}

void despegar(int x,Cola<int> &c)
{
    Cola<int> aux(12);
    int a = c.frente();
    if(a == x)
        c.pop();
    else
    {
        do
        {
            aux.push(a);
            c.pop();
            a = c.frente();
        }while(a != x && !c.vacia());
        if(a == x)
        {
            c.pop();
            while(!c.vacia())
            {
                aux.push(c.frente());
                c.pop();
            }
        }        
        while(!aux.vacia())
        {
            c.push(aux.frente());
            aux.pop();
        }
    }
    printcola(c);
}

int main()
{
    Cola<int> c(12);
    for(int i = 0; i < 12; ++i)
        aterrizar(i,c);
    despegar(11,c);
    despegar(0,c);
    despegar(5,c);
    aterrizar(24,c);
}
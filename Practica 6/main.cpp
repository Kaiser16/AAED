#include <iostream>
#include "bicola.h"
#include "pilavec0.h"

bool isomorfica(Pila p, Cola<char> a)
{
    bool isomorfica = true;
    p.pop();
    while(!p.vacia(), !a.vacia())
    {
        if(p.tope() != a.frente())
            isomorfica = false;
        p.pop();
        a.pop_front();
    }
    return isomorfica;
}

void printcola(Cola<char> c)
{
    while(!c.vacia())
    {
        std::cout<<(char)c.frente();
        c.pop_front();
    }
    std::cout<<std::endl;
}

Cola<char> invertirTramo(Cola<char> c,char a,char b)
{
    Cola<char> c2;
    Pila p;
    while(!c.vacia() && c.frente() != a)
    {
        c2.push_back(c.frente());
        c.pop_front();
    }
    while(!c.vacia() && c.frente() != b)
    {
        p.push(c.frente());
        c.pop_front();
    }
    if(!c.vacia())
    {
        p.push(c.frente());
        c.pop_front();
    }
    while(!p.vacia())
    {
        c2.push_back(p.tope());
        p.pop();
    }
    while (!c.vacia())
    {
        c2.push_back(c.frente());
        c.pop_front();
    }
    printcola(c2);
    return c2;
}

int main()
{
    Cola<char> c1,c2,c3;
    Pila p = Pila();
    p.push(6);
    p.push(5);
    p.push(4);
    p.push(1);
    c1.push_back('4');
    c1.push_back('5');
    c1.push_back('6');
    if(isomorfica(p,c1))
        std::cout<<"Isomorfica"<<std::endl;
    else
        std::cout<<"No Isomorfica"<<std::endl;
    
    std::string Sc("0123456789");
    char a = '0',b = '9';
    for(int i = 0; i < Sc.size();++i)
    {
        c2.push_back(Sc[i]);
    }
    printcola(c2);
    invertirTramo(c2,a,b);
    c3.push_front('4');
    c3.push_front('5');
    c3.push_front('6');
    printcola(c3);
    c3.pop_front();
    printcola(c3);
    c3.pop_front();
    printcola(c3);
    c3.pop_front();
    printcola(c3);
}
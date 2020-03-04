#include<iostream>
#include<string>
#include<fstream>
#include"pilavec0.h"

bool fun1(std::string a)
{
    std::string b;
    std::string c;
    Pila p = Pila();
    for(int i = 0; i < a.size();++i)
    {
        p.push(a[i]);
    }
    for(int i = 0; !p.vacia() && p.tope()!='&' ;i++)
    {
        b+=p.tope();
        p.pop();
    }
    p.pop();
    for(int i = 0; !p.vacia() && p.tope()!='&' ;i++)
    {
        c+=p.tope();
        p.pop();
    }
    if(b.size() != c.size()) return false;
    for(int i = 0; i < b.size();i++)
    {
        if(b[i] != c[(c.size()-1)-i]) return false;
    }
    return true;
}

bool fun2 (std::string a)
{
    unsigned cont = 0;
    Pila p = Pila();
    for(int i = 0 ; i < a.size();i++)
    {
        p.push(a[i]);
    }
    while(!p.vacia())
    {
        std::string b;
        for(int i = 0; !p.vacia() && p.tope() != '#';i++)
        {
            b+=p.tope();
            p.pop();
        }
        if(!p.vacia())p.pop();
        if(fun1(b)) cont++;
        b.clear();
    }
    if(cont == 4) return true;
    else return false;
}

void fun3 (int a,int b, Pila p)
{
    Pila r = Pila();
    Pila p1 = Pila();
    Pila p2 = Pila();
    bool fin = false;
    while(!p.vacia())
    {
        if(p.tope() == a)
        {
            while(!p.vacia() && !fin)
            {
                if(p.tope() == b) fin = true;
                p2.push(p.tope());
                p.pop();
            }
            do
            {
                p1.push(p2.tope());
                p2.pop();
            }while(!p2.vacia());
        }
        p1.push(p.tope());
        p.pop();
    }
    while(!p1.vacia())
    {
        r.push(p1.tope());
        p1.pop();
    }
    while(!r.vacia())
    {
        std::cout<<(char)r.tope();
        r.pop();
    }
}

int main()
{
    std::string Sa("hola&aloh");
    if(fun1(Sa))std::cout<<"Bien"<<std::endl;
    else std::cout<<"Mal"<<std::endl;
    /////////////////////////////////////////////
    std::string Sb("buenas&saneub#hola&aloh#buenas&saneub#buenas&saneub");
    if(fun2(Sb))std::cout<<"Bien"<<std::endl;
    else std::cout<<"Mal"<<std::endl;
    /////////////////////////////////////////////
    Pila p = Pila();
    std::string Sc("0213735734563456879");
    char a = '1',b = '8';
    for(int i = Sc.size(); i >= 0;--i)
    {
        p.push(Sc[i]);
    }
    fun3(a,b,p);
    /////////////////////////////////////////////
    std::fstream fichero;
    fichero.open("fichero.txt");
    fichero<<"Escribiendo.\n";
    fichero.close();
}

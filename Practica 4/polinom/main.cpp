#include <iostream>
#include "usapolinom.h"

using namespace std;

std::ostream &operator<<(std::ostream &os,const polinomio &a)
{
    for(int i = a.grado();i >= 0;i--) 
       if(i!=0) os << a.coeficiente(i) << "x^" << i << " + ";
       else os << a.coeficiente(i);
    return os;
}

int main()
{
    int op;
    bool ta = false ,tb = false;
    polinomio a(1);
    polinomio b(1);
    polinomio res(1);
    cout<<a.grado()<<endl;
    do    
    {
        cout<<"a: "<<a<<endl;
        cout<<"b: "<<b<<endl;
        cout<<"res: "<<res<<endl;
        cout<<"|OPCIONES|\n 1.Crear Polinomio a\n 2.Crear Polinomio b\n 3.Suma\n 4.Resta\n 5.Multiplicacion \n 6.Derivada de a\n 7.Derivada de b\n Op: "<<endl;
        cin>>op;
        switch (op)
        {
        case 1:a = crear();break;
        case 2:b = crear();break;
        case 3:res = a + b;break;
        case 4:res = a - b;break;
        case 5:res = a * b;break;
        case 6:res = derivada(a);break;
        case 7:res = derivada(b);break;
        default:
            break;
        }
    }while(op != 0);
    /*
    polinomio a(4);
    polinomio b(2);
    for(int i = 0; i <= 4;i++) 
        a.coeficiente(i,2);
    for(int i = 0; i <= 2;i++)  
        b.coeficiente(i,3);

    std::cout << a+b << std::endl;
    std::cout << b-a << std::endl;
    std::cout << a*b << std::endl;
    std::cout << derivada(a) << std::endl;
    return 0;
    */
}
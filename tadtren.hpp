#ifndef TAD_TREN_HPP
#define TAD_TREN_HPP
#include <cassert>
#include "pilaenla.hpp"

class Tren
{   
public:
    typedef int Vagon;
    Tren();
    void despIzq();
    void despDer();
    void deleteVagon();
    void insertVagon(const Vagon&);
    const Vagon &lookVagon() const;
    bool emptyTrain() const;
private:
    Pila<Vagon> d,i;
};

Tren::Tren() : d(), i() {}

void Tren::despIzq()
{
    assert(!emptyTrain());
    if(!d.vacia())
    {
        Vagon aux = d.tope();
        d.pop();
        if(d.vacia())
            d.push(aux);
        else
            i.push(aux);
    }
}

void Tren::despDer()
{
    assert(!emptyTrain());
    if(!i.vacia())
    {
        d.push(i.tope());
        i.pop();
    }
}

void Tren::deleteVagon()
{
    assert(!emptyTrain());
    d.pop();
    if(d.vacia() && !i.vacia())
    {
        d.push(i.tope());
        i.pop();
    }
}

void Tren::insertVagon(const Vagon& x)
{
    d.push(x);
}

const Tren::Vagon &Tren::lookVagon() const
{
    assert(!emptyTrain());
    return d.tope();
}

bool Tren::emptyTrain() const
{
    return (d.vacia() && i.vacia());
}
#endif
#ifndef pila_bicola_h
#define pila_bicola_h
#include "bicola.h"

const int LMAX = 100;

template <typename T> class Pila
{
public:
    Pila();
    bool vacia() const;
    bool llena() const;
    const T& tope() const;
    void pop();
    void push(const T& x);
private:
    Cola<T> c;
    int tope_;
};

template <typename T>
Pila<T>::Pila() : tope_(-1) {}

template <typename T>
bool Pila<T>::vacia() const
{
    return c.vacia();
}

template <typename T>
bool Pila<T>::llena() const
{
    return (tope_ == LMAX -1);
}

template <typename T>
const T& Pila<T>::tope() const
{
    return c.frente();
}

template <typename T>
void Pila<T>::pop()
{
    assert(!vacia());
    c.pop_front();
    --tope_;
}

template <typename T>
void Pila<T>::push(const T& x)
{
    assert(!llena());
    c.push_back(x);
    ++tope_;
}

#endif
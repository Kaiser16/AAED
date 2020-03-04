#ifndef PILA_VEC0_H
#define PILA_VEC0_H

const int LMAX = 100;

class Pila
{
public:
    typedef int tElemento;
    Pila();
    bool vacia() const;
    bool llena() const;
    const tElemento& tope() const;
    void pop();
    void push(const tElemento& x);
private:
    tElemento elementos[LMAX];
    int tope_;
};

#endif // PILA_VEC0_H
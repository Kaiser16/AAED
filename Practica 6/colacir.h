#ifndef COLA_CIR_H
#define COLA_CIR_H
#include <cassert>

template <typename T> class Cola
{
public:
    explicit Cola(size_t TamaMax);
    Cola(const Cola<T>& C);
    Cola<T>& operator =(const Cola<T>& C);
    bool vacia() const;
    bool llena() const;
    void pop();
    void push(const T& x);
    ~Cola();
private:
    T *elementos;
    int Lmax;
    int inicio,fin;
};

template <typename T>
Cola<T>::Cola(size_t TamaMax) : 
    elementos(new T[TamaMax + 1]), // + 1 para cola llena
    Lmax(TamaMax + 1),
    inicio(0),
    fin(TamaMax)
{}

template <typename T>
Cola<T>::Cola(const Cola<T>& C) : 
    elementos(new T[C.Lmax]),
    Lmax(C.Lmax),
    inicio(C.inicio),
    fin(C.fin)
{
    if(!C.vacia())
    {
        for(int i = inicio; i != (fin+1) % Lmax; i = (i + 1) % Lmax)
            elementos[i] = C.elementos[i];
    }
}

template <typename T>
Cola<T>& Cola<T>::operator =(const Cola<T>& C)
{
    if(this != &C)
    {
        if(Lmax != C.Lmax)
        {
            delete [] elementos;
            Lmax = C.Lmax;
            elementos = new T[Lmax];
        }
        inicio = C.inicio;
        fin = C.fin;
        if(!C.vacia())
        {
            for(int i = inicio; i != (fin + 1) % Lmax;i = (i + 1) % Lmax)
                elementos[i] = C.elementos[i];
        }
    }
    return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return ((fin + 1) % Lmax == inicio);
}

template <typename T>
inline bool Cola<T>::llena() const
{
    return ((fin + 2) % Lmax == inicio);
}

template <typename T>
inline void Cola<T>::pop()
{
    assert(!vacia());
    inicio = (inicio + 1) %Lmax;
}

template <typename T>
inline void Cola<T>::push(const T& x)
{
    assert(!llena());
    fin = (fin + 1) %Lmax;
    elementos[fin] = x;
}

template <typename T>
inline Cola<T>::~Cola()
{
    delete [] elementos;
}

#endif
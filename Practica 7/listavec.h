#ifndef LISTA_VEC_H
#define LISTA_VEC_H
#include <cassert>

template <typename T>
class Lista
{
public:
    typedef int posicion;
    explicit Lista(size_t TamaMax);
    Lista(const Lista<T>& l);
    Lista<T>& operator =(const Lista<T>& l);

    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const; //lectura
    T& elemento(posicion p); //lectura/escritura
    posicion buscar(const T& x) const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;
    ~Lista();
private:
    T *elementos;
    int Lmax;
    int n;
};

template <typename T>
inline Lista<T>::Lista(size_t TamaMax) : 
    elementos(new T[TamaMax]),
    Lmax(TamaMax),
    n(0)
{}

template <typename T>
Lista<T>::Lista(const Lista<T>& l):
    elementos(new T[l.Lmax]),
    Lmax(l.Lmax),
    n(l.n)
{}

template <typename T>
Lista<T>& Lista<T>::operator =(const Lista<T>& l)
{
    if(this != &l)
    {
        if(Lmax != l.Lmax){ 
            delete[] elementos;
            Lmax = l.Lmax;
            elementos = new T[Lmax];
        }
        n = l.n;
        for(Lista<T>::posicion p = 0; p < n; p++)
            elementos[p] = l.elemento[p];
    }
    return *this;
}

template <typename T>
void Lista<T>::insertar(const T& x,Lista<T>::posicion p)
{
    assert(p >= 0 && p <= n);//posicion valida
    assert(n < Lmax);//lista no llena
    for(Lista<T>::posicion q = n; q > p; q--)
        elementos[q] = elementos[q-1];
    elementos[p] = x;
    n++;
}

template <typename T>
void Lista<T>::eliminar(Lista<T>::posicion p)
{
    assert(p >= 0 && p < n);
    n--;
    for(Lista<T>::posicion q = p; q < n; q++)
        elementos[q] = elementos[q+1];
}

template <typename T> inline
const T& Lista<T>::elemento(Lista<T>::posicion p) const
{
    assert(p >= 0 && p < n); //posicion valida
    return elementos[p];
}

template <typename T>
inline T& Lista<T>::elemento(Lista<T>::posicion p)
{
    assert(p >= 0 && p < n);
    return elementos[p];
}

template <typename T>
typename Lista<T>::posicion Lista<T>::buscar(const T& x) const
{
    Lista<T>::posicion q = 0;
    bool encontrado = false;
    while(q < n && !encontrado)
    {
        if(elementos[q] == x)
            encontrado = true;
        else q++;
    }
    return q;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(Lista<T>::posicion p) const
{
    assert(p > 0 && p <= n);
    return p-1;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::anterior(Lista<T>::posicion p) const
{
    assert(p > 0 && p <= n);
    return p-1;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const
{return 0;}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const
{return n;}

template <typename T>
inline Lista<T>::~Lista()
{delete[] elementos;}

#endif
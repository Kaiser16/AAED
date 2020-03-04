#ifndef TADCOCINA_H_
#define TADCOCINA_H_
#include "listaenla.h"

class Cocina
{
private:
    struct Mueble
    {
        unsigned posicion;
        unsigned anchura;
        Mueble(unsigned p = 0, unsigned a = 0) : posicion(p), anchura(a) {};
    };
    unsigned longitud;
    Lista<Mueble> lmuebles;
public: 
    Cocina(unsigned l);
    bool comprobarMueble(const unsigned& anchura,const unsigned posicion) const;
    void InsertarMueble(const unsigned& anchura,const unsigned posicion);
    const Mueble devolverMueble(const Lista<Mueble>::posicion& p);
    const void eliminarMueble(const Lista<Mueble>::posicion& p);
    void moverMueble(const Lista<Mueble>::posicion& p);
    ~Cocina();
};

Cocina::Cocina(unsigned l) : longitud(l) {}

//Cabecera: Compureba que un mueble cabe en una determinada posicion
//Precondicion: Recibe un mueble con la anchura inicializada y una posicion 
//menor a la longitud de la cocina
//Postcondicion: Devuelve si es valido colocar el mueble en dicha posicion
bool Cocina::comprobarMueble(const unsigned& anchura,const unsigned posicion) const
{
    if(longitud > (posicion + anchura)) return false;
    bool esValido = true;
    Lista<Mueble>::posicion p = lmuebles.primera();
    if(p != lmuebles.fin())
    {
        while(p != lmuebles.fin())
        {
            if(lmuebles.elemento(p).posicion < posicion)
            {
                if((lmuebles.elemento(p).posicion + lmuebles.elemento(p).anchura) > posicion)
                    esValido = false;
            }
            else if((posicion + anchura) > lmuebles.elemento(p).posicion)
                esValido = false;
                  
            p = lmuebles.siguiente(p); 
        }
    }
    return esValido;
}
//Cabecera: Coloca el mueble en la cocina
//Precondicion: El mueble cabe en la posicion dada
//Postcondicion: Se coloca el mueble en la posicion dada
void Cocina::InsertarMueble(const unsigned& anchura,const unsigned posicion)
{
    assert(!comprobarMueble(anchura,posicion));
    Lista<Mueble>::posicion p = lmuebles.primera();
    if(p == lmuebles.fin())
    {
        lmuebles.insertar(Mueble(anchura,posicion),lmuebles.fin());
    }
    else
    {
        while(p != lmuebles.fin() && lmuebles.elemento(p).posicion <= posicion)
            p = lmuebles.siguiente(p);
        lmuebles.insertar(Mueble(anchura,posicion),p);
    }
}

//Cabecera: Devuelve el mueble de una poscion
//Precondicion: Recibe la posicion de un mueble existente
//Postcondicion: Devuelve el mueble de la posicion i-esima empezando por la izquierda
const Cocina::Mueble Cocina::devolverMueble(const Lista<Mueble>::posicion& p)
{
    return lmuebles.elemento(p);
}

//Cabecera: Quita un mueble de la cocina
//Precondicion: Recibe la posicion de un mueble
//Postcondicion: Se elimina el mueble de la posicion dada
const void Cocina::eliminarMueble(const Lista<Mueble>::posicion& p)
{
    lmuebles.eliminar(p);
}


//Cabecera: Quita un mueble de la cocina
//Precondicion: Recibe la posicion de un mueble
//Postcondicion: Se elimina el mueble de la posicion dada
void Cocina::moverMueble(const Lista<Mueble>::posicion& p)
{
    Lista<Mueble>::posicion q = lmuebles.siguiente(p);
    lmuebles.elemento(p).posicion = lmuebles.elemento(q).posicion - lmuebles.elemento(p).anchura;
}

Cocina::~Cocina()
{
    lmuebles.~Lista();
}
#endif
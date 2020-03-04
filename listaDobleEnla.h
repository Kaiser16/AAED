//
//  listaDobleEnla.h
//  ListaDoble
//
//  Created by JM on 07/09/2019.
//  Copyright © 2019 JM Heredia. All rights reserved.
//

#ifndef listaDobleEnla_h
#define listaDobleEnla_h
#include <cassert>

template <typename T> class Lista{
private:
	struct nodo
    {
        T elto;
        nodo *ant,*sig;
        nodo(T e,nodo* a = 0,nodo* s = 0) : elto(e), sig(a), ant(s){}
    };
	nodo *L_;
	void copiar(const Lista<T>&);
public:
	typedef nodo* posicion;
	Lista();
	Lista(const Lista<T>&);
	Lista<T> &operator=(const Lista<T>&);
	void insertar(const T&, posicion);
	void eliminar(posicion);
	T &elemento(posicion);
	const T &elemento(posicion) const;
	posicion buscar(const T&) const;
	posicion siguiente(posicion) const;
	posicion anterior(posicion) const;
	posicion primera() const;
	posicion fin() const;
	~Lista();
};

template <typename T>
void Lista<T>::copiar(const Lista<T> &L){
	L_ = new nodo(T());
	L_->ant = L_->sig = L_;
	nodo *q = L.L_->sig;
	while(q != L.L_){
		L_->ant = L_->ant->sig = new nodo(q->elto, L_->ant, L_);
		q = q->sig;
	}
}

template <typename T>
inline Lista<T>::Lista() : L_(new nodo(T())){L_->ant = L_->sig = L_;}

template <typename T>
inline Lista<T>::Lista(const Lista<T> &L) : L_(new nodo(T())){copiar(L);}

template <typename T>
Lista<T> &Lista<T>::operator=(const Lista<T> &L){
	if(this != &L){
		this->~Lista();
		copiar(L);
	}
}

template <typename T>
inline void Lista<T>::insertar(const T &x, posicion p){
	p->sig = p->sig->ant = new nodo(x, p, p->sig);
}

template <typename T>
void Lista<T>::eliminar(posicion p){
	assert(p->sig != L_);
	nodo *q = p->sig;
	p->sig = q->sig;
	p->sig->ant = p;
	delete q;
}

template <typename T>
inline const T& Lista<T>::elemento(posicion p) const{
	assert(p->sig != L_);
	return p->sig->elto;
}

template <typename T>
inline T& Lista<T>::elemento(posicion p){
	assert(p->sig != L_);
	return p->sig->elto;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::buscar(const T& x) const{
	nodo *q = L_;
	bool encontrado = false;
	while (q->sig != L_ && !encontrado)
		if (q->sig->elto == x)
			encontrado = true;
			else q = q->sig;
				return q;
}

template <typename T> inline
typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const{
	assert(p->sig != L_);
	return p->sig;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::anterior(posicion p) const{
	assert(p != L_);
	return p->ant;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const{return L_;}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const{return L_->ant;}

template <typename T>
Lista<T>::~Lista(){
	nodo* q;
	while (L_->sig != L_) {
		q = L_->sig;
		L_->sig = q->sig;
		delete q;
	}
	delete L_;
}

#endif /* listaDobleEnla_h */

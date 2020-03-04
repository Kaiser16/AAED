#include <iostream>
#include "ListaD.h"


struct funcion{
	funcion(){} 
	funcion(double i,double a=0):ini(i),alt(a){}
	double ini,alt;
};
bool operator == (const funcion& a, const funcion& b){
	return a.ini == b.ini;
}
class escalonada{ 
private:
	 Lista<funcion> list;
public :
	escalonada(){} 
	escalonada(funcion& f){ 
		list.insertar(f,list.primera());
	}
	void anadirsalto(double x,double y){
		funcion salto(x,y);
		bool encontrado = false;
		Lista<funcion>::posicion i = list.buscar(salto);
		if(i != list.fin()){
			list.elemento(i).alt = salto.alt;
		}
		else{
			if (salto.ini < list.elemento(list.primera()).ini){ 
					list.insertar(salto,list.primera());
					encontrado=true;
			}

			if(salto.ini > list.elemento(list.anterior(list.fin())).ini){
					list.insertar(salto,list.fin());
					encontrado= true;
				}

			for (i = list.primera(); i != list.anterior(list.fin()) && !encontrado; i = list.siguiente(i))
			{
				if(salto.ini >= list.elemento(i).ini  && salto.ini < list.elemento(list.siguiente(i)).ini){
					encontrado = true;
				}
			}
			if(encontrado) list.insertar(salto,list.siguiente(i));
			}
	}
		
	
	void eliminarescalon(double x){ 
		bool encontrado=false; 
		funcion salto(x);
		Lista<funcion>::posicion p;
		for(p=list.primera();!encontrado && p!=list.fin();p=list.siguiente(p)){
		
			if(salto.ini >= list.elemento(p).ini  && salto.ini < list.elemento(list.siguiente(p)).ini){
					encontrado = true;
			}
		}
		if(encontrado){
			list.eliminar(p);
		}
		else{
			if (salto.ini >= list.elemento(list.anterior(list.fin())).ini)
			{
				list.eliminar(list.anterior(list.fin()));
			}
		}
		
	}
	double valorenunpunto(double x){ 
		bool encontrado=false; 
		funcion salto(x);
		Lista<funcion>::posicion i;
		for (i = list.primera(); i != list.anterior(list.fin()) && !encontrado; i = list.siguiente(i))
			{
				if(salto.ini >= list.elemento(i).ini  && salto.ini < list.elemento(list.siguiente(i)).ini){
					return list.elemento(i).alt;
				}
			} 
		return 0; 
	}
	double valormin(){ 
		double min=list.elemento(list.primera()).alt; 
		for(Lista<funcion>::posicion p=list.siguiente(list.primera());p!=list.fin();p=list.siguiente(p)){
			if(list.elemento(p).alt<min)min=list.elemento(p).alt;
		} 
		return min; 
	}
	double valormax(){ 
		double max=list.elemento(list.primera()).alt; 
		for(Lista<funcion>::posicion p=list.siguiente(list.primera());p!=list.fin();p=list.siguiente(p)){ 
			if(list.elemento(p).alt>max) max=list.elemento(p).alt;
		} 
		return max;
	}

	void translacion(funcion f,double w,double z){
		Lista<funcion>::posicion p = list.buscar(f);
		double x,y;
		if(p != list.fin()){
			x = list.elemento(p).ini + w;
			y =  list.elemento(p).alt + z;
			list.eliminar(p);
			anadirsalto(x,y);
		}
	}

};


int main(int argc, char const *argv[])
{
	
	return 0;
}
#include "polinom.h"
#include <iostream>

polinomio operator+(const polinomio &a,const polinomio &b);

polinomio operator*(const polinomio &a,const polinomio &b);

polinomio operator-(const polinomio &a);

polinomio operator-(const polinomio &a, const polinomio &b);

polinomio derivada(polinomio a);

polinomio crear();
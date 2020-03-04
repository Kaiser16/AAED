#ifndef polinomioh

#define polinomioh

class polinomio
{
    public:
    polinomio(unsigned gradoMax);
    unsigned grado() const;
    double coeficiente(unsigned n) const;
    void coeficiente(unsigned n,double c);

    private:
    double* vec;
    unsigned gradMax;
    unsigned gradop;
};

#endif 
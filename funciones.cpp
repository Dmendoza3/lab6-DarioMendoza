#include "funciones.h"

funciones::funciones()
{

}

funciones::funciones(int gra)
{
    grado = gra;
}

void funciones::addC(int nCoeficiente)
{
    coeficientes.push_back(nCoeficiente);
    //coeficientes.insert(coeficientes.begin(), nCoeficiente);
}
/*ostream& funciones::operator<<(ostream& os, const funciones& f)
{
    int gr = grado;

    os << "f(x) = ";
    for(int i = 0; i < coeficientes.size(); i++)
    {
        os << coeficientes[i] << "x^" << grado << " + ";
        grado--;
    }

    return os;
}*/

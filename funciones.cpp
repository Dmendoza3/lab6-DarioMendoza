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

void funciones::clear()
{
	coeficientes.clear();
}

void funciones::set(funciones* nF)
{
	clear();
	grado = nF->grado;
	coeficientes = nF->coeficientes;
}

void funciones::set(funciones nF)
{
	clear();
	grado = nF.grado;
	coeficientes = nF.coeficientes;
}

void funciones::add(funciones nF)
{
	for(int i = 0; i < coeficientes.size(); i++)
	{
		coeficientes[i] += nF.coeficientes[i];
	}
}

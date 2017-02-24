#include <iostream>
#include <vector>

using namespace std;

#ifndef FUNCIONES_H
#define FUNCIONES_H

class funciones
{
    public:
        funciones();
        funciones(int);
        int grado;
        vector<int> coeficientes;
        void addC(int);

        //operadores
        friend ostream& operator<< (ostream& os, const funciones& f)
        {
            int gr = f.grado;

            os << "f(x) = ";
            for(int i = 0; i < f.coeficientes.size(); i++)
            {
                if(gr > 0)
                    os << f.coeficientes[f.grado - i] << "x^" << gr << " + ";
                else
                    os << f.coeficientes[f.grado - i];
                gr--;
            }

            return os;
        }

		funciones operator+(funciones* f)
		{
			int ma = (this->grado > f->grado)?this->grado:f->grado;
			funciones* menorF = (this->grado < f->grado)?this:f;
			funciones* mayorF = (this->grado >= f->grado)?this:f;
			funciones nF(ma);

			for(int i = 0; i <= ma; i++)
			{
				if(menorF->coeficientes.size() >= i)
					nF.addC(this->coeficientes[i] + f->coeficientes[i]);
				else
					nF.addC(mayorF->coeficientes[i]);
					
			}
	
			return nF;
		}
		
		funciones operator-(funciones* f)
		{
			int ma = (this->grado > f->grado)?this->grado:f->grado;
			funciones* menorF = (this->grado < f->grado)?this:f;
			funciones* mayorF = (this->grado >= f->grado)?this:f;
			funciones nF(ma);

			for(int i = 0; i <= ma; i++)
			{
				if(menorF->coeficientes.size() >= i)
					nF.addC(this->coeficientes[i] - f->coeficientes[i]);
				else
					nF.addC(mayorF->coeficientes[i]);
					
			}

			return nF;
		}
		
		funciones operator*(funciones* f)
		{
			int nGr = this->grado * f->grado;
			funciones nF(nGr);

			for(int i = 0; i < this->coeficientes.size(); i++)
			{
				int nVal = 1;
				for(int j = 0; j < f->coeficientes.size(); j++)
				{
					nVal += this->coeficientes[i] * f->coeficientes[j];
				}	
				nF.addC(nVal);
			}

			return nF;
		}

		bool operator==(funciones* f)
		{
			if(this->grado != f->grado)
				return false;

			for(int i = 0; i < this->coeficientes.size(); i++)
			{
				if(this->coeficientes[i] != f->coeficientes[i])	
					return false;
			}
			
			return true;
		}
		
		bool operator!=(funciones* f)
		{
			if(this->grado != f->grado)
				return true;

			for(int i = 0; i < this->coeficientes.size(); i++)
			{
				if(this->coeficientes[i] != f->coeficientes[i])	
					return true;
			}
			
			return false;
		}
};
#endif

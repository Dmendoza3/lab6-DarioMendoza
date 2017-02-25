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
		void set(funciones*); //Copy
		void set(funciones); //Copy
		void add(funciones);
		void clear();

		
int isPrime (int num) {
    int nPrime = num + 1;
    int pCounter = 0;
    bool primeFound = false;
    while (primeFound == false) {
        for (int i = 2; i < nPrime; i++) {
            if (nPrime % i == 0) {
                pCounter++;
                break;
            }
        }
		
        if (pCounter == 0) {
            primeFound = true;
            pCounter = 0;
            return nPrime;
        } else {
       		nPrime++;
        	pCounter = 0;
        }
    }
    return 0;
}


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
		
		funciones operator+(funciones f2)
		{
			funciones* f = &f2;
			
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
					nF.addC(-mayorF->coeficientes[i]);
					
			}

			return nF;
		}
		
		int operator++()
		{
			int c = 1;
			int ma;
		
			for(int i = 0; i < this->coeficientes.size(); i++)
			{
				if(i == 0)
					ma = this->coeficientes[i];
				else
					if(ma < this->coeficientes[i])
						ma = this->coeficientes[i];
			}

			cout << "mayor es:" << ma << endl;

			int prm = isPrime(c);
			while(prm <= ma)
			{
				int i = 0;
				for(i = 0; i < this->coeficientes.size(); i++)
				{
					if(this->coeficientes[i] % isPrime(c) != 0)
					{
						c++;
						prm = isPrime(c);
						break;
					}
				}
				if(i == this->coeficientes.size())
					return prm;
			}
			return -1;
		}

		funciones operator*(int val)
		{
			funciones nF;
			nF.set(this);
			for(int i = 0; i < this->coeficientes.size(); i++)
				nF.coeficientes[i] *= val;

			return nF;
		}

		funciones operator*(funciones* f)
		{
			int ma = (this->grado > f->grado)?this->grado:f->grado;
			int nGr = this->grado * f->grado;
			funciones nF(nGr);
			funciones tempff;
			tempff.grado = nGr;
			cout << "\nnot yet";

			for(int i = 0; i < f->coeficientes.size(); i++)
			{
				//int nVal = 0;
				tempff.clear();
				for(int k = 0; k < tempff.grado - ma; k++)
				{
					tempff.coeficientes.push_back(0);
				}
				
				/*for(int j = 0; j < this->coeficientes.size(); j++)
				{
					//funciones temptempF;
					//temptempF.set(tempF*this->coeficientes[j]);
					cout << "Set";
					tempF.set(tempF * (this->coeficientes[j]));
					//nVal += this->coeficientes[i] * f->coeficientes[j];
				}*/
				cout << "add";
				nF.set(nF + tempff);
				tempff.grado++;
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

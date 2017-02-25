#include "funciones.h"

int main()
{
    vector<funciones*> func;
	vector<funciones> resultados;
    int op = 0;

    while(true)
    {
        cout << "0. Agregar una funcion\n"
        <<      "1. Sumar\n"
        <<      "2. Restar\n"
        <<      "3. Multiplicar\n"
        <<      "4. Dividir\n"
        <<      "5. Factor comun\n"
        <<      "6. Evaluar iguales\n"
        <<      "7. Evaluar diferentes\n"
        <<      "8. Imprimir funcion\n"
		<<		"10. Resultados\n"
        <<      "9. Salir\n->:";
		
        cin >> op;

        switch(op)
        {
            case 0:{
                int gr;
                cout << "Ingrese el grado(2-5): ";
                do{
                    cin >> gr;
                }while(gr > 5 || gr < 2);

                func.push_back(new funciones(gr));

                for(int i = 0; i <= func.back()->grado; i++)
                {
                    int tmp;
                    cout << "Ingrese el coeficiente para el grado x^" << i << ": ";
                    cin >> tmp;

                    func.back()->addC(tmp);
                }
                break;
            }

            case 1:{
				int ind1, ind2;
				//funciones* f1, f2;
				cout << "Ingrese los dos indices de las funciones a sumar: ";
				do{
					cin >> ind1 >> ind2;
				}while(ind1 < 0 || ind2 < 0 || ind1 >= func.size() || ind2 >= func.size());

				//cout << (*func[ind1] + func[ind2]) << endl;
				resultados.push_back( (*func[ind1] + func[ind2]) );
				cout << resultados.back() << endl;
                break;
            }

            case 2:{
				int ind1, ind2;
				//funciones* f1, f2;
				cout << "Ingrese los dos indices de las funciones a restar: ";
				do{
					cin >> ind1 >> ind2;
				}while(ind1 < 0 || ind2 < 0 || ind1 >= func.size() || ind2 >= func.size());

				//cout << (*func[ind1] - func[ind2]) << endl;
				resultados.push_back( (*func[ind1] - func[ind2]) );
				cout << resultados.back() << endl;
                break;
            }

            case 3:{
				cout << (*func[0]) * func[0];
				/*int ind1, ind2;
				//funciones* f1, f2;
				cout << "Ingrese los dos indices de las funciones a multiplicar: ";
				do{
					cin >> ind1 >> ind2;
				}while(ind1 < 0 || ind2 < 0 || ind1 >= func.size() || ind2 >= func.size());
				
				resultados.push_back( (*func[ind1] * func[ind2]) );
				cout << resultados.back() << endl;*/
				cout << "No implementado";
                break;
            }

            case 4:{

                break;
            }

            case 5:{
                int ind;
                cout << "Ingrese el indice de la funcion: ";
				
				do{
					cin >> ind;
				}while(ind < 0 || ind >= func.size());

                cout << "El factor comun es: " << ++(*func[ind]) << endl;
                break;
            }

            case 6:{
				int ind1, ind2;
				//funciones* f1, f2;
				cout << "Ingrese los dos indices de las funciones a comparar(==): ";
				do{
					cin >> ind1 >> ind2;
				}while(ind1 < 0 || ind2 < 0 || ind1 >= func.size() || ind2 >= func.size());

				cout << ((*func[ind1] == func[ind2])?"Verdadero":"Falso") << endl;
                break;
            }

            case 7:{
				int ind1, ind2;
				//funciones* f1, f2;
				cout << "Ingrese los dos indices de las funciones a comparar(!=): ";
				do{
					cin >> ind1 >> ind2;
				}while(ind1 < 0 || ind2 < 0 || ind1 >= func.size() || ind2 >= func.size());

				cout << ((*func[ind1] != func[ind2])?"Verdadero":"Falso") << endl;
                break;
            }

            case 8:{
                int ind;
                cout << "Ingrese el indice de la funcion: ";
				
				do{
					cin >> ind;
				}while(ind < 0 || ind >= func.size());

                cout << *(func[ind]) << endl;
                break;
            }

			case 10:{
				cout << endl;
				for(int i = 0; i < resultados.size(); i++)
					cout << i + 1 << ") "<< resultados[i] << endl;
				break;
			}
			
            case 9:{
                return 0;
                break;
            }
            default:{
                cout << "Error\n";
            }
        }
    }

	for(int i = 0; i < func.size(); i++)
	{
		delete func[i];
	}
	func.clear();
	
    return 0;
}

#include <iostream>
#include <list>
using namespace std;
/**
Ejercicio 12- Guía 2 (TADs)
Compacta. Escribir una función void compacta(list<int> &L,list<int> &S) que toma 
un elemento entero n de S y, si es positivo, saca n elementos de L y los reemplaza
por su suma. Esto ocurre con todos los elementos de S hasta que se acaben, o bien 
se acaben los elementos de L.
**/


void show_list(list<int> &L){
	cout<<"(";
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<" ";
	}
	cout<<")";
}
void compacta(list<int> &L, list<int> &S){
	list<int>::iterator itL = L.begin();
	list<int>::iterator itS = S.begin();
	
	while(itL != L.end() && itS != S.end()){	//ninguno de los dos iteradores deben apuntar al end() 
		
		if(*itS > 0){
			int suma = 0;
			for(int i=0;(itL != L.end() && i<*itS);i++) { 
				suma += *itL; 			//acumulo los valores de itL, itS-veces.
				itL = L.erase(itL);		/**lo elimino y deja apuntando al supuesto 
											siguiente elemento, por lo tanto no 
											hace falta incrementar itL**/
			}
			itL = L.insert(itL,suma);	//insertar la suma.
			itL++; 	//avanza itL para acumular en la siguiente posición
			itS = S.erase(itS);		//pide eliminar los elementos de S la lista de sumas
		}
		else{
			itS++; 	//avanza 
		}
	}
}
int main() {
	list<int> L = {1,3,6,2,8,2,3,2,3,10,1,4,5,7,6,-3};
	list<int> S = {3,2,4,1,3,3};
	//queria L = {10, 10 ,10 ,10 ,10,10};
	
	compacta(L,S);
	
	show_list(L);
	
	return 0;
}








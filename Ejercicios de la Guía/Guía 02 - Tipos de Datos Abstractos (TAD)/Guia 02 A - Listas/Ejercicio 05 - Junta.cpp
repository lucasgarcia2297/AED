#include <iostream>
#include <list>
using namespace std;
/**	Ejercicio 05 - Guia 2 (TADs)
Junta. Escribir una función void junta(list<int> &L, int c) que, dada una lista L,
agrupa de a c elementos, dejando su suma in place. Por ejemplo, si se le pasa como
argumento la lista L=(1,3,2,4,5,2,2,3,5,7,4,3,2,2), después de aplicar el algoritmo
junta(L,3) debe quedar L=(6,11,10,14,4) (notar que se agrupan los últimos elementos,
pese a no completar los tres requeridos). El algoritmo debe tener un tiempo de 
ejecución O(n).
**/
void show_list(list<int> &L){
	cout<<"( ";
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<" ";
	}
	cout<<" )";
}
void junta(list<int> &L, int c){
	list<int>::iterator it = L.begin();
	while(it != L.end()){
		auto it2 = it++;  //it2 apunta al primero e it apunta al siguiente
		for(int i=1; (it!=L.end() && i<c) ; i++) { 
			*it2 += *it;  //cuando el algoritmo debe ser in-place se puede acumular los valores en un iterador
			it++;	//apunta a la siguiente posición
		}
		it = L.erase(++it2,it); //elimina desde la posición siguiente e de it2 hasta it(sin incluirlo)
								//it se actualiza y apunta a la posicion siguiente al ultimo elemento eliminado 
	}
	
} 


int main() {
//main para junta:
	int c;
	cout<<"Ingrese c: ";
	cin>>c;
	list<int> L = {1,3,2,4,5,2,2,3,5,7,4,3,2,2};
	junta(L,c);
	
	show_list(L);
	return 0;
}








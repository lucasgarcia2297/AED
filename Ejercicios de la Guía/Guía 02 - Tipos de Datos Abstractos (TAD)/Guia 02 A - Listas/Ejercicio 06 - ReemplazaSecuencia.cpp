#include <iostream>
#include <list>
using namespace std;
/**	Ejercicio 06 - Guia 2(TADs)
ReemplazaSecuencia. Dada una lista de enteros L y dos listas SEQ y REEMP, 
posiblemente de distintas longitudes, escribir una función 
void reemplaza(list<int> &L, list<int>& SEQ, list<int> &REEMP), que busca todas
las secuencias de SEQ en L y las reemplaza por REEMP. Por ejemplo, 
si L=(1,2,3,4,5,1,2,3,4,5,1,2,3,4,5), SEQ=(4,5,1) y REEMP=(9,7,3),
entonces despu´es de llamar a reemplaza(L,SEQ,REEMP), 
debe quedar L=(1,2,3,9,7,3,2,3,9,7,3,2,3,4,5). 
Para implementar este algoritmo primero buscar desde el principio 
la secuencia SEQ, al encontrarla, reemplazar por REEMP, luego seguir buscando 
a partir del siguiente elemento al ´ultimo de REEMP.
**/

template<class T> 
void show_list(list<T> &L){
	cout<<"( ";
	for(typename list<T>::iterator it=L.begin(); it!=L.end(); ++it ) { //cuando uso template debo usar typename
		cout<<*it<<" ";
	}
	cout<<" )";
}

//el tamaño de la lista seria el n. suponiendo que la lista tiene muchos elementos
//por cada elemento de la lista L, hacemos algunas operaciones que no dependen del tamaño de L
//por lo tanto el algoritmo es de O(n) (en el MEJOR CASO).
//aunque el peor caso es reemplazar todos los elementos por algo igual o mas grande que L
//en ese caso es orden n^2 (T_Peor = n^2).
void reemplaza(list<int> &L, list<int> &SEQ, list<int> &REEMP){
	list<int>::iterator it = L.begin();
	list<int>::iterator itSEQ = SEQ.begin();
	
	while(it!=L.end()){		//itera los n reemplazos
		
		list<int>::iterator itIni = it;
		while(itSEQ != SEQ.end() && it != L.end()){
			if(*it == *itSEQ){
				itSEQ++;
				it++;
			}else{
				itSEQ = SEQ.begin();
				it++;
				itIni = it;
			}
		}
		if(itSEQ == SEQ.end()){
			it = L.erase(itIni,it); //elimina el rango, refresco el iterador(aunque queda en la misma posicion)
			it = L.insert(it,REEMP.begin(),REEMP.end());	//inserta en donde elimine, y refresco en la 
//			advance(it,REEMP.size()); //avanzo hasta el final del elemento donde inserte para no entrar en un bucle
//			
//			//otra forma:NO por rangos
//			for(int x:REEMP){
//				it = L.insert(it,x);
//				it++;
//			}
			itSEQ = SEQ.begin();
		}
	}
}

int main() {
	list<int> L = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
	list<int> SEQ ={4,5,1};
	list<int> REEMP = {9,7,3};
	reemplaza(L,SEQ, REEMP);
	
	show_list(L);
	return 0;
}








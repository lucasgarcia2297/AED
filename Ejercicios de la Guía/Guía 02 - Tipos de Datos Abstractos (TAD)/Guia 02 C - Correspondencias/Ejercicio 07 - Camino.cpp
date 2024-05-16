#include <iostream>
#include <graphviz.hpp>
#include <list>
#include <map>
using namespace aed;
using namespace std;
/**	Ejercicio 07 - Guia 2c) TADs [Correspondencias]
Camino. Implemente la función 
		bool es_camino(map<int,list<int>> G, list<int> &L) 
	que recibe una lista L y determina si es o no camino en el grafo G.
	El grafo se representa como un mapa que relaciona cada vértice (clave)
	con la lista de sus vértices adyacentes (valor).
**/

///funcion auxiliar que nos dice si el elemento pertenece o no a la lista
bool es_vecino(list<int> &L, int nodo){
	list<int>::iterator it = L.begin();
	while( it != L.end()){
		if(*it == nodo) return true;
		it++;
	}
	return false;
}

bool es_camino(map<int,list<int>> G, list<int> &L) {
	list<int>::iterator itPrev = L.begin();
	list<int>::iterator it = ++L.begin();
	
	//si hay un solo elemento no es camino
	if(it == L.end() || L.empty())
		return false;
	
	//recorre el camino
	while(it != L.end()){
		//consultamos si *itPrev pertenece al grafo
		//consultamos si *it es vecino de *itPrev
		if(G.find(*itPrev) == G.end() || !es_vecino(G[*itPrev],*it)){	
			//si no se cumplen las condiciones, entonces L no es camino de G
			return false;
		}
		itPrev++;
		it++;
		
	}
	
	//es camino
	return true;
}
int main() {
	map<int, list<int>> G = {
		{1,{2,6}},
		{2,{1,3,4,5}},
		{3,{2,5,7}},
		{4,{2,6}},
		{5,{2,3}},
		{6,{1,4,7}},
		{7,{3,6}}
	};
	list<int> L = {1,2,3,7};
	cout <<"L es camino? "<<es_camino(G,L);
//	graph2dot(G);
	return 0;
}








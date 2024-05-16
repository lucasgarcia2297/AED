#include <iostream>
#include <map>
#include <list>
using namespace std;
/**	Ejercicio 09 - Guia 2c) TADs [Correspondencias]
isHamilt. Dado un grafo map<int, list<int> >G y una lista de vértices 
	list<int> L determinar si L es un camino hamiltoniano en G.
**/


///Funcion auxiliar para ver si el nodo esta dentro de la lista
bool es_vecino(list<int> &L, int nodo){
	list<int>::iterator it = L.begin();
	while( it != L.end()){
		if(*it == nodo) return true;
		it++;
	}
	return false;
}
/** DEFINICIÓN: un camino es Hamiltoniano si pasa por todos los nodos 
				del grafo una sola vez (sin repeticiones),**/
bool isHamilt(map<int, list<int>> &G, list<int> &L){
	list<int>::iterator it = L.begin();
	
	//Condicion especial: grafo vacío
	//si el grafo está vacío, el unico camino hamiltoniano es el camino "vacío"
	if(it == L.end() && G.empty())
		return true;
	
	//verifica que todos los valores de L sean nodos de G
	while(it != L.end()){
		if(G.find(*it) == G.end()){	
			return false;
		}
		it++;
	}
	//verifica si L es camino Hamiltoniano
	list<int> visitados;
	
	it = L.begin();
	list<int>::iterator itNext;
	
	bool bandera = true;
	while(bandera){
		//si el nodo ya fue visitado, no es camino hamiltoniano
		if(es_vecino(visitados,*it)){	//"es vecino" o "pertenece" al la lista de visitados
		
		}else{
			visitados.push_back(*it);
		}
		itNext = it;
		itNext++;
		//verifica que el nodo siguiente no sea el endl
		if(itNext!= L.end()){
			//si el nodo siguiente no es vecino del nodo actual, no es camino
			if(!es_vecino(G[*it],*itNext))
				return false;
			it = itNext; 
		}else{
			//si el nodo siguiente es el end, corto el ciclo
			bandera = false;
		}
		
	}
	
	//si paso todas las condiciones y los tamños son iguales entonces retornara true
	return visitados.size() == G.size();
}
	
	
	
///OTRA FORMA:

///Funcion auxiliar para ver si hay duplicados
bool has_duplicates(list<int> L){
//	L.sort();
	list<int>::iterator it = L.begin();
	list<int>::iterator it1 = L.begin(); 
	++it1;
	while(it1 != L.end()){
		if(*it == *it1) return true;
		it==it1++;
	}
	return false;
}

///Funcion del ejercicio 7
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
bool isHamilt2(map<int, list<int>> &G, list<int> &L){
	list<int>::iterator it = L.begin();
	
	//Condicion especial: grafo vacío
	//si el grafo está vacío, el unico camino hamiltoniano es el camino "vacío"
	if(it == L.end() && G.empty()) return true;
	
	//verifica que la cantidad de nodos del camino sea la misma que la cantidad de nodos del grafo
	if(L.size() != G.size()) return false;
	
	//verificar que L no tenga elementos repetidos
	if(has_duplicates(L)) return false;
	
	//llamar al a funcion es_camino del ejercicio 7
	return es_camino(G,L);
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
	list<int> LH = {1,2,5,3,7,6,4};
	cout <<"LH es camino Hamiltoniano? "<<isHamilt2(G,LH);
	//	graph2dot(G);
	return 0;
}








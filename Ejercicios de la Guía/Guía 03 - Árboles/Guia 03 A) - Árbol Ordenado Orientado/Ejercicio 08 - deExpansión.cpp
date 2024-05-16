#include <iostream>
using namespace std;

/**
deExpansión Dado un grafo G, y un árbol T, decimos que T expande
	a G si la raiz n de T es un vértice de G, y los caminos de T
	permiten llegar desde n hasta cualquier otro nodo de G. 
	Escribir una función 
		bool es_arbol_de_expansion(graph G, tree<int> T) 
	que determina si T expande a G.
**/

typedef map<int, map<int, bool>> graph;
///FUNCIÓN AUXILIAR
bool es_arbol_de_expansion(graph G, tree<int> &T, tree<int>::iterator p){
	if(p == T.end()) return false;
	//bandera
	bool esExpansion = true; 	
	
	tree<int>::iterator Hijo_izq = p.lchild();
	while(Hijo_izq != T.end()){
		if(G[*p].find(*Hijo_izq) == G[*p].end() || !esExpansion){
			return	false;
		}
		esExpansion = es_arbol_de_expansion(G,T,Hijo_izq++);
	}
	return esExpansion;
}

///WRAPPER
bool es_arbol_de_expansion(graph G, tree<int> T){
	if(T.begin() == T.end()) return false;
	tree<int>iterator p = T.begin();
	if(G.find(*p) == G.end()) return false;
	return es_arbol_de_expansion(G,T,T.begin());
}
int main() {
	
	return 0;
}








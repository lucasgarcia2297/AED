#include <iostream>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/**	Ejercicio 03 - Guía 03a) [AOO]
Level Escribir una función int count_level(tree<int> &T, int l), 
	que cuente cuantos nodos hay en el nivel l del árbol T
**/
//NIVEL: Conjunto de todos los nodos que estan a una misma profundidad
//PROFUNDIDAD: longitud del único camino que va desde el nodo a la raiz

int count_level(tree<int> &T, tree<int>::iterator p, int &n, int l){
	int nnodos = 0;
	if(p == T.end()) return 0;
	if(n == l){
		--n;
		return 1;
	}
	tree<int>::iterator Hijo_izq = p.lchild();
	while(Hijo_izq != T.end()){
		nnodos += count_level(T,Hijo_izq++, ++n,l);
	}
	--n;
	return nnodos;
}
int count_level(tree<int> &T, int l){
	int n = 0;
	return count_level(T,T.begin(),n,l);
}

int main() {
	tree<int> T;
	lisp2tree("(1 (2 5)(3 6)(4 (7 (8 9 10))))",T);
	int l = 3;
	cout << "Cantidad de nodos en el nivel "<<l<<": "<<count_level(T,l);
//	tree2dot(T);
	return 0;
}








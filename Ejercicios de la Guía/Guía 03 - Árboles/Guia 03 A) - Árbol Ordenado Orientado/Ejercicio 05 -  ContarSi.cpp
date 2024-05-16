#include <iostream>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/** Ejercicio 05 - Guía 03a) [AOO]
ContarSi. Escribir una función 
		int count_if(tree<int> &T,bool (*pred)(int x)) 
	que retorna el número de nodos del árbol T que satisfacen el 
	predicado pred. Por ejemplo, si T=(1 2 (3 5 7 6) 4), entonces 
	count_if(T,odd) debe retornar 4. Escribir el predicado 
	bool odd(int x) que determina si un entero es impar.
**/
bool odd(int x){	//es impar?
	return x%2;		//si retorna 0 es falso, si retorna cualquier otro valor es verdadero
}
bool pos(int x){	
	return x>0;
}

///FUNCION AUXILIAR
int count_if(tree<int> &T, tree<int>::iterator n, bool (*pred)(int x)){
	if(n == T.end()) return 0;
	int count = pred(*n);	
	tree<int>::iterator hijo_izq = n.lchild();
	while(hijo_izq != T.end()){
		count += count_if(T,hijo_izq,pred);
		++hijo_izq;
	}
	return count;
}
int count_if(tree<int> &T, bool (*pred)(int x)){
	return count_if(T,T.begin(),pred);
}
int main() {
	tree<int> T;
	
	lisp2tree("(1 -2 (3 -5 7 6) 4)",T);
	int count = count_if(T,odd);
	int total_de_nodos_positivos = count_if(T,pos);
	tree2dot(T);
	cout <<"Cantidad de nodos impares: "<<count <<endl;
	cout <<"Cantidad de nodos positivos: "<<total_de_nodos_positivos <<endl;
	return 0;
}








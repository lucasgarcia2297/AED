#include <iostream>
#include <graphviz.hpp>
#include <lisp.hpp>
#include <tree.hpp>
#include <list>
using namespace aed;
using namespace std;
/** Ejercicio 07 - Guía 3a) [AOO]
list2tree Escribir una función 
		void list2tree(tree<int> &T,list<int> &L) 
	que dada una lista L con el orden previo de T y el tama˜no 
	de sus subárboles reconstruye T. La forma de almacenar el 
	árbol en T es la siguiente: se almacena en orden previo 2 
	valores enteros por cada nodo, a saber el contenido del nodo
	y el número de hijos. 
		Por ejemplo: Para el árbol (6 4 8 (5 4 4) 7 9) 
					tenemos L=(6 5 4 0 8 0 5 2 4 0 4 0 7 0 9 0). 
	Escribir también la función inversa 
		void tree2list(tree<int> &T,list<int> &L).
**/

///FUNCION AUXILIAR
tree<int>::iterator list2tree(tree<int> &T, tree<int>::iterator n, list<int> &L, list<int>::iterator &p){
	//Agrega el valor del nodo
	n = T.insert(n, *p);
	
	//avanza el iterator para obtener la cantidad de hijos a procesar
	++p;
	
	//guardo la cantidad de hijos del nodo
	int cantHijos = *p;
	++p;
	
	//reconstrucción de los hijos 
	tree<int>::iterator Hijo_izq = n.lchild();  //es un lamba
	
	for(int i=0;i<cantHijos;i++) { 
		Hijo_izq = list2tree(T,Hijo_izq, L, p);
		Hijo_izq++;
	}
	return n;
	
}
///FUNCION WRAPPER
void list2tree(tree<int> &T, list<int> &L){
	list<int>::iterator p = L.begin();
	list2tree(T,T.begin(),L,p); 
}

	
void show_list(list<int> L){
	cout <<"( ";
	for(auto x:L){
		cout <<x<<" ";
	}
	cout <<")"<<endl;
}
	
int main() {
	tree<int> T;
//	lisp2tree("(6 4 8 (5 4 4) 7 9)",T);
	
//	tree2dot(T);
	list<int> L = {6, 5, 4, 0,8, 0 ,5, 2, 4, 0, 4,0 ,7,0,9,0};
 	list2tree(T,L);
	tree2dot(T);
	return 0;
}








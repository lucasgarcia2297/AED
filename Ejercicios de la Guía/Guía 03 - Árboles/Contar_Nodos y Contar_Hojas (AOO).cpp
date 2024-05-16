#include <iostream>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <make_random.hpp>
using namespace aed;
using namespace std;

//FUNCION AUXILIAR
int contar_nodos(tree<int> &T, tree<int>::iterator nodo){
	if(nodo == T.end()) return 0;
	tree<int>::iterator hijo_izq = nodo.lchild();
	int c = 1; 
	while(hijo_izq != T.end()){
		c += contar_nodos(T, hijo_izq++); //llama a la recursion por hermano derecho 
	}
	return c;
}
//FUNCION WRAPPER
int contar_nodos(tree<int> &T){
	return contar_nodos(T, T.begin());
}

///FUNCION AUXILIAR
int contar_hojas(tree<int> &T, tree<int>::iterator nodo){
	if(nodo == T.end()) return 0;
	tree<int>::iterator hijo_izq = nodo.lchild();
	
	if(hijo_izq == T.end()) return 1;
	
	int c = 0; //arranco desde 0 porque podria no tener hojas
	while(hijo_izq != T.end()){
		c += contar_hojas(T,hijo_izq++);
	}
	return c;
}
///FUNCION WRAPPER
int contar_hojas(tree<int> &T){
	return contar_hojas(T, T.begin());
}

int main() {
	tree<int> T;
//	lisp2tree("(1 2 3 (4 (5 7 8 (9 10)) 6))",T);
//	lisp2tree("(a (b c))", T);
	int Nodos = 10, Cant_mayor_de_hijos = 7;
	make_random_tree(T, Nodos ,Cant_mayor_de_hijos);	//genera un arbol de 10
	
	cout << "Cantidad de nodos: "<<contar_nodos(T)<<endl;
	cout << "Cantidad de hojas: "<<contar_hojas(T)<<endl;
	tree2dot(T);
	
	return 0;
}








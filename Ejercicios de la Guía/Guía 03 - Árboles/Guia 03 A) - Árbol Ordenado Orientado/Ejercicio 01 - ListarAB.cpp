#include <iostream>
#include <list>
#include <make_random.hpp>
#include <tree.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/**	Ejercicio 01 - Guía 03 a) - [ARBOL ORDENADO ORIENTADO]
ListarAOO. Escribir procedimientos para listar un árbol ordenado 
	orientado siguiendo los ´ordenes prefijo y postfijo.
**/
template<class T>
void show_list(list<T> &L){
	cout <<"( ";
	for(auto x:L){
		cout << x<<" ";
	}
	cout <<" )"<<endl;
}

///FUNCION AUXILIAR
template<typename Q>
void prefijo(tree<Q> &T, typename tree<Q>::iterator nodo, list<Q> &L){
	if(nodo == T.end()) return;
	L.push_back(*nodo);
	typename tree<Q>::iterator hijo_izq = nodo.lchild();
	while(hijo_izq != T.end()){
		prefijo(T, hijo_izq++, L); //llama a recursividad con el 
	}
}
///FUNCION WRAPPER
template<typename Q>
list<Q> prefijo(tree<Q> &T){
	list<Q> pref;
	prefijo(T, T.begin(),pref);
	return pref;
}
	
///FUNCION AUXILIAR
template<typename Q>
void postfijo(tree<Q> &T, typename tree<Q>::iterator nodo, list<Q> &L){
	if(nodo == T.end()) return;
	typename tree<Q>::iterator hijo_izq = nodo.lchild();
	while(hijo_izq != T.end()){
		postfijo(T, hijo_izq++, L); //llama a recursividad con el 
	}
	L.push_back(*nodo);
}
///FUNCION WRAPPER
template<typename Q>
list<Q> postfijo(tree<Q> &T){
	list<Q> postf;
	postfijo(T, T.begin(),postf);
	return postf;
}


int main() {
	tree<int> T;
	//	lisp2tree("(1 2 3 (4 (5 7 8 (9 10)) 6))",T);
	//	lisp2tree("(a (b c))", T);
	int Nodos = 10, Cant_mayor_de_hijos = 7;
	make_random_tree(T, Nodos ,Cant_mayor_de_hijos);	//genera un arbol de 10
	
	list<int> Lpre = prefijo(T);
	list<int> Lpos = postfijo(T);
	
	cout << "PREFIJO: ";
	show_list(Lpre);
	cout <<endl;
	cout << "POSTFIJO: ";
	show_list(Lpos);
	tree2dot(T);
	
	return 0;
}








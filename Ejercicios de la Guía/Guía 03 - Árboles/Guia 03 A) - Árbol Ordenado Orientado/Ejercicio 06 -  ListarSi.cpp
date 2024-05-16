#include <iostream>
#include <tree.hpp>
#include <lisp.hpp>
#include <list>
using namespace aed;
using namespace std;
/**	Ejercicio 06 - Guía03a) [AOO]
ListarSi. Escribir una función 
		void list_if(tree<int> &T,list<int> &L, bool (*pred)(int x)) 
	que retorna en L la lista de valores nodales en orden previo de 
	un árbol ordenado orientado T que satisfacen el predicado pred. 
	Por ejemplo, si T=(1 (-2 7 (8 -7) (3 -5 -6))), entonces después 
	de list_if(T,L,positive), debe quedar L={1,7,8,3}. Escribir el 
	predicado bool positive(int x) que determina si un entero es
	mayor que 0.
**/
bool positive(int x){
	return x>0;
}

///FUNCION AUXILIAR
void list_if(tree<int> &T,tree<int>::iterator n, list<int> &L, bool (*pred)(int x)){
	if(pred(*n)){
		L.push_back(*n);
	}
	tree<int>::iterator hijo_izq = n.lchild();
	while(hijo_izq != T.end()){
		list_if(T,hijo_izq,L,pred);
		++hijo_izq;
	}
}
///WRAPPER
void list_if(tree<int> &T, list<int> &L, bool (*pred)(int x)){
	L.clear();
	if(T.begin() != T.end()){
		list_if(T,T.begin(),L,pred);
	}
}

void show_list(list<int> &L){
	cout << "[ ";
	for(auto x:L){
		cout << x << " ";
	}
	cout<<" ]"<<endl; 
}
int main() {
	tree<int> T;
	lisp2tree("(1 (-2 7 (8 -7) (3 -5 -6)))",T);
//	tree2dot(T);
	list<int> L;
	list_if(T, L, positive);
	cout << "Listado de nodos positivos: "<<endl; 
	show_list(L);
	return 0;
}








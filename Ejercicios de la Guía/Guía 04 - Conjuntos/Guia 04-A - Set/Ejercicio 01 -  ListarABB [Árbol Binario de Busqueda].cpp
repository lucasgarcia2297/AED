#include <iostream>
#include <btree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;
/**
listarABB. Programe una función 
		void listar_ABB(btree<int> &BT) 
	que muestre en orden ascendente los elementos del conjunto implementado 
	como ABB (Arbol Binario de Búsqueda).
**/
//Funcion Auxiliar
void listar_ABB(btree<int> &BT, btree<int>::iterator p) {
	if(p == BT.end()) return;
	listar_ABB(BT,p.left());
	cout <<*p<<" ";
	listar_ABB(BT,p.right());
}
//Funcion Wrapper
void listar_ABB(btree<int> &BT) {
	listar_ABB(BT,BT.begin());
}

int main() {
	btree<int> BT;
	lisp2btree("(5 (1 (2 . 4) 13) 7)",BT);
	btree2dot(BT);
	listar_ABB(BT);
	return 0;
}








#include <iostream>
#include <graphviz.hpp>
#include <lisp.hpp>
#include <btree.hpp>
using namespace aed;
using namespace std;
/**	Ejercicio 01: Guia 04b) [VARIOS: Arbol Binario de Busqueda]
listarABB. Programe una función 
		void listar_ABB(btree<int> &BT)
	que muestre en orden ascendente los elementos del conjunto implementado
	como ABB.
**/
//FUNCION AUXILIAR
void listar_ABB(btree<int> &BT, btree<int>::iterator n){ //seria como el orden simetrico
	if(n == BT.end()) return;
	
	listar_ABB(BT,n.left());
	cout << *n <<" ";
	listar_ABB(BT,n.right());
}
//WRAPPER
void listar_ABB(btree<int> &BT){
	return listar_ABB(BT, BT.begin());
}	
int main() {
	btree<int> BT;
	lisp2btree("(10 (7 . 9) (12 11 (15 14  16)))",BT);
	listar_ABB(BT);
	btree2dot(BT);
	return 0;
}








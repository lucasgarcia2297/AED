#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/**
insertaABB. Programe una función 
		void inserta_ABB(btree<int> &BT, int v) 
	que inserte v en la posición adecuada de BT que permita la construcción
	de un árbol binario de búsqueda.
**/
btree<int>::iterator findABB(btree<int> &BT, int v){
	btree<int>::iterator it = BT.begin();
	
	while(true){
		if(it == BT.end())
			return it;
		if(v<*it)
			it = it.left();
		else if(v>*it)
			it = it.right();
		else
			return it;
	}
}

void inserta_ABB(btree<int> &BT, int v) {
	btree<int>::iterator n = findABB(BT,v);
	if(n == BT.end()){ 
		BT.insert(n,v);
	}
}
int main() {
	btree<int> BT;
	lisp2btree("(10 (4 2 7) (12 11 (15 14  16)))",BT);
	int v = 12;
	inserta_ABB(BT,v);
	btree2dot(BT);
	return 0;
}








#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/**
eliminaABB. Programe una función 
		void elimina_ABB(btree<int> &BT, int v) 
	que elimina, si existe, el valor v del árbol binario BT de tal manera
	de preservar el ordenamiento del mismo.
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
void elimina_ABB(btree<int> &BT, int v) {
	btree<int>::iterator n = findABB(BT,v);
	if(n != BT.end()){
		
		if(n.left() == BT.end() && n.right() == BT.end())
			BT.erase(n);
		else if(n.right() == BT.end()){	//solo tiene hijo izquierdo
			btree<int> temp;
			temp.splice(temp.begin(),n.left());	//todo el subarbol del hijo izquierdo de pos y lo colocamos en temp
			n = BT.erase(n);
			BT.splice(n,temp.begin());
		}else if(n.left() == BT.end()){	//solo tiene hijo izquierdo
			btree<int> temp;
			temp.splice(temp.begin(),n.right());	//todo el subarbol del hijo izquierdo de pos y lo colocamos en temp
			n = BT.erase(n);
			BT.splice(n,temp.begin());
			temp.clear();
		}else{	//si tiene ambos hijos, elegir una estrategia ("mínimo de los máxximos")
			btree<int>::iterator minR = n.right();
			while(minR.left() != BT.end()){
				minR = minR.left();
			}
			int valorTemp = *minR;
			BT.erase(minR);
			*n = valorTemp;
		}
		
	}

}
int main() {
	btree<int> BT;
	lisp2btree("(10 (4 2 7) (12 11 (15 14  16)))",BT);
	int v = 12;
	elimina_ABB(BT,v);
	btree2dot(BT);
	return 0;
}








#include <iostream>
#include <list>
#include <tree.hpp>
using namespace aed;
using namespace std;
/**	Ejercicio 04
LevelList: El listado en orden de nivel de los nodos de un árbol 
	lista primero la raíz, luego todos los nodos de profundidad 1, 
	después todos los de profundidad 2, y así sucesivamente. 
	Los nodos que estén en la misma profundidad se listan en orden 
	de izquierda a derecha. Escribir una función 
		void orden_de_nivel (tree <int> &T) 
	para listar los nodos de un árbol en orden de nivel.
**/
template<typename Q>
list<list<Q>> orden_de_nivel (tree<Q> &T){
	list<list<Q>> LL;
	if(T.begin() != T.end()){
		int level = 0;
		while(count_level(T,level,) > 0){
			list<Q> L;
			listar_nivel(T,L,level++);
			LL.push_back(L);
		}
	}
	return LL;
}
	
void orden_de_nivel (tree <int> &T){
	
}

int main() {
	
	return 0;
}








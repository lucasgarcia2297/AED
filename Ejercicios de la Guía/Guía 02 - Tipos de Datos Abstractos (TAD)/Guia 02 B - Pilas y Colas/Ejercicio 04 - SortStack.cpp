#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;
/** Ejercicio 04 - Guia 2b: TADs - [Pilas y Colas]
SortStack. Escribir una función void sort(list<int> &L), que ordena los 
	elementos de L de mayor a menor. Para ello emplear el siguiente 
	algoritmo simple, utilizando una pila auxiliar P: ir tomando el menor 
	elemento de L, eliminarlo de L e insertarlo en P hasta que L este vacía.
	Luego insertar los elementos de P en L.
**/
void sortStack(list<int> &L){
	stack<int> P;
	while(!L.empty()){
		list<int>::iterator it = min_element(L.begin(),L.end());
		P.push(*it);
		L.erase(it);
	}
	while(!P.empty()){
		L.push_back(P.top());
		P.pop();
	}
}
void show_list(list<int> &L){
	cout <<"( ";
	for(auto x: L){
		cout << x<< " ";
	}
	cout <<" )"<<endl;
}
int main() {
	list<int> L = {3,4,5,-1,-15,-333,123,2};
	sortStack(L);
	show_list(L);
	return 0;
}








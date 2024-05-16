#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
/**
	Ejercicio 01 - Guía 2 (TADs):
BasicSort. Escribir una función void basic_sort(list<int> &L), que ordena los elementos 
de L de menor a mayor. Para ello emplear el siguiente algoritmo simple: utilizando 
una lista auxiliar L2, tomar el menor elemento de L, eliminarlo de L e insertarlo
al final de L2 hasta que L este vacía. Luego insertar los elementos de L2 en L.
**/

template<class T>
void show_list(list<T>& L){
	cout<<"(";
	for(auto it = L.begin();it!=L.end();it++){
		cout<<*it<<" ";		
	}
	cout<<")";
}

///no es "IN-PLACE" para que sea in place no necesitaria estructuras auxiliares
void basic_sort(list<int> &L){
	//utilizando una lista auxiliar L2
	list<int> L2;
	while(!L.empty()){
		//tomar el menor elemento de L
		list<int>::iterator it = min_element(L.begin(), L.end());
		//insertarlo al final de L2
		L2.push_back(*it);
		//eliinarlo de L
		it = L.erase(it);
	}
	//Luego insertar los elementos de L2 en L
	L = L2; ///O(1) ----->Con un for es O(n).
}

int main() {
	list<int> L = {1,45,3,2,7,8,32,11};
	basic_sort(L);
	show_list(L);
	return 0;
}








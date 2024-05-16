#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
/**
	Ejercicio 02 - Guía 2 (TADs):
SelectionSort. Escribir una función void selection_sort(list<int> &L), que ordena
los elementos de L de menor a mayor. Para ello debe tomarse el menor elemento de L
e intercambiarlo (swap) con el primer elemento de la lista. Luego intercambiar el 
menor elemento de la lista restante, con el segundo elemento, y as´i sucesivamente.
Esta función debe ser IN PLACE.
**/

void show_list(list<int> L){
	cout <<"(";
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<" ";
	}
	cout <<")";
}

void selection_sort(list<int> &L){   //orden n^2. lo bueno respecto al basic_sort es que este es IN -PLACE
	list<int>::iterator it= L.begin();
	while(it != L.end()) {
		//buscar menor elemento
		list<int>::iterator min = min_element(it,L.end());
		
		//usar swap()
		swap(*it, *min);
		it++;
	}
}
	
	
	//implementacion de un compañero
//	void SelectionSort(list<int> &L){//		list<int>::iterator itSelector;//		//		for(itSelector = L.begin(); itSelector!=L.end(); ++itSelector){//			list<int>::iterator itMenor = itSelector;//			for(list<int>::iterator it = itSelector ; it!=L.end(); ++it){//				if(*it < *itMenor) itMenor = it;//			}//			swap(*itSelector, *itMenor);//		}//	}

int main() {
	list<int> L = {1,4,6,2,4,8,9,33};
	
	selection_sort(L);
	
	show_list(L);
	
	return 0;
}








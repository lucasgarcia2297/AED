#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;
/**
SortQueue. Escribir una función void sort(list<int> &L), que ordena los 
	elementos de L de menor a mayor. Para ello utilizar el siguiente 
	algoritmo simple, utilizando una cola auxiliar C: ir tomando el menor
	elemento de L, eliminarlo de L e insertarlo en C hasta que L este vacía.
	Luego insertar los elementos de C en L.
**/
void sortQueue(list<int> &L){
	queue<int> Q;
	while(!L.empty()){
		list<int>::iterator it = min_element(L.begin(),L.end());
		Q.push(*it);
		L.erase(it);
	}
	while(!Q.empty()){
		L.push_back(Q.front());
		Q.pop();
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
	sortQueue(L);
	show_list(L);
	return 0;
}








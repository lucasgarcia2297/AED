#include <iostream>
#include <list>
#include <vector>
using namespace std;
/**	Ejercicio 08 - Guia 2 (TADs)
Ascendente2. Escribir una función void ascendente2(list<int> &L, vector<list<int>> &VL)
	que, dada una lista L, genera un vector de listas VL de tal forma de que cada 
	sublista es ascendente.
**/
void ascendente2(list<int> &L, vector<list<int>> &LL){
	if(L.empty()) return;
	//recorrer una lista generalmente es así
	list<int>::iterator it = L.begin();
	list<int>::iterator itIni = it;
	it++;	//arranco desde el segundo elemento
	while(it!=L.end()){
		list<int>::iterator itprev = prev(it);
		if(*it >= *itprev){
			//sigue siendo ascendente
			it++;
		}else{
			//dejo de ser ascendente
			list<int> sublista(itIni, it); /**equivale a list<int>L sublista;
			sublista.insert(sublista.begin(), itIni, it);
			**/
			LL.push_back(sublista);
			itIni = it;
			it++;
		}
	}
	//
	if(itIni != it){
		list<int> sublista(itIni, it);	//similar a hacer el insert despues de crear la lista
		LL.push_back(sublista);
	}
}

void show_list(list<int> &L){
	cout<<"(";
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<" ";
	}
	cout<<")";
}

int main() {
	list<int>L = {1,2,3,2,4,7,7,5,6,9};
	vector<list<int>> VL;
	//	VL = {{1,2,3},{2,4,7,7},{5,6,9}};
	ascendente2(L,VL);
	for(auto lista:VL){
		show_list(lista);
	}
	
	//Basicamente es igual a ascendente1 pero con un Vector de Listas
	return 0;
}
	







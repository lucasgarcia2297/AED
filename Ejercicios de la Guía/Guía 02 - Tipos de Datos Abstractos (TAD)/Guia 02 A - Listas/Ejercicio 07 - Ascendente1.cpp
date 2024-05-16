#include <iostream>
#include <list>
using namespace std;
/**	Ejercicio 07 - Guía 2 (TADs)
Ascendente1. Escribir una función void ascendente1(list<int> &L, list<list<int>> &LL)
	que, dada una lista L, genera una lista de listas LL de tal forma de que 
	cada sublista es ascendente.
**/
void ascendente1(list<int> &L, list<list<int>> &LL){
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
		list<int> sublista(itIni, it);	//inser
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
	list<list<int>> LL;
//	LL = {{1,2,3},{2,4,7,7},{5,6,9}};
	ascendente1(L,LL);
	for(auto lista:LL){
		show_list(lista);
	}
	return 0;
}








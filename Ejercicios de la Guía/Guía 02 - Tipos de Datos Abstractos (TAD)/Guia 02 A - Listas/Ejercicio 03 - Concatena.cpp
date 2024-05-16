#include <iostream>
#include <list>
using namespace std;
/**
	Ejercicio 03 - Guía 2 (TADs):
Concatena. Escriba procedimientos para concatenar: 
	a) dos listas L1 y L2 usando insert; 
	b) una lista LL de n sublistas usando insert; 
	c) una lista LL de n sublistas usando splice. 
Cada procedimiento debe retornar el resultado en una lista nueva.
**/

void show_list(list<int> L){
	cout <<"(";
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<" ";
	}
	cout <<")";
}

///Concatenar
///a) dos listas L1 y L2 usando insert;
//retornando una nueva lista.
list<int> concatA(list<int> &L1, list<int> &L2){
	list<int> L = L1;
//	
	
//	forma menos compacta(insert por elementos)
//		list<int>::iterator itL2 = L2.begin();
//		while(itL2!=L2.end()){
//			L.insert(L.end(),*itL2);
//			itL2++;
//		}
	
	//version compacta del insert (sin while);
	L.insert(L.end(), L2.begin(),L2.end());
	
	return L;
}
	
	
///Concatenar
///b) una lista LL de n sublistas usando inserter
void concatB(list<list<int>> &LL, list<int> &L){
	
//	LL = {{1,2,3},{5,6,7},{2,3,4}};
	list<list<int>>::iterator itLL = LL.begin(); //el iterador apunta a una sublista completa
	
	while(itLL!=LL.end()){
		list<int> &aux = *itLL;
		
		L.insert(L.end(),aux.begin(), aux.end());
		itLL++;
	}
}
	
///Concatenar c)
void concatC(list<list<int>> &LL, list<int> &L){
	for(list<int> Laux : LL){
		
		//("concatena" los elementos de toda la lista)
		//L.splice(L.end(),L.aux);
		
		//("concatena" los elementos por rangos)
		L.splice(L.end(),Laux,Laux.begin(),Laux.end());
	}
}

int main() {
	list<int> L1 = {1,2,3,4};
	list<int> L2 = {5,5,3};
	
//	list<int> L = concatA(L1,L2);
	
	list<int> L;
	list<list<int>> LL = {{1,2,3},{6,7,8},{6,5,4}};
	
//	concatB(LL,L);
	
	concatC(LL,L);
	
	show_list(L);
	return 0;
}








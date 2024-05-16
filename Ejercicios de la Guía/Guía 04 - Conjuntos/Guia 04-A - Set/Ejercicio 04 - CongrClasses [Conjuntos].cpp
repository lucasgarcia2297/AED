#include <iostream>
#include <set>
#include <list>
#include <iterator>
using namespace std;
/**	Ejercicio 04: Guia 04a) [CONJUNTOS] 
ClasesDeCongruencia. Dado un conjunto S implementar la función
		congrClasses(set<int> &S, int m,list<set<int>> &L) 
	que retorna las clases de congruencia módulo m en la lista list<set<int>> L.

**/
void congrClasses(set<int> &S, int m,list<set<int>> &L){
	set<int>::iterator itS = S.begin();
	L.resize(m);
	
	while(itS != S.end()) { 
		list<set<int>>::iterator itLS = L.begin();
		int resto = *itS % m;	//resto
		//resto = 2%3 = 2; 
		advance(itLS,resto);
		itLS->insert(*itS);
		itS++;
	}
} 
void show_set(set<int> &S){
	cout << "{";
	for(auto x:S){
		cout <<x<<" ";
	}
	cout <<"}"<<endl;
}
	
void show_list(list<set<int>> &L){
	cout << "{"<<endl;
	for( list<set<int>>::iterator it=L.begin(); it!=L.end(); ++it ) {
		show_set(*it);
	}
	cout <<"} "<<endl;
}
	
int main() {
	set<int> S = {1,2,3,4};
	int m = 3;
	list<set<int>> L;
/*	L = {
		{},	//Resto 0;
		{7,10},	//Resto 1;
		{2,5,8}	//Resto 2;
	}
*/
	congrClasses(S,m,L);
	show_list(L);
	
	return 0;
}








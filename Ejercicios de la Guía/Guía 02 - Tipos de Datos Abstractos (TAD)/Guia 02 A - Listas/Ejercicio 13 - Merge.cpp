#include <iostream>
#include <list>
using namespace std;
/** Ejercicio 13 - Guía 2a) TADs
Merge. Escribir una función void merge(list<int> &L1, list<int> &L2, list<int>& L)
	la cual recibe dos listas ordenadas (que pueden ser de distinto tama˜no)
	de forma ascendente L1 y L2 y retorna una lista L, pasada como parámetro,
	con los elementos de ambas ordenados también en forma ascendente. 
	Por ejemplo si L1=[1, 3, 6, 11] y L2=[2, 4, 6, 10], la lista L debe 
	quedar como L=[1, 2, 3, 4, 6, 6, 10, 11].
**/
void show_list(list<int> &L){
	cout <<"( ";
	for(auto x:L){
		cout<<x<<" ";
	}
	cout<<" )"<<endl;
}

void merge(list<int> &L1, list<int> &L2, list<int> &L){
	//iterator
	list<int>::iterator itL1 = L1.begin();
	list<int>::iterator itL2 = L2.begin();
	L.clear();
	
	//ciclo
	while(itL1 != L1.end() && itL2 != L2.end()){
		if(*itL1 < *itL2){
			L.push_back(*itL1);
			itL1++;
		}else{
			L.push_back(*itL2);
			itL2++;
		}
	}
	//"acomodar" L (si es necesario) 
	L.insert(L.end(),itL1, L1.end());
	L.insert(L.end(),itL2, L2.end());
}

int main() {
	list<int> L1 = {1,3,6,11};
	list<int> L2 = {2,4,6,10};
	list<int> L;
	
	merge(L1,L2,L);
	
	show_list(L);
	return 0;
}








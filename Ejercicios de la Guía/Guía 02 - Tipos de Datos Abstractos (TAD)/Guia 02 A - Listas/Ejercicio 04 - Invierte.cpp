#include <iostream>
#include <list>
using namespace std;
/**
	Ejercicio 04 - Guía 2 (TADs):
Invierte. Escribir una función void invert(list<int> &L), que invierte el orden 
de la lista L. Este algoritmo debe implementarse in place y debe ser O(n). 
Restricción: no utilizar el método size().
**/

void show_list(list<int> L){
	cout <<"(";
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<" ";
	}
	cout <<")";
}
	
void invert(list<int> &L){
	if(!L.empty()){
		list<int>::iterator Lini = L.begin(), Lfin = --L.end();
		
		while(Lini != Lfin ){
			swap(*Lini,*Lfin);
			Lini++;
			if(Lini != Lfin){
				//lista par
				//no se recomienda el break. la estructura iterativa debe repetirse hasta que sse cumpla la condicion
				--Lfin;
			}
			
		}
	}
}
int main() {
	list<int> L = {1,2,3,4,5,6,7};
//	list<int> L2 = 7,6,5};
	
	invert(L);
	
	show_list(L);
	return 0;
}








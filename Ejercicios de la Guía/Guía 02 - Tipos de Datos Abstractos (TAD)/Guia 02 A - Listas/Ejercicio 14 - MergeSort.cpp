#include <iostream>
#include <list>
using namespace std;
/**	Ejercicio 14 - Guía 2a) TADs
MergeSort. Programar una función void mergesort(list<int> &L) que reciba una
	lista L desordenada y la ordene en forma ascendente mediante la siguiente
	estrategia recursiva: Si la lista está vacía o tiene un sólo elemento ya
	está ordenada. Sino se parte la lista en dos sublistas y se las ordena a
	cada una de forma recursiva. Luego se mezclan (fusionan) cada una de las
	sublistas ya ordenadas. Para partir una lista puede utilizarse el método
	de la clase 
	list void list::splice(iterator position, list& x, iterator first, iterator last)
	el cual transfiere los elementos desde la lista x al contenedor que 
	realiza la llamada en la posición position. Se sugiere utilizar la 
	función merge(..) implementada en el punto anterior.
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

void mergesort(list<int> &L){
	//condiciones de corte
	if(L.size()<=1){
		return;
	}else{
		list<int> L1, L2;
		
		L1.swap(L);
		
		list<int>::iterator itL1 = L1.begin();
		for(size_t i=0;i<L1.size()/2;i++) {   
			itL1++;
		}
		L2.splice(L2.begin(),L1,itL1,L1.end());
		
		//hay que hacer un llamado a mergesort
		mergesort(L1);
		mergesort(L2);
		
		merge(L1,L2,L);
	}
}
	
///----Otra Forma----------------
void mergesort2(list<int> &L){
	if(L.size()<=1) return;
	
	list<int> L1;
	L1.splice(L1.begin(),L,L.begin());
	list<int> L2;
	L2.splice(L2.begin(),L);
	mergesort2(L2);
	merge(L1,L2,L);
}
int main() {
	list<int> L = {2,4,67,3,21,7,9,0,4,2,1,4,5,8,0,3,4};
	mergesort(L);
	show_list(L);
	
	cout <<endl;
	
	list<int> L2 = {2,4,67,3,21,7,9,0,4,2,1,4,5,8,0,3,4};
	mergesort2(L2);
	show_list(L2);
	return 0;
}








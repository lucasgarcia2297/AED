#include <iostream>
#include <list>
#include <set>
using namespace std;
/**
DiferenciaSimétrica. Dada una lista de conjuntos de enteros list<set<int>> L
	escribir una función void diffsym(list< set<int> > &L, set<int> &ad)
	que retorna en ad el conjunto de los elementos que pertenecen a uno y 
	sólo uno de los conjuntos de L. 
	Por ejemplo, si L = ({1,2,3},{2,4,5},{4,6}) entonces ad = {1,3,5,6}. 
	Notar que si el número de conjuntos en L es 2 y los llamamos A y B, 
	entonces debe retornar ad = (A-B)-unión-(B-A).
**/
///---------------------Funciones Auxiliares-------------------------------
void set_difference(set<int> &A,set<int> &B,set<int> &C){
	C.clear(); //siempre vaciar primero el conjunto que se va a retornar
	set<int>::iterator itA = A.begin(), itB = B.begin();
	
	while(itA != A.end() && itB != B.end()){
		if(*itA<*itB){
			C.insert(*itA);
			++itA;
		}else if(*itB<*itA){
			++itB;
		}
		else{
			++itA;	//incremento los dos
			++itB;
		}
	}
	while(itA != A.end()){
		C.insert(*itA);
		++itA;
	}
} 
void set_union(set<int> &A,set<int> &B,set<int> &C){
	C.clear();	//siempre vaciar primero el conjunto que se va a retornar
	set<int>::iterator itA = A.begin(), itB = B.begin();
	while(itA != A.end() && itB != B.end()){
		if(*itA<*itB){
			C.insert(*itA);
			++itA;
		}else if(*itB<*itA){
			C.insert(*itB);
			++itB;
		}
		else{
			C.insert(*itA); //inserto cualquiera de los dos
			++itA;	//incremento los dos
			++itB;
		}
	}
	
	while(itA != A.end()){
		C.insert(*itA);
		++itA;
	}
	
	while(itB != B.end()){
		C.insert(*itB);
		++itB;
	}
}
///------------------------------------------------------------------------

void diffsym(list<set<int>> &L, set<int> &ad){
	ad.clear();
	list<set<int>>::iterator it = L.begin();
	
	if(!L.empty()){
		ad = *it;
		++it;
	}
	
	while(it != L.end()){
		
		set<int> difBA, difAB;
		
		set_difference(ad,*it,difAB);
		set_difference(*it,ad,difBA);
		
		set_union(difAB,difBA,ad);
		
		++it;
	}
}
void show_set(set<int> &S){
	cout <<" (";
	for(auto x:S){
		cout << x << " ";
	}
	cout <<")"<<endl;
}

int main() {
	
	list<set<int>> L = {{1,2,3},{2,4,5},{4,6}};
	set<int> ad;
	diffsym(L,ad);
	show_set(ad);
	return 0;
}








#include <iostream>
#include <map>
#include <list>
using namespace std;
/**	Ejercicio 02 - Guía 2c) TADs [CORRESPONDENCIAS]
list2map. Escribir una función que dadas las listas de claves (k1,k2,k3, ...) 
	y valores (v1,v2,v3, ...) retorna el map M con las asignaciones 
	correspondientes { k1->v1, k2->v2, k3->v3, ...}. Utilice la signatura 
	void list2map(map<int,int> &M, list<int> &Keys, list<int> &Vals). 
	Nota: si hay claves repetidas, sólo debe quedar la asignación 
	correspondiente a la última clave en la lista. Si hay menos valores que
	claves utilizar cero como valor. Si hay m´as valores que claves, 
	ignorarlos.
**/
void show_map(map<int, int> &M){
	cout << "( ";
	for( map<int, int>::iterator it=M.begin(); it!=M.end(); ++it ) { 
		cout << it->first <<"->"<<it->second<<" ";
	}
	cout <<" )"<<endl;
}

void list2map(map<int, int> &M, list<int> &Keys, list<int> &Vals){
	list<int>::iterator itk = Keys.begin(), itv = Vals.begin();
	while(itk != Keys.end() && itv != Vals.end()){
		M[*itk] = *itv;
//		M.insert(pai<int,int> )	//
		itk++;
		itv++;
	}
	while(itk != Keys.end()){
		M[*itk] = 0;
		itk++;
	}
}
int main() {
	map<int,int> M;
	list<int> k = {1,2,3,4,5,6};
	list<int> v = {11,22,33,44,55};
	
	list2map(M,k,v);
	
	show_map(M);
	return 0;
}








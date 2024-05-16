#include <iostream>
#include <map>
#include <list>
using namespace std;
/** Ejercicio 01 - Guía 2c) TADs [CORRESPONDENCIAS]
map2list. Escribir una función que dado un map M retorna las listas de claves
	y valores, utilice la signatura 
		void map2list(map<int,int> &M, list<int> &Keys, list<int> &Vals).
Ejemplo: si M={1->2, 3->5, 8->20}, entonces debe retornar Keys = (1,3,8) y 
	Vals = (2,5,20).
**/
void map2list(map<int,int> &M, list<int> &Keys, list<int> &Vals){
	Keys.clear();
	Vals.clear();
	map<int,int>::iterator it = M.begin();
	while(it!=M.end()){
		Keys.push_back(it->first);
		Vals.push_back(it->second);
		it++;
	}
}
void show_list(list<int> &L){
	cout <<"( ";
	for(auto x:L){
		cout << x<< " ";
	}
	cout <<" )"<<endl;
}
int main() {
	map<int,int> M = {
		{9,2},
		{1,2},
		{3,4},
		{5,6},
		{7,8},
		{2,5}
	};
	list<int> k,v;
	
	map2list(M,k,v);
	
	cout <<"Claves: "<<endl;
	show_list(k);
	cout <<"Valores: "<<endl;
	show_list(v);
	return 0;
}








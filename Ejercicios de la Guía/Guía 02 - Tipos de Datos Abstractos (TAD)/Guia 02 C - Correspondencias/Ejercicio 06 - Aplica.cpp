#include <iostream>
#include <map>
#include <list>
using namespace std;
/**	Ejercicio 06 - Guía 2c) TADs [CORRESPONDENCIAS]
Aplica. Escribir una función 
		void apply_map(list<int> &L, map<int,int> &M, list<int> &ML) 
	que, dada una lista L y una correspondencia M retorna por ML una lista 
	con los resultados de aplicar M a los elementos de L. Si algún elemento
	de L no está en el dominio de M, entonces el elemento correspondiente de
	ML no es incluido. Por ejemplo, si L = (1,2,3,4,5,6,7,1,2,3) y 
	M= {(1,2),(2,3),(3,4),(4,5),(7,8)}, entonces, despu´es de hacer 
	apply_map(L,M,ML), debe quedar ML = {(2,3,4,5,8,2,3,4)}.
**/
void apply_map(list<int> &L, map<int,int> &M, list<int> &ML){
	ML.clear();
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		if(M.find(*it) != M.end())
			ML.push_back(M[*it]);
//		if(M.count(*it) == 0)	//otra forma con count
//			ML.push_back(M[*it]);
	}
}
void show_map(map<int, int> &M){
	cout << "( ";
	for( map<int, int>::iterator it=M.begin(); it!=M.end(); ++it ) { 
		cout << it->first <<"->"<< it->second<<" ";
	}
	cout <<" )"<<endl;
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
		{1,2},
		{2,3},
		{3,4},
		{4,5},
		{7,8}
	};
	list<int> L = {1,2,3,4,5,6,7,1,2,3}, ML;
	
	cout <<"L: "<<endl;
	show_list(L);
	cout <<"M: "<<endl;
	show_map(M);
	
	apply_map(L,M,ML);
	
	cout <<"ML: "<<endl;
	show_list(ML);
	return 0;
}








#include <iostream>
#include <set>
#include <vector>
using namespace std;
/** Ejercicio 05 - Guia4a) [CONJUNTOS]
CubreTodo. Escribir una funci”n predicado 
		cubre_todo(vector<set<T>>&v, set<T>& W)
	que verifica si todos los conjuntos en el vector de conjuntos v est·n
	incluidos en W.
**/

template<typename T>
bool cubre_todo(vector<set<T>>&v, set<T>& W){
	for(size_t i=0;i<v.size();i++) { 
		for(typename set<T>::iterator it=W.begin(); it!=W.end(); ++it ) {  
			if(v[i].find(*it) == v[i].end()) return false;
		}	
	}
	return true;
}
int main(){
	vector<set<char>> v = {{'a','b','c','s','v'},{'s','v','x','w','z'},{'c','s','v'},{'s','t','u','v','w'}};
	set<char> S = {'s','v'};
	cout << "Cubre todo? "<<cubre_todo(v,S);
	
	return 0;
}








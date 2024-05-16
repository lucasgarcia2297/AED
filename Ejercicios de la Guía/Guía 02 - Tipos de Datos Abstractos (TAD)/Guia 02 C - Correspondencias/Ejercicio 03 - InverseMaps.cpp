#include <iostream>
#include <map>
using namespace std;
/**	Ejercicio 03 - Guía 2c) TADs [CORRESPONDENCIAS]
InverseMaps. Dos correspondencias M1 y M2 son inversas una de la otra si 
	tienen el mismo número de asignaciones y para cada par de asignación 
	x->y en M1 existe el par y->x en M2. Escribir un predicado 
	bool areinverse(map<int,int> &M1, map<int,int> &M2); que determina si 
	las correspondencias M1 y M2 son inversas.
**/
bool areinverse(map<int,int> &M1, map<int,int> &M2){
	if(M1.size()!=M2.size()) return false;
	
	map<int,int>::iterator it1 = M1.begin();
	map<int,int>::iterator it2 = M2.begin();
	
	while(it1 != M1.end() && it2 != M2.end()){
		if(it1->first == it2->second && it1->second == it2->first){
			it1++;
			it2++;
		}else{
			return false;
		}
	}
	return true;
}
int main() {
	map<int, int> M1 = {
		{1,2},
		{3,4},
		{5,6}
	},
	M2 = {
		{2,1},
		{4,3},
		{6,5}
	};
	
	cout <<"Son inversas? "<<areinverse(M1,M2);
	return 0;
}








#include <iostream>
#include <vector>
#include <set>
using namespace std;
/**
Disjuntos. Escribir una función predicado 
		bool disjuntos(vector<set<T>>&v) 
	que verifica si todos los conjuntos Ai dentro del vector de conjuntos v
	son disjuntos de a pares, esto es: si Ai -distinto- Aj entonces 
	Ai -interseccion- Aj = {conjunto vacío}.
**/

///Funcion auxiliar
void set_intersection(set<int> &A,set<int> &B,set<int> &C){
	C.clear(); //siempre vaciar primero el conjunto que se va a retornar
	set<int>::iterator itA = A.begin(), itB = B.begin();
	
	while(itA != A.end() && itB != B.end()){
		if(*itA<*itB){
			++itA;
		}else if(*itB<*itA){
			++itB;
		}
		else{
			C.insert(*itA); //inserto cualquiera de los dos
			++itA;	//incremento los dos
			++itB;
		}
	}
	
}

bool disjuntos(vector<set<int>> &v){
	int n = v.size();
	
	for(int i=0;i<n-1;i++) { 
		for(int j=i+1;j<n;j++) { 
			set<int> temp;
			set_intersection(v[i],v[j],temp);
			if(!temp.empty())
				return false;
		}
	}
	return true;
}


int main() {
	vector<set<int>> vs ={{1,2},{3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
	cout <<"Los conjuntos son disjuntos? "<<disjuntos(vs);
	return 0;
}








#include <iostream>
#include <vector>
#include <set>
using namespace std;
/**	Ejercicio 06: Guia 4a) [CONJUNTOS]
IncluyeTodo. Dados n conjuntos A0, A1, ... An-1 determinar si alguno de
	ellos (digamos Aj) incluye a todos los otros. Es decir Aj-incluye-Ak 
	para todo k. En ese caso, retornar el indice j, si no retornar -1.
	Signatura: int includes_all(vector< set<int> > &setv).
**/
bool cubre_todo(vector<set<int>> &v, set<int> &S){
	for(size_t i=0;i<v.size();i++) { 
		for( set<int>::iterator it=S.begin(); it!=S.end(); ++it ) { 
			if(v[i].find(*it)==v[i].end())
				return false;
		}
	}
	return true;
}

int includes_all(vector< set<int> > &setv){
	for(size_t i=0;i<setv.size();i++) { 
		if(cubre_todo(setv,setv[i])){
			return i;
		}
	}
	return -1;
}
int main() {
	vector<set<int>> vs = {
		{1,2,4,44},		//A0
		{1,2,3,4,5,9},	//A1
		{1,2,4,8,90},	//A2
		{1,2,4,5,6,7},	//A3
		{1,2,4},		//A4
		{1,2,3,4,45,200}//A5
	};
	int j = includes_all(vs);
	cout << "Conjunto que esta incluido en todos: A"<<j;
	return 0;
}








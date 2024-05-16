#include <iostream>
#include <list>
#include <vector>
using namespace std;
/**
Sea vector<list<int>> M un vector de listas que almacena los coeficientes 
de una matriz A de m*n entradas, es decir A 2 IRmxn, donde la lista M[j]
contiene la fila j-1 (el -1 viene de la base 0 de C++). Escribir una 
función void transpose(vector<list<int>> &M,vector<list<int> > &Mt); 
que retorna los coeficientes de la matriz transpuesta es decir la lista
Mt[j] contiene la columna j-1.Por ejemplo: si M=[(11,12,13),(21,22,23)] entonces transpose(M,Mt) debe dar:Mt=[(11,21),(12,22),(13,23)].

**/
void transpose(vector<list<int>> &M,vector<list<int> > &Mt){
	int m = M.size();
	int n = M[0].size();	//El indice representa las columnas
	Mt.clear();
	Mt.resize(n);
	
	for(int i=0;i<m;i++) { 
		list<int>::iterator itM = Mt[i].begin();
		for(int j=0;j<n;j++) { 
//			Mt[j][i] = M[i][j]	//si fuera vector de vectores
			
			//Una forma:
			list<int>::iterator it = advance(Mt[j].begin(),i);
			list<int>::iterator jt = advance(Mt[i].begin(),j);
			*it = *jt;
			
			//Otra forma:
//			Mt[j].push_back(*itM);
//			itM++;
		}
	}
}

void show_list(list<int> &L){
	cout <<"(";
	for(auto x:L){
		cout << x << " ";
	}
	cout << " )"<<endl;
}

int main() {
	vector<list<int>> VL = {{2,2,2},{1,1,1},{3,3,3}};
	vector<list<int>> ML;
//	transpose(VL,ML);
	for(auto x:ML){
		for(auto y:x){
			cout << y<< " "; 
		}
		cout <<endl;
	}
	return 0;
}








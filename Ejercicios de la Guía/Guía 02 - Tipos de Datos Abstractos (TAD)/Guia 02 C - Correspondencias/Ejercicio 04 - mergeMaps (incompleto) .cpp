#include <iostream>
#include <list>
#include <map>
using namespace std;
/** Ejercicio 04 - Guía 2c) TADs
mergeMap. Dadas dos correspondencias A y B, que asocian enteros con listas
	ordenadas de enteros, escribir una función 
	void merge_map(map<int, list<int>> &A, map<int, list<int>> &B, map<int, list<int>> &C)
	que devuelve en C una correspondencia que asigna al elemento x la fusión 
	ordenada de las dos listas A[x] y B[x]. Si x no es clave de A, 
	entonces C[x] debe ser B[x] y viceversa. Sugerencia: utilice la 
	función merge implementada en uno de los ejercicios anteriores.
**/

//Merge de listas
void merge(list<int> &L1, list<int> &L2, list<int>& L) {	auto p = L1.begin();	auto q = L2.begin();	while ( p!= L1.end() and q != L2.end() ){				if ( *p > *q ){			L.insert(L.end(),*q);			q++;		}				if ( *p < *q ){			L.insert(L.end(),*p);			p++;		}						if ( *p == *q ){			L.insert(L.end(),*p);			p++;			q++;		}	}		if ( p == L1.end() and q != L2.end()){		L.insert(L.end(),q,L2.end());	}else{		L.insert(L.end(),p,L1.end());	}}	

void merge_map(map<int, list<int>> &A, map<int,list<int>> &B, map<int, list<int>> &C){	auto p = A.begin();	auto q = B.begin();	while ( p != A.end() and q != B.end() ){		list<int> aux;		//asigna al elemento x la fusion ordenada de las dos listas A[x] y B[x]		//		if ( p->first == q->first ){		//			merge(p->second,q->second,aux);		//			C[p->first]=aux;		//		}				if ( A.find(q->first) != A.end() and B.find(p->first) != B.end() ){			merge(p->second,q->second,aux);			C[p->first]=aux;		}		//		Si x no es clave de A, entonces C[x] debe ser B[x];		if ( A.find(q->first) == A.end() and B.find(q->first) != B.end() ){			C[q->first] = q->second;		}		//		Si x no es clave de B, entonces C[x] debe ser A[x];		if( B.find(p->first) == B.end() and A.find(p->first) != A.end() ){			C[p->first] = p->second;					}		q++;		p++;	}
	
	while(p!= A.end()){
		C[p->first] = p->second;
	}
	while(q!= B.end()){
		C[q->first] = q->second;
	}	}

void show_list(list<int> L){
	cout << " ( ";
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		cout << *it <<" ";
	}
	cout <<" )"<<endl;
}
template<class T,class C>
void show_map(map<T, C> &M){
	cout << "( ";
	for( map<T,C>::iterator it = M.begin(); it!=M.end(); ++it ) { 
		cout << it->first <<"->"; show_list(it->second);
	}
	cout <<" )"<<endl;
}
	
int main() {
	list<int> L1={1,2,3};	list<int> L2={4,5,6};	list<int> L3={7,8,9};	list<int> L4={10,11,12};	list<int> L5={13,14,15};	list<int> L6={16,17,18};		map<int,list<int>> A = {{0,L1},{2,L2},{4,L3},{5,L4},{7,L5},{10,L6}};	map<int,list<int>> B = {{1,L4},{3,L6},{5,L1},{6,L2},{7,L3},{9,L5}};
	map<int,list<int>> C;
	
	merge_map(A,B,C);
	return 0;
}








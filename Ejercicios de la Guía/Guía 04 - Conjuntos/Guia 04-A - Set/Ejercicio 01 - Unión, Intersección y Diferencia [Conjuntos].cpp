#include <iostream>
#include <set>
using namespace std;
/**	Ejercicio 01 - Guia 4a) [CONJUNTOS]
Operaciones. Escribir las funciones 
	a) void set_union(set<T> &A,set<T> &B,set<T> &C);
	b) void set_intersection(set<T> &A,set<T> &B,set<T> &C); 
	c) void set_difference(set<T> &A,set<T> &B,set<T> &C); 
en términos de los restantes métodos de la interfase de set.
**/

//version menos eficiente pero mas sencilla.
void set_union2(set<int> &A,set<int> &B,set<int> &C){
	C = A;
	C.insert(B.begin(),B.end());
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
/* C = B-A
Ej: A = {1,2,3}, B ={1,2,3,4,5} -> C = B-A = {1,4,5};
	
	*/
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



void show_set(set<int> &S){
	cout <<" (";
	for(auto x:S){
		cout << x << " ";
	}
	cout <<")"<<endl;
}
int main() {
	set<int> A = {1,2,3,4, 8,9}, B = {6, 7}, C;
//	set_union(A,B,C);
//	set_intersection(A,B,C);
	set_difference(A,B,C);		//A-B;
	show_set(C);
	
	return 0;
}








#include <iostream>
#include <stack>
#include <queue>
using namespace std;
/** Ejercicio
PancakeSort. Dada una pila de números S, implementar la función 
	void pancake_sort(stack<int>&S) la cual ordena la pila solo haciendo
	operaciones en las cuales se invierte un rango contiguo de elementos
	en el tope de la pila.
**/

//1ero buscar el mayor de la pila desordenada 
//2do invertir toda la "subpila" (desde el tope hasta el valor encontrado)
//3ero invertir toda la "subpila" (sin incluir el encontrado)

//tendremos que usar una funcion buscar mayor para la pila
void show_stack(stack<int> &S){
		while(!S.empty()){
			cout <<S.top()<<endl;
			S.pop();
		}
}
int busca_mayor(stack<int> S, int n){ //devuelve la posicion del mayor
	int mayor = S.top();
	int imayor = 0;
	for(int i=0;i<n;i++){
		if(mayor < S.top()){
			mayor = S.top();
			imayor = i;
		}
		S.pop();
	}
	return imayor;
}
void invertir(stack<int> &S, int n){	//funcion destructiva {&S}
	if(S.size()>= 1){ //en realidad no es necesario porque en pancakesort n
					//es siempre menor que S.size()
		
		queue<int> q; //estructura auxiliar
		for(int i=0;i<n;i++) { 
			q.push(S.top());
			S.pop();
		}
		for(int i=0;i<n;i++) { 
			S.push(q.front());
			q.pop();
		}
	}
}

void pancake_sort(stack<int> &S){
	int N = S.size();
	for(int i=0;i<N;i++) {
		
		//elementos a ordenar
		int n = N-i;
		// 1ero
		int iMax = busca_mayor(S,n);
		
		//2do	
		invertir(S,iMax+1); //el indice mas 1
		
		//3ero
		invertir(S,n);
	}
}
int main() {
	stack<int> S({5,4,6,8,4,32,1,6,4,-6,-7,9});

	pancake_sort(S);
	
	show_stack(S);
	return 0;
}








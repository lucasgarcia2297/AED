#include <iostream>
using namespace std;
/** Ejercicio 03: Guia03B) [ARBOLES BINARIOS] 
Profundidad. Escribir una funci�n 
		int cant_nodos_prof(btree<int> &A, int prof)
	que retorna el n�mero de nodos de un �rbol binario A que est�n 
	a profundidad prof o mayor.
**/
int cant_nodos_prof(btree<int> &A, btree<int>::iterator itA, int prof, int &curr_prof){
	if(itA == A.end()) return 0;
	int nnodos =0;
	
	if(curr_prof >= prof) ++nnodos;
	
	nnodos = 
}

int cant_nodos_prof

int main() {
	bin2oo
	return 0;
}








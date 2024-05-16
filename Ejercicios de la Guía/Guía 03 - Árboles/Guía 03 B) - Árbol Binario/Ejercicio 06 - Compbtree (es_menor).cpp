#include <iostream>
#include <lisp.hpp>
#include <btree.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/**	Ejercicio 06: Guia03B) [ARBOLES BINARIOS]
compbtree. Se define una relación de orden entre árboles binarios
	de enteros de la siguiente forma: A<B si a<b, o bien (a=b y A<B)
	o bien (a = b y Ai = Bi y Ad < Bd), donde a, b son las raíces
	y Ai, Ad, Bi, Bd son los subárboles izquierdos y derechos de
	A y B. Consigna: Escribir una función 
		bool es_menor(btree<int> &A, btree<int> &B)
	que retorne verdadero si A < B

**/
bool es_menor(btree<int> &A, btree<int>::iterator itA, btree<int> &B, btree<int>::iterator itB){
	//si los arboles estan vacios retorna falso;
	if(itA == A.end() && itB == B.end()) return false;
	
	//Si A está vacío y B no, se cumple la relacion de orden
	if(itA = A.end()) return true;
	
	//Si B está vacío y A no, no se cumple la relacion de orden
	if(itB = B.end()) return false;
	
	//Consulta las raices
	//si a<b, retorna verdadero
	if(*itA < *itB) return true;
	if(*itA > *itB) return false;
	
	//si no sale por las condiciones anteriores, entonces
	//a == b y hay que evaluar los hijos izquierdos
	//A_i < B_i
	if(es_menor(A, itA.left(), B, itB.left())) return true;

	//B_i no puede ser menor que A_i
	if(es_menor(B, itB.left(), A, itA.left())) return false;
	
	// Resta evaluar los hijos derechos
	// (a = b y A_i = B_i y A_d < B_d)
	return (es_menor(A, itA.right(), B, itB.right()));
}
bool es_menor(btree<int> &A, btree<int> &B){
	return es_menor(A, A.begin(), B, B.begin());
}

int main() {
	btreeh<int> BT1, BT2;
	lisp2btree("(4 (9 4 6)(8 2 3))",BT1);
	lisp2btree("(4 (9 4 6)(7 1 4))",BT1);
	
	btree2dot(BT1);
	btree2dot(BT2);
	
	cout << es_menor(BT1, BT2);
	return 0;
}








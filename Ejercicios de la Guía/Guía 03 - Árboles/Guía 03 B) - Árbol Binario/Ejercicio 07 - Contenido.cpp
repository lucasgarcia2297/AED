#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/**	Ejercicio 07: Guia 3b) [ARBOLES BINARIOS]
contenido. Escribir una funci´on predicado 
		bool contenido(btree<int> &A, btree<int> &B)
	que retorna verdadero si la estructura del ´arbol binario A esta contenido
	dentro de la de B y las etiquetas correspondientes de A son menores que las
	de B.
**/
/// Auxiliar
bool es_menor(btree<int>& A, btree<int>::iterator itA, btree<int>& B, btree<int>::iterator itB) {
	/// Si los arboles estan vacios,
	/// retorna falso
	if(itA == A.end() && itB == B.end()) return false;
	
	/// Si A esta vacio,
	/// se cumple la relacion de orden
	if(itA == A.end()) return true;
	
	/// Si B esta vacio y A no,
	/// no se cumple la relacion de orden
	if(itB == B.end()) return false;
	
	/// Consulta las raices
	/// Si a < b, retorna verdadero
	if(*itA < *itB) return true;
	
	/// Si b < a, retorna falso
	if(*itA > *itB) return false;
	
	/// Si no sale por las condiciones anteriores,
	/// entonces a = b y hay que evaluar los hijos izquierdos
	/// A_i < B_i
	if(es_menor(A, itA.left(), B, itB.left())) return true;
	
	/// B_i no puede ser menor que A_i
	if(es_menor(B, itB.left(), A, itA.left())) return false;
	
	/// Resta evaluar los hijos derechos
	/// (a = b y A_i = B_i y A_d < B_d)
	return es_menor(A, itA.right(), B, itB.right());
}

/// Propuesta Tomas
bool es_menor_tomas(btree<int> &A,btree<int>::iterator itA, btree<int> &B, btree<int>::iterator itB) {
	if(itA == A.end() or itB == B.end()){ 
		if(itA == A.end() and itB == B.end()){ 
			return true; 
		} else { 
			return false; 
		} 
	}
	
	if(*itA > *itB) { 
		return false; 
	} 
	
	if(*itA < *itB) {
		return true; 
	} else { 
		bool valorizq = es_menor(A,itA.left(),B,itB.left());
		
		/// falta checkear que B_i no sea < A_i
		
		if(valorizq)
			return true;
		else 
			return es_menor(A,itA.right(),B,itB.right());
	}
}

/// Wrapper
bool es_menor(btree<int>& A, btree<int>& B) {
	return es_menor(A, A.begin(), B, B.begin());
	//return es_menor_tomas(A, A.begin(), B, B.begin());
}


/// -------------------------------------------------------------

/// Auxiliar
bool contenido(btree<int>& A, btree<int>::iterator itA, btree<int>& B, btree<int>::iterator itB) {
	/// retorna verdadero si la estructura del arbol binario A esta
	/// contenido dentro de la de B y las etiquetas correspondientes de
	/// A son menores que las de B.
	
	/// itA no tiene ningun valor, no importa
	/// lo que itB tenga
	if(itA == A.end()) return true;
	
	/// itA tiene un valor pero itB no
	if(itB == B.end()) return false;
	
	/// itB no tiene que ser mayor a itA
	if(*itB < *itA) return false;
	
	/// se evalua la estructura de cada hijo
	/// en forma recursiva
	if(!contenido(A, itA.left(), B, itB.left())) return false;
	if(!contenido(A, itA.right(), B, itB.right())) return false;
	
	return true;
}

/// Wrapper
bool contenido(btree<int>& A, btree<int>& B) {
	return contenido(A, A.begin(), B, B.begin());
}

int main() {
	
	btree<int> BT1, BT2;
	
	//	lisp2btree("(4 (9 4 6) (7 2 3))", BT1);
	//	lisp2btree("(4 (9 4 6) (8 3 4))", BT2);
	//	
	//	btree2dot(BT1, "BT1");
	//	btree2dot(BT2, "BT2");
	//	
	//	cout<<"se cumple la relacion de orden? "<<es_menor(BT1, BT2)<<endl;
	
	lisp2btree("(4 (9 . 8) (5 7 8))", BT1);
	lisp2btree("(4 (10 7 8) (6 8 9))", BT2);
	
	btree2dot(BT1, "BT1");
	btree2dot(BT2, "BT2");
	
	cout<<"se cumple contenido? "<<contenido(BT1, BT2)<<endl;
	
	return 0;
}














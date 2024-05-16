#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/**	Ejercicio 02: Guia 3b) [ÁRBOL BINARIO]
VariosAB. Escribir procedimientos para: 
	a) Determinar si dos árboles tienen la misma estructura (semejantes). 
	b) Determinar si la estructura de un árbol es la espejada de otro (espejados). 
	c) Determina si dos árboles son iguales, en estructura y contenido (iguales).
	d) Copiar un árbol en otro en forma espejada. (espejar)
**/

///--a) Determinar si dos árboles tienen la misma estructura------------------------ 
bool semejantes(btree<char> &BT1,btree<char>::iterator n1, btree<char> &BT2, btree<char>::iterator n2){
	if((n1 == BT1.end()) xor (n2 == BT2.end())) return false;
	else if(n1 == BT1.end())	//es una hoja
		return true;
	else{ 	
		return semejantes(BT1, n1.left(),BT2,n2.left()) && semejantes(BT1, n1.right(),BT2,n2.right());
		
	}
}

bool semejantes(btree<char> &BT1, btree<char> &BT2){
	return semejantes(BT1, BT1.begin(),BT2,BT2.begin());
}
///-------------------------------------------------------------------------
///--b) Determinar si la estructura de un árbol es la espejada de otro (espejados).
bool espejados(btree<char> &BT1,btree<char>::iterator n1, btree<char> &BT2, btree<char>::iterator n2){
	if(n1 == BT1.end() xor n2 == BT2.end()) return false;
	else if(n1 == BT1.end())
		return true;
	else 
		return espejados(BT1, n1.left(),BT2,n2.right()) && semejantes(BT1, n1.right(),BT2,n2.left());
}

bool espejados(btree<char> &BT1, btree<char> &BT2){
	return espejados(BT1, BT1.begin(),BT2,BT2.begin());
}	
///-------------------------------------------------------------------------------
///--c) Determina si dos árboles son iguales, en estructura y contenido (iguales).
bool iguales(btree<char> &BT1,btree<char>::iterator n1, btree<char> &BT2, btree<char>::iterator n2){
	if((n1 == BT1.end()) xor (n2 == BT2.end())) return false;
	else if(n1 == BT1.end())	//es una hoja
		return true;
	else{ 	
		if(*n1 != *n2) return false;
		return iguales(BT1, n1.left(),BT2,n2.left()) && iguales(BT1, n1.right(),BT2,n2.right());
	}
}

bool iguales(btree<char> &BT1, btree<char> &BT2){
	return iguales(BT1, BT1.begin(),BT2,BT2.begin());
}
///-------------------------------------------------------------------------------
///-------d) Copiar un árbol en otro en forma espejada. (espejar)-----------------
void espejar(btree<char> &BT1,btree<char>::iterator n1, btree<char> &BT2, btree<char>::iterator n2){
	if(n1 == BT1.end()) return;
	else{
		n2 = BT2.insert(n2,*n1);
		espejar(BT1,n1.left(),BT2,n2.right());
		espejar(BT1,n1.right(),BT2,n2.left());
	}
}

void espejar(btree<char> &BT1, btree<char> &BT2){
	BT2.clear();
	espejar(BT1, BT1.begin(),BT2,BT2.begin());
}
///-------------------------------------------------------------------------------
int main() {
	btree<char> BT1;
	btree<char> BT2;
	btree<char> BT3;
	lisp2btree("(a (b c t) (d p e))", BT1);
	lisp2btree("(a (b c t) (d p e))", BT2);
//	btree2dot(BT1);
//	btree2dot(BT2);
	cout << "Misma estructura? "<<semejantes(BT1,BT2)<<endl;
	cout << "Espejados? "<<espejados(BT1,BT2)<<endl;
	cout << "iguales? "<<iguales(BT1,BT2)<<endl;
	espejar(BT1,BT3);
	btree2dot(BT3);
	return 0;
}








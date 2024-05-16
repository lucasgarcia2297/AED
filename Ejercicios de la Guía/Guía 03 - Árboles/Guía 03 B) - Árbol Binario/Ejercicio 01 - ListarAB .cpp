#include <iostream>
#include <graphviz.hpp>
#include <lisp.hpp>
#include <btree.hpp>
using namespace aed;
using namespace std;
/** Ejercicio 01 - Guia 3b) [Árboles Binarios]
ListarAB. Escribir procedimientos para listar un árbol ordenado 
	orientado siguiendo los ´ordenes prefijo, infijo y postfijo.
**/

//template<typename T>
void orden_prev(btree<char> &BT, btree<char>::iterator it){
	if(it==BT.end()) return;
	cout <<*it<<" ";
	orden_prev(BT,it.left());
	orden_prev(BT,it.right());
}
//template<class T>
void orden_post(btree<char> &BT, btree<char>::iterator it){
	if(it==BT.end()) return;
	orden_post(BT,it.left());
	orden_post(BT,it.right());
	cout <<*it<<" ";
	
}
//template<class T>
void orden_sim(btree<char> &BT, btree<char>::iterator it){
	if(it==BT.end()) return;
	orden_sim(BT,it.left());
	cout <<*it<<" ";
	orden_sim(BT,it.right());
}

int main() {
	btree<char> BT;
	lisp2btree("(a (e r f)(t y .))",BT);
	btree2dot(BT);
	cout <<"Orden previo: ";
	orden_prev(BT,BT.begin());
	cout <<endl;
	cout <<"Orden posterios: ";
	orden_post(BT,BT.begin());
	cout <<endl;
	cout <<"Orden simetrico: ";
	orden_sim(BT,BT.begin());
	cout <<endl;
	
	return 0;
}








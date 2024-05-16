#include <iostream>
#include <list>
using namespace std;
/**	Ejercicio 11 - Guia 2a) [TADs - Lista]
Palíndromo. Escribir un predicado bool is_palindromo(char* S), que 
	reciba como parámetro una cadena de texto S y determine si ésta 
	es un palíndromo, ignorando los espacios entre palabras. 
	Un palíndromo es una secuencia de caracteres que se lee igual 
	hacia adelante que hacia atr´as, por ejemplo: alli si maria avisa
	y asi va a ir a mi silla. Recordar que un string puede indexarse
	como un vector. Con el fin de utilizar la estructura <list>, 
	primero deben pasarse los elementos del string a una lista y 
	solo utilizar ésta en el algoritmo.
**/
void show_list(list<char> &L){
	cout<<"(";
	for( list<char>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it;
	}
	cout<<")";
}
bool is_palidromo(string &S){
	list<char> L;
	for(size_t i=0;i<S.size();i++) { 
		if(S[i] != ' ')
			L.push_back(S[i]);
	}
	show_list(L);
	
	list<char>::iterator it = L.begin();
	list<char>::iterator it2 = --L.end();
	while(it != it2){
		if(*it == *it2){
			it++;
		}else{
//			it = --it2;
//			bandera = false;
//			it2++;
			return false;
		}
		--it2;
	}
	return true;
}

int main() {
	string S = "alli si maria avisa y asi va a ir a mi silla";
	if(is_palidromo(S))
		cout <<"Si, lo es";
	else
		cout <<"No, no lo es";
	return 0;
}








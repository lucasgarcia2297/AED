#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;
/**
maxsubK: Escriba una funcion 
		int maxsubk(set<int> &S, int k);
	que devuelva la maxima suma en valor absoluto de todos los subconjuntos
	posibles del conjunto S tomados de a k.
**/
int suma_set(set<int> S){
	int suma =0;
	for(auto x:S){
		suma += abs(x);
	}
	return suma;
}

int maxsubk(set<int> S, int k, set<int> Sk){
	//si k llega a 0 retorno la suma de sk;
	if(k ==0) return suma_set(Sk);
	//si S queda vacio retorno -1
	if(S.empty()) return -1;
	//tomo el primer elemento 
	int elem = *S.begin();
	//lo borro
	S.erase(S.begin());
	//llamo a recusividad con el primer elemento eliminado de S
	int suma_sin = maxsubk(S,k,Sk);
	//inserto el elemnto que habia eliminado en Sk
	Sk.insert(elem);
	//llamo a recursividad con un valor menos de k
	int suma_con = maxsubk(S,k-1,Sk);
	
	return (suma_sin>suma_con) ? suma_sin : suma_con;
}
int maxsubk(set<int> &S, int k){
	return maxsubk(S,k,{});
}
int main() {
	set<int> S = {1,2,3,4,5};
	int k = 3;
	int sumamax = maxsubk(S,k);
	cout << "La suma mayor tomado de a "<< k<< " elementos es: "<<sumamax;
	return 0;
}








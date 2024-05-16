#include <iostream>
#include <list>
using namespace std;
/**Ejercicio 09 - Guía 02 (TADs)
Camaleón. Implemente los predicados bool menor(int x, int y), bool mayor(int x, int y)
y bool dist(int x, int y) que retornen verdadero si x es menor, mayor o menor 
en valor absoluto que y respectivamente. Luego implemente una función 
ordena(list<int> &L, bool (*f)(int,int)) que ordene la lista L dependiendo 
de la función f pasada cómo parámetro.
**/

bool menor(int x, int y){
	return x<y;
}
bool mayor(int x, int y){
	return x>y;
}
bool dist(int x, int y){ 	//distancia al 0
	return abs(x)<abs(y);
}
	
void ordena(list<int> &L, bool (*f)(int, int)){  //con puntero a funcion
	//Utilizando Basic_sort
	list<int> L2;
	
	while(!L.empty()){
		//tomar el siguiente eleento de L a ubicar,
		list<int>::iterator it = L.begin();
		list<int>::iterator itNext = L.begin();
		while(it!= L.end()){
			//ordena de acuerdo a la funcion f (menor, mayor, distancia, etc.)
			if(f(*it,*itNext)){
				itNext = it;
			}
			it++;
		}
		L2.push_back(*itNext);
		L.erase(itNext);
	}
	//Luego insertar los elementos de L2 en L
	L = L2;
}

void show_list(list<int> &L){
	cout<<"(";
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<" ";
	}
	cout<<")";
}

int main() {
	cout <<"Ordenamientos: "<<endl;
	list<int> L = {1,2,3,-2,4,7,-7,5,6,9};
	ordena(L, menor);
	show_list(L);
	cout <<endl;
	
	ordena(L, mayor);
	show_list(L);
	cout <<endl;
	
	ordena(L, dist);
	show_list(L);
	cout <<endl;
	return 0;
}








#include <iostream>
#include <queue>
using namespace std;
/**
Rotación. Escribir una función void rotacion(queue <int> &C), la cual saca
	una cierta cantidad de enteros del frente de la cola C y los vuelve a 
	insertar en fin de la misma, de tal manera que quede en el frente de 
	cola un número par. Por ejemplo, si C = [1, 3, 5, 2, 4] entonces, 
	después de rotacion(C), debe quedar C = [2, 4, 1, 3, 5].
**/
bool es_par(int n){
	if(n%2 == 0) 
		return true;
	else
		return false;
}

void rotacion(queue<int> &C){
	queue<int> aux;
	while(!C.empty() && !es_par(C.front())){
		aux.push(C.front());
		C.pop();
	}
	while(!aux.empty()){
		C.push(aux.front());
		aux.pop();
	}
}
void show_queue(queue<int> C){
	cout <<"[ ";
	while(!C.empty()){
		cout <<C.front()<< " ";
		C.pop();
	}
	cout <<" ]"<<endl;
}
int main() {
	queue<int> C({-1,1,-4,-2,2,3});
	show_queue(C);
	rotacion(C);
	cout << endl;
	show_queue(C);
	return 0;
}








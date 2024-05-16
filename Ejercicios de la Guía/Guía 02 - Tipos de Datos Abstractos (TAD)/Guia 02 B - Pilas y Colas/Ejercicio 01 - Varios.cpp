#include <iostream>
#include <stack>
using namespace std;
/**	Ejercicio 01 - Guia 2b - Pilas y colas (TADs)
Varios. Utilizando las operaciones del contenedor stack<> de STL, construir una 
serie de procedimientos que realicen cada una de las actividades siguientes en 
una pila: **/

/** a) Asignar i al segundo elemento desde la parte superior de la pila, 
	dejando la pila sin sus dos elementos de la parte superior. **/
void varios_a(stack<int> &S, int i){
	if(S.size()>= 2){
//		for(int i=0;i<2;i++) { 	//no hace falta el for, ya que con hacer
								//pop() 2 veces ya está
		S.pop();
//		S.pop();
//		S.push(i);
		S.top() = i;
	}
}
/** b) Asignar i al segundo elemento desde la parte superior de la pila, 
	sin modificarla. **/
void varios_b(stack<int> &S, int i){
	//reemplaza el segundo elemento por i
	if(S.size()>1){
		int x = S.top();	//guardo el elemento del tope
		S.pop();			//elimino el elemento del tope
		S.pop();			//elimino el "segundo" elemento del tope
		S.push(i);			//agrego i
		S.push(x);			//vuelvo a agregar el primer elemento
		//otra forma de hacer el push
//		S.top() = x; 	//S.top() es una referencia	por lo tanto,
						//se puede modificar de esta manera	
	}
}

/**c) Dado un entero n, asignar i al elemento n-ésimo desde la parte 
	superior de la pila, dejando la pila sin sus n elementos superiores. **/
void varios_c(stack<int> &S, int i, int n){ 
	if(S.size()>=n){
		for(int j=0;j<n;j++) { 
			S.pop();
		}
		S.push(i);
	}
}

/**d) Asignar i al elemento del fondo de la pila, dejando la pila vacía.**/
void varios_d(stack<int> &S, int i){
	while(!S.empty()){
		S.pop();
	}
	S.push(i);
}

/** e) Asignar i al elemento del fondo de la pila, dejando la pila sin modificar. **/
void varios_e(stack<int> &S, int i){
	//pasando los elementos de una pila a otra (Saux quedará invertida)
	stack<int> Saux;
	while(!S.empty()){
		Saux.push(S.top());
		S.pop();
	}
	//agtego el elemento i
	S.push(i);
	//Vuelvo a agregar los demas elementos (cambio Saux por S)
	while(!Saux.empty()){
		S.push(Saux.top());
		Saux.pop();
	}
	
	
}
void show_stack(stack<int> S){
	cout<< "[";
// --------------------MAL--------------------
//	for(size_t i=0;i<S.size();i++) { 
//		cout << S.top() << endl;
//	}
//:-----------------------------------------
//--- Debo ir eliminando los elemementos del tope para poder ver los siguientes.
//----por ello, los metodos hasta para ver, son destructivos.	
	while(!S.empty()){ 
		cout << S.top()<<endl;
		S.pop();
	}
	cout <<"]"<<endl;
}
	
int main() {
	// forma de inicializar
	stack<int> Sa({5,4,3,2,1});  //lo que esta entre parentesis es un contenedor
								//el elemento 5 estará en el tope
	varios_a(Sa,9);
	cout<<"----------Pila A---------------"<<endl;
	show_stack(Sa);
	cout<<"-------------------------------"<<endl;
	
	stack<int> Sb({5,4,3,2,1});
	varios_b(Sb,9);
	cout<<"----------Pila B---------------"<<endl;
	show_stack(Sb);
	cout<<"-------------------------------"<<endl;
	
	
	stack<int> Sc({5,4,3,2,1});
	varios_c(Sc,9,3);
	cout<<"----------Pila C---------------"<<endl;
	show_stack(Sc);
	cout<<"-------------------------------"<<endl;
	
	stack<int> Sd({5,4,3,2,1});
	varios_d(Sd,9);
	cout<<"----------Pila D---------------"<<endl;
	show_stack(Sd);
	cout<<"-------------------------------"<<endl;
	
	stack<int> Se({5,4,3,2,1});
	varios_e(Se,9);
	cout<<"----------Pila E---------------"<<endl;
	show_stack(Se);
	cout<<"-------------------------------"<<endl;	
	return 0;
}








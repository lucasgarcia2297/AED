#include <iostream>
#include <list>
using namespace std;
/**	Ejercicio 10 - Guía 2 (TADs)
Problema de Josephus. Un grupo de soldados se haya rodeado por una fuerza enemiga. 
No hay esperanzas de victoria si no llegan refuerzos y existe solamente un caballo
disponible para el escape. Los soldados se ponen de acuerdo en un pacto para 
determinar cuál de ellos debe escapar y solicitar ayuda. Forman un círculo y se 
escoge un número n al azar. Igualmente se escoge el nombre de un soldado. 
Comenzando por el soldado cuyo nombre se ha seleccionado, comienzan a contar en
la dirección del reloj alrededor del círculo. Cuando la cuenta alcanza el valor n,
este soldado es retirado del círculo y la cuenta comienza de nuevo, con el soldado
siguiente. El proceso continúa de tal manera que cada vez que se llega al valor 
de n se retira un soldado. El último soldado que queda es el que debe tomar el
caballo y escapar. Entonces, dados un número n y una lista de nombres, que es 
el ordenamiento en el sentido de las agujas del reloj de los soldados en el 
círculo (comenzando por aqu´el a partir del cual se inicia la cuenta), escribir
un procedimiento list<string> josephus(list<string>& nombres, int n) que retorna
una lista con los nombres de los soldados en el orden que han de ser eliminados
y en ´ultimo lugar el nombre del soldado que escapa.
**/

list<string> josephus(list<string> &nombres, int n){
	list<string> resultado = {};
	list<string>::iterator itN = nombres.begin(); 
	
	
	///-----Determinar el punto de partida (inicia en un numero al azar)--------
	//la idea es hacer una "lista circular" que si termina debe volver al principio
	//avanzo n veces el iterador
	for(int i=0;i<n;i++) { 
	//tambien controlo que el iterador no apunte al end
		itN++;
		if(itN == nombres.end()){
			itN = nombres.begin();
		}
	}
	///-------------------------------------------------------------------------
	
//	while(itN != nombres.end()){
	//repetir hasta que quese solo 1
	while(nombres.size() > 1){
		for(int i=0;i<n;i++) { 
		//tambien controlo que el iterador no apunte al end
			itN++;
			if(itN == nombres.end()){
				itN = nombres.begin();
			}
		}
		resultado.push_back(*itN);	//agregamos los nombres que van saliendo
		itN = nombres.erase(itN);	//lo eliinamos
		
		if(itN == nombres.end()){
			itN = nombres.begin();
		}
	}
	
	/**"resultado" tendra la lista en orden de los que fueron saliendo, incluyendo
	   el ultimo 
	**/
	resultado.push_back(*nombres.begin());
	
	///nombres debe quedar con un solo elemento que es el que sale
	
	return resultado; 
}

void show_list(list<string> &L){
	cout<<"(";
	for( list<string>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<" ";
	}
	cout<<")";
}

int main() {
	list<string> nombres = {"roberto", "maria", "juana", "pepe", "daniel", "rosa"};
	list<string> resultado = josephus(nombres,2);
	show_list(resultado);
	show_list(nombres);
	return 0;
}








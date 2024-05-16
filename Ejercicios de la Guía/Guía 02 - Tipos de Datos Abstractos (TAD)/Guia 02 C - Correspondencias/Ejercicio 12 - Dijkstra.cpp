#include <iostream>
#include <map>
#include <list>
using namespace std;
/**	Ejercicio 12 - Guia 2c) [CORRESPONDENCIAS]
Dijkstra. Programe float Dijkstra(graphW& G, int u, int v, list<int>&path) 
	que dado el grafo ponderado G definido como 
		typedef map<int,map<int,float>> graphW;, 
	implemente el algoritmo de Dijkstra para retornar el costo del camino
	más corto entre el vértice de partida u y el v´ertice de llegada v.
	Además debe devolver en path uno de los posibles caminos. Si no hay 
	camino posible, retornar un número muy grande (infinito).

**/
typedef map<char, map<char, float>> graphW;	//grafo ponderado No dirigido.

float Dijkstra(graphW &G, char ini, char fin, list<int>&path){
//	set<char>
	map<char, bool> visitados; 		//para buscar un nodo visitado es eficiente el set o el mapa
	map<char, pair<int, char>> acum;	//por cada nodo (char) tener un par (pair) de entero y char
	
	acum[ini] = {0,'-'};
	char currentnode = ini; //nodo actual
	
	while(currentnode != fin){
		visitados[currentnode];
		map<char, int> & adyacentes = G[currentnode];
		
		int w = acum[currentnode].first;
		
		///actualizar la tabla de los vecinos
		for(auto vecino: adyacentes){
			char label = vecino.first; //etiqueta
			if(visitados.find(label) == visitados.end()){
				int new_w = w + vecinos.second;
				if(new_w < acum[vecino].first){
					acum[vecino].first = new_w;
					acum[vecino].second = currentnode;
				 }
			}
		}
		///seleccionar el siguiente nodo a evaluar
		///entre los no visitados buscar el de menor peso en la tabla acum
		int minw = inf;
		for(auto columna: acum){
			if(visitados.find(columna.first) == visitados.end()){ //si no fue visitado
				if(columna.second.first < minw){	//
					minw = columna.second.first;
					currentnode = columna.first;
				}
			}
		}
	}
	//generar la lista 'hacia atras'
	
}

int main() {
//	map<char, map<char, int>> 
	graphW	GW = {
		{'a',{
			{'b',2},
			{'c',3}
			}
		},
		{'b',{
			{'a',2},
			{'d',5},
			{'e',2}
			}
		},
		{'c',{
			{'a',3},
			{'e',5}
			}
		},
		{'d',{
			{'b',5},
			{'e',1},
			{'z',2}
			}
		},
		{'e',{
			{'b',2},
			{'c',5},
			{'d',1}
			{'z',4}
			}
		},
		{'z',{
			{'d',2},
			{'e',4},
		}
		}
	};
	
	return 0;
}








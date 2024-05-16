#include <iostream>
using namespace std;
/**
Prim. Programe int Prim(graphW& G, tree<int>&T) que dado el 
	grafo no dirigido ponderado G definido como 
		typedef map<int,map<int,int>> graphW;
	implemente el algoritmo de Prim para hallar y retornar el
	árbol de expansión de costo mínimo.
**/


typedef map<char,map<char,int>> graphW;

const int INF = INT_MAX; //declarar un peso infinito

int Prim(graphW& G, tree<int>&T){
	graphW::iterator itG = G.begin();
	tree<char>::iterator p = T.begin();
	
	map<char, tree<char>::iterator> visitados;
	
	//vertice de inicio
	p = T.insert(p,itG->first);
	visitados[itG->first] = p;
	
	int W = 0;
	while(visitados.size() < G.size()){
		int min = INF;
		
		//par aristas de menor peso
		char f,c;	//"fila, columna"
		
		//recorrer todos los vértices del grafo
		itG = G.begin();
		for(size_t x=0;x<G.size()-1;x++, i++) { 
			char nodoActual = itG->first;
			
			//verifica que el vértice actual ya fue visitado
			if(visitados.find(nodoActual) != visitados.end()){
				map<char, int> adyacentes = itG->second;
				map<char, int>::iterator j = adyacentes.begin();
				
				//recorre todas las aristas adyacentes
				for(size_t y=0;y<adyacentes.size();y++,j++) { 
					char nodoAdyacente = j->first;
					
					//busca a la arista adyacente de menor peso;
					if(min > G[nodoActual][nodoAdyacente] && visitados.find(*nodoActual) == visitados.end()){
						min = G[nodoActual][nodoAdyacente];
						f = nodoActual;
						c = nodoAdyacente;
					}
				}	
			}
		}
		//suma el peso mínimo al total acumulado
		W += min;
		
		// armar el árbol
		p = T.insert(visitados[f].lchild(),c); //inserta en el hijo mas izquierdo del nodo actual
		
		// agregar el vértice que marca la arista de peso mínimo
		visitados[c] = p;
	}
	return W;
}
int main() {
	graphW G = {
		{'A',{
			{'B',2},
			{'C',3},
		}},
		{'B',{
			{'A',2},
			{'D',5},
			{'E',2},
		}},
		{'C',{
			{'A',2},
			{'D',5},
			{'E',2},
		}},
		{'D',{
			{'A',2},
			{'',5},
			{'E',2},
		}},
		{'E',{
			{'B',2},
			{'C',5},
			{'',2},
			{'E',2},
		}},
		{'Z',{
			{'A',2},
			{'D',5},
			{'E',2},
		}},
	}
	prim();
	return 0;
}








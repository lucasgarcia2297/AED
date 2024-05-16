#include <iostream>
#include <list>
#include <map>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/**	Ejercicio 08: Guia02C) [CORRESPONDENCIA]
CompConexa. Dado un grafo como map<int,list<int>> G encontrar los 
	subconjuntos del mismo list<list<int>> D que estn desconectados, 
	es decir, los conjuntos de vértices de cada una de las componentes conexas.
	Por ejemplo, si G={1->{2},2->{1},3->{4},4->{3}}, entonces debe retornar 
	D=({1,2},{3,4}). La signatura de la función a implementar es 
		void comp_conexas(map<int,list<int>> &G, list<list<int>> &D).
**/
typedef map<int,list<int>> graph;

void genCompConexa(graph& G, map<int,bool>& visitados, int label, list<int>& cc) {
	visitados[label];
	cc.push_back(label);
	list<int>& adyacentes = G[label];
	for(auto vecino:adyacentes){
		if(visitados.find(vecino)==visitados.end()){
			genCompConexa(G,visitados,vecino,cc);
		}
	}
}

list<list<int>> compConexas(graph& G){
	list<list<int>> CC;
	map<int,bool> visitados;
	
	while(visitados.size()<G.size()){
		int label;
		///busco algun vertice que no haya sido visitado
		for(auto vertice:G){
			if(visitados.find(vertice.first)==visitados.end()){
				label = vertice.first;
				break;
			}
		}
		///generar su componente conexa
		list<int> cc;
		genCompConexa(G,visitados,label,cc);
		
		CC.push_back(cc);
	}
	
	return CC;
}
	
int main() {
	graph G={
		{0,{1}},
	{1,{0,3,4}},
		{2,{3}},
	{3,{1,2}},
		{4,{1}},
	{5,{6}},
		{6,{5,7}},
	{7,{6}}
	};
	graph2dot(G);
	list<list<int>> CC = compConexas(G);
	
	cout<<"Componentes conexas: "<<endl;
	for(auto cc : CC){
		cout<<"( ";
		for(auto x : cc){
			cout<<x<<" ";
		}
		cout<<")"<<endl;
	}
	return 0;
}
	
	
	
	
	
	
	







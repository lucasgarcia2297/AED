#include <iostream>
#include <set>
#include <list>
using namespace std;
/**
subK. Escriba una función 
		list<set<int>> subk(set<int> &S, int k) 
	que devuelva una lista conteniendo todos los subconjuntos posibles
	del conjunto S tomados de a k.
**/

//s = {1,2,3,4,5};
//si k = 1 -> LS = [{1},{2},{3},{4},{5}]  
//si k = 2 -> LS = [{1,2},{1,3},{1,4},{1,5},{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}]  
//si k = 3 -> LS = [{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},{1,4,5},{2,3,4},{2,3,5},{2,4,5},{3,4,5}]  
//si k = 4 -> LS = [{1,2,3,4},{1,2,3,5},{1,2,4,5},{1,3,4,5},{2,3,4,5}]  
//si k = 5 -> LS = [{1,2,3,4,5}];  

//s = {3,5,6,9,15};
//si k = 1 -> LS = [{3},{5},{6},{9},{15}]  
//si k = 2 -> LS = [{3,5},{3,6},{3,4},{1,5},{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}]  
//si k = 3 -> LS = [{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},{1,4,5},{2,3,4},{2,3,5},{2,4,5},{3,4,5}]  
//si k = 4 -> LS = [{1,2,3,4},{1,2,3,5},{1,2,4,5},{1,3,4,5},{2,3,4,5}]  
//si k = 5 -> LS = [{1,2,3,4,5}];  
void show_set(set<int> &S);
void subk(set<int> S, int k, set<int> Sk, set<set<int>> &SS){
	//si k llega a 0 retorno la suma de sk;
	if(k ==0){ 
		SS.insert(Sk);
	}
	//si S queda vacio retorno -1
	if(S.empty()) return;
	//tomo el primer elemento 
	int elem = *S.begin();
	//lo borro S={} k = 1;
	S.erase(S.begin());
	//llamo a recusividad con el primer elemento eliminado de S
	subk(S,k,Sk,SS);
	//inserto el elemnto que habia eliminado en Sk
	Sk.insert(elem); //Sk = {4}
	//llamo a recursividad con un valor menos de k
	subk(S,k-1,Sk,SS); //
	
}

list<set<int>> subk(set<int> S, int k){
	list<set<int>> LS;
	set<set<int>> SS;
	subk(S,k,{},SS);
	for(auto x:SS){
		LS.push_back(x);
	}
	return LS;
}

void show_set(set<int> &S){
	cout <<"{ ";
	for(auto x:S){
		cout << x<< ", ";
	}
	cout <<" }" <<endl;
}
void show_listSet(list<set<int>> &LS){
	cout << "[ ";
	for(auto x: LS){
		show_set(x);
	}
	cout <<" ]"<<endl;
}
int main() {
	set<int> S = {1,2,6};
	int k = 0;
	list<set<int>> LS = subk(S,k);
	show_listSet(LS);
	//LS = {{1,2,3},{1,2,4},{1,3,4},{2,3,4}};
	return 0;
}








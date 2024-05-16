// Example program
#include <iostream>
#include <vector>

using namespace std;

void show_vector(vector<int>& v) {
	cout<<"{ ";
	for(auto i:v) {
		cout<<i<<" ";
	}
	cout<<"}"<<endl;
}


void bubble_sort(vector<int>& v) {
	int n = v.size();
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-1; j++) {
			if (v[j] > v[j+1]) {
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}

void insertion_sort(vector<int>& v) {
	int n = v.size();
	
	for(int i=1; i<n; i++) {
		int aux = v[i];
		
		int j = i-1;
		while(aux<v[j] && j>=0) {
			v[j+1] = v[j];
			--j;
		}
		v[j+1] = aux;
	}
}

void selection_sort(vector<int>& v) {
	int n = v.size();
	
	for(int i=0; i<n-1; i++) {
		int min = i;
		for(int j=i+1; j<n; j++) {
			if (v[j] < v[min]) {
				min = j;
			}
		}
		int aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}
}


/// Auxiliar
void quick_sort(vector<int>& v, int izq, int der) {
	/// Eleccion del pivote
	/// Promedio entre los extremos
	//int p = v[izq] + (v[der] - v[izq])/2;
	
	/// A tres bandas
	int p = (v[izq] + v[(der+izq)/2] + v[der])/3;
	
	/// Extremo derecho (izquierdo)
	//int p = v[der];
	
	// crea los indices a partir del rango
	int i = izq;
	int j = der;
	
	// procesa el subrango del vector definido por i y j
	while(i<=j) {
		// posiciona los indices del rango a los elementos
		// mas cercanos al pivote
		while(v[i]<p)
			i++;
		while(v[j]>p)
			j--;
		
		// solo realiza el intercambio si los indices no se cruzaron
		if(i<=j) {
			// intercambia
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			
			// actualiza los indices
			i++;
			j--;
		}
	}
	
	// realiza recursion hasta que los indices alcanzan los extremos
	// condicion de corte implicita si el rango abarca un solo elemento
	if(j>izq)
		  quick_sort(v, izq, j);
	if(i<der)
		quick_sort(v, i, der);
}

/// Wrapper
void quick_sort(vector<int>& v) {
	return quick_sort(v, 0, v.size()-1);
}


void reheap(vector<int>& v, int n, int j = 0) {
	while(true) {
		int mayor,
			padre = j,
			izq = 2*j+1,
			der = izq+1;
		
		if(izq>=n) break; // fuera de rango, elemento ya ordenado
		
		if(der<n) { // tiene dos hijos
			mayor = (v[izq]<v[der]) ? der : izq;
		} else {
			mayor = izq;
		}
		
		if(v[mayor]>v[padre]) {
			int aux = v[mayor];
			v[mayor] = v[padre];
			v[padre] = aux;
		}
		
		j = mayor;
	}
}

void make_heap(vector<int>& v, int n) {
	for(int j=(n/2)-1; j>=0; j--)
		reheap(v, n, j);
}

void heap_sort(vector<int>& v) {
	int n = v.size();
	make_heap(v, n);
	
	int heaplast = n;
	
	while(heaplast>0) {
		heaplast--;
		int aux = v[0];
		v[0] = v[heaplast];
		v[heaplast] = aux;
		
		reheap(v, heaplast);
	}
}


/// Auxiliar
void merge_sort(vector<int>& v, int ini, int fin, vector<int>& temp) {
	int n = fin-ini;
	
	if(n==1) return;	//si hay un solo elemento retorno.
	
	int nIzq = (n/2), nDer = n-nIzq;	//divido por 2 el tamaño del vector
	
	int medio = ini+nIzq, q = 0, q1 = ini, q2 = medio;	//q2 es desde el inicio hasta la mitad	
	
	merge_sort(v, ini, medio, temp);	//llamo recursivamente a la funcion desde el inicio hasta la mitad
	merge_sort(v, medio, fin, temp);	//y, por otro lado, desde la mitad hasta el final
	
	while (q1!=medio && q2!=fin) {	//mientras que q1 (inicio) no haya llegado a la mitad y q2 (medio) no haya llegado al fin
		if(v[q2]<v[q1]) {			//si el que esta 
			temp[q] = v[q2];
			++q2;
		} else {
			temp[q] = v[q1];
			++q1;
		}
		++q;
	}
	
	while (q1!=medio) {
		temp[q] = v[q1];
		++q1;
		++q;
	}
	
	while (q2!=fin) {
		temp[q] = v[q2];
		++q2;
		++q;
	}
	
	q1 = ini;
	for (int j=0; j<n; j++) {
		v[q1] = temp[j];
		++q1;
	}
}

/// Wrapper
void merge_sort(vector<int>& v) {
	vector<int> temp = vector<int>(v.size(), 0);
	return merge_sort(v, 0, v.size(), temp);
}


int main()
{
	vector<int> V = {6,5,3,1,8,7,2,4};
	
	cout<<"V =    ";
	show_vector(V);
	
//	bubble_sort(V);
//	insertion_sort(V);
//	selection_sort(V);
//	
//	quick_sort(V);
//	heap_sort(V);
	merge_sort(V);
	
	cout<<"Vord = ";
	show_vector(V);
	
	
	
	return 0;
}







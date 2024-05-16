#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

/**
Comparación de estrategias para hallar el n-esimo numero de Fibonacci
**/

/*
Definicion recursiva, O(2^n)
*/
int fib1(int n){
	if (n==1 || n==2) return 1;
	else return (fib1(n-1)+fib1(n-2));
}
	
/*	
Solucion incremental O(n)
*/
int fib2(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	int f_n_2 = 0;
	int f_n_1 = 1;
	int f_n;
	int i = 2;
	while(i<=n){
		f_n = f_n_1 + f_n_2;
		f_n_2 = f_n_1;
		f_n_1 = f_n;
		i++;
	}
	return f_n;
}
	
/*
	Solución explicita de la relaci?n de recurrencia, O(1)
*/
int fib3(int n){
	double srqt5 = sqrt(5);
	return (pow((1+srqt5),n)-pow((1-srqt5),n))/(pow(2,n)*srqt5);
}

/*
Solucion recursiva mas inteligente:
Programación dinámica con estructura auxiliar, O(n)
*/
vector<int> fibs;
int fib4(int n){
	if(fibs[n]>0) return fibs[n];
	if (n==1 || n==2) fibs[n] = 1;
	else 
		fibs[n] = (fib2(n-1)+fib2(n-2));
	return fibs[n];
}
	
int main() {
	int N;
	cout<<" Ingrese N: ";
	cin >>N;
	cout<<endl;
	
	clock_t begin1 = clock();
	int f1 = fib1(N);
	clock_t end1 = clock();
	double elapsed_secs_1 = double(end1 - begin1) / CLOCKS_PER_SEC;
	cout<<"f_"<<N<<": "<<f1<<" ---- elapsed time function fib1: "<<elapsed_secs_1<<" [s]"<<endl;
	
	clock_t begin2 = clock();
	int f2 = fib2(N);
	clock_t end2 = clock();
	double elapsed_secs_2 = double(end2 - begin2) / CLOCKS_PER_SEC;
	cout<<"f_"<<N<<": "<<f2<<" ---- elapsed time function fib2: "<<elapsed_secs_2<<" [s]"<<endl;
	
	clock_t begin3 = clock();
	int f3 = fib3(N);
	clock_t end3 = clock();
	double elapsed_secs_3 = double(end3 - begin3) / CLOCKS_PER_SEC;
	cout<<"f_"<<N<<": "<<f3<<" ---- elapsed time function fib3: "<<elapsed_secs_3<<" [s]"<<endl;
	
	fibs.resize(N+1,0);
	clock_t begin4 = clock();
	int f4 = fib4(N);
	clock_t end4 = clock();
	double elapsed_secs_4 = double(end4 - begin4) / CLOCKS_PER_SEC;
	cout<<"f_"<<N<<": "<<f4<<" ---- elapsed time function fib4: "<<elapsed_secs_4<<" [s]"<<endl;
	
	
	return 0;
}

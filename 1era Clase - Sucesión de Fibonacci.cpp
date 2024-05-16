#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;


// Orden 2^n - O(2^n)	
int fib1(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	return (fib1(n-1)+fib1(n-2));
}

// Orden n - O(n)
int fib2(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	int f_n_2 = 0;
	int f_n_1 = 1;
	int f_n;
	for(int i=2;i<=n;i++) { 
		f_n = f_n_1 + f_n_2;
		f_n_2 = f_n_1;
		f_n_1 = f_n;
	}
	return f_n;
}

// Orden 1 - O(1)
int fib3(int n){
	double sqrt5 = sqrt(5);
	return ((pow((1+sqrt5)/2,n)-pow((1-((1+sqrt5)/2)),n))/sqrt5);
}
	
	
int main() {
	int n;
	cout <<"Ingrese n: ";
	cin >> n;
	
	clock_t begin1 = clock();
	int f1 = fib1(n);
	clock_t end1 = clock();
	double elapsed_secs_1 = double(end1 - begin1)/CLOCKS_PER_SEC;
	cout <<"f_"<<n <<": "<<f1 <<" --- elapsed time function fib11:" <<elapsed_secs_1<<" [s]"<<endl;

	clock_t begin2 = clock();
	int f2 = fib2(n);
	clock_t end2 = clock();
	double elapsed_secs_2 = double(end2 - begin2) / CLOCKS_PER_SEC;
	cout <<"f_"<<n <<": "<<f2 <<" --- elapsed time function fib12:" <<elapsed_secs_2<<" [s]"<<endl;
	
	clock_t begin3 = clock();
	int f3 = fib3(n);
	clock_t end3 = clock();
	double elapsed_secs_3 = double(end3 - begin3) / CLOCKS_PER_SEC;
	cout <<"f_"<<n <<": "<<f3 <<" --- elapsed time function fib13:" <<elapsed_secs_3<<" [s]"<<endl;
	
	return 0;
}








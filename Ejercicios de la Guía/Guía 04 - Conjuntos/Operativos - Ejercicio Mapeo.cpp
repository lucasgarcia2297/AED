#include <iostream>
using namespace std;
/**
Mapeo. La realización de conjuntos mediante vectores de bits se puede usar 
	siempre que el conjunto universal se pueda traducir a los enteros de 
	1 a N. Describa cómo haría esa traducción (es decir funciones 
		int indx(elem_t) y elem_t element(int)) 
	si el conjunto universal fuera:
**/
///1) los enteros 0, 1, ..., 99. 
int indx1(elem_t e){	//retorna el indice del vector de bits (para "prender" o "apagar")
	return e+1;	//100 elementos
}
elem_t element1(int i)){	//a partir de un indice, retorna el elemento 
	return i-1;
} 

///2) los enteros de n a m para cualquier n <= m. 
int indx2(elem_t e){	//retorna el indice del vector de bits (para "prender" o "apagar")
	return (e-n)+1;	  //+1 porque n puede ser igual a m.
}

elem_t element2(int i)){	//a partir de un indice, retorna el elemento 
	return (i-1)+n;
}
///3) los enteros n, n + 2, n + 4, ...n + 2k, para cualesquier n y k. 4) los caracteres a, b, ... z.
int indx3(elem_t e){	//retorna el indice del vector de bits (para "prender" o "apagar")
	return ((e-n)/2)+1;
}

elem_t element3(int i)){	//a partir de un indice, retorna el elemento 
	return ((i-1)*2)+n;
}

///4) los caracteres a, b, ... z.  (a=97 en ASCII)
int indx4(elem_t e){
	return (e-'a')+1;
}
elem_t element4(int i){
	return 
}
int main() {
	
	return 0;
}








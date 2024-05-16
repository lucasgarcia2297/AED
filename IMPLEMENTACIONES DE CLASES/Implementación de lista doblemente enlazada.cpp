#include <iostream>
#include <list>
using namespace std;

/**	IMPLEMENTACIÓN DE listA CON CELDAS DOBLEMENTE ENLAZADA	**/
namespace aed{
	template<class T>
	class list {
	public: 
		class iterator;	//declaración para poder usarla antes de implementar.
		
	private:
		class cell{
			friend class list;	//puede acceder a los miembros privados de la clase list
			friend class iterator;	//puede acceder a los miembros privados de la clase iterator
			T t;		//tipo t del elemento.
			cell *next, *prev;  //puntero de tipo celda que apunta a la siguiente (next), y a la celda anterior(prev).
			cell() : next(NULL), prev(NULL){}	//constructor vacío que apunte al nulo.
		};
		cell *first, *last; //punteros que apuntan al principio y al final de la lista.
		
	public: 
		class iterator {
		private:
			friend class list; 	//puede acceder a los miembros privados de la clase list
			cell* ptr;	//
			
		public:
			
			T &operator*(){ return ptr->next->t; }
			T &operator->(){ return &ptr->next->t; }
			
			bool operator!=(iterator q){ return ptr!=q.ptr; }
			bool operator==(iterator q){ return ptr==q.ptr; }
			
			//CONSTRUCTOR DE ITERATOR
			iterator(cell *p = NULL) : ptr(p){}	
			
			// ++ PREFIJO:
			iterator operator++(){
				ptr = ptr->next;
				return *this;
			}
			// ++ POSTFIJO:
			iterator operator++(int){
				iterator q = *this;
				ptr = ptr->next;
				return q;
			}
			
			// -- PREFIJO
			iterator operator--(){
				ptr = ptr->prev;
				return *this;
			}
			// -- POSTFIJO:
			iterator operator--(int){
				iterator q = *this;
				ptr = ptr->prev;
				return q;
			}
			
			
		};
		
		///CONSTRUCTOR DE list
		list(){
			first = new cell;
			last = first;
		}
		///DESTRUCTOR DE list
		~list() {clear(); delete first; }
		
		///método insert( "donde", "Dato")
		iterator insert(iterator p, T t){	
			cell *q = p.ptr->next;
		
			cell *c = new cell;
			p.ptr->next = c;
			
			c->next = q;	
			c->prev = p.ptr;
			//actualizar el valor del elemento. 
			c->t = t;
			
			q->prev = c;
			
			if(q == NULL){
				last = c;
			}
			
			return p;
		}
			
		///metodo erase( posicion);
		iterator erase(iterator p){
			cell *o = p.ptr->prev;	//celda anterior de p
			cell *q = p.ptr->next;	//celda siguiente de p
			
			if(q == last) last = p.ptr;
			
			p.ptr->next = q->next;
			p.ptr->prev = o->prev;
			
			delete q;	//eliminar la memoria de q
			delete o;	//eliminar la memoria de o
			return p;
		} 
			
		///metodo erase( "desde", "hasta" ) [de rango];
		iterator erase(iterator p, iterator q){
			cell *s, *r = p.ptr->next, *o = p.ptr->prev;
			
			p.ptr->next = q.ptr->next;
			p.ptr->prev = o->prev;	//porque es doblemente enlazada
			
			//si p.ptr->next no está definido
			if(!p.ptr->next) last = p.ptr;
			if(!p.ptr->prev) first = p.ptr;
			
			while(r!=q.ptr->next){ //eliminamos de la memoria el rango
				s = r->next;
				
				delete r;
				
				r = s;
			}
			return p;
		}	
		///método begin();
		iterator begin(){ return iterator(first); }
		///método end();
		iterator end(){ return iterator(last); }
		///método clear();
		void clear() { erase(begin(), end()); };
	};
}
//void show_list(list<int> L){
//	cout << " ( ";
//	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
//		cout << *it <<" ";
//	}
//	cout <<" )"<<endl;
//}
	
int main() {
//	list<int> L;
//	list<int>::iterator it = L.begin();
//	list<int>::iterator it2 = it;
//	
//	for(int i=0;i<10;i++) { 
//		L.insert(L.begin(),i);
//	}
//	show_list(L);
//	
//	it2++;
//	it2++;
//	it2++;
//	for(int i=0;i<7;i++) { 
//		it++;
//		it2++;
//	}
//	if(it2 == L.end()){
//		cout << "Posicion no dereferenciable!"<<endl;
//	}else{
//		cout << *it2<<endl;
//		it2 = L.erase(it,it2);
//		cout << *it2<<endl;
//	}
//	show_list(L);
	return 0;
}








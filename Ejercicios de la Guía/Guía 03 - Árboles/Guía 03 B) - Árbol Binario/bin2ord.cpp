#include <iostream>
using namespace std;


void bin2ord(btree<int> &B, btree<int>::iterator itB, tree<int> &T, tree<int>::iterator itT){
	if(itB == B.end()) return;
	
	itT = T.insert(itT, *itB);
	
	bree<int>::iterator itB_left = itB.left();
	bree<int>::iterator itB_right = itB.right();
	
	//itB es Hoja
	if(itB_left == B.end() && itB_right == B.end()) return;
	
	//Existe el hijo izquierdo y no existe el derecho;
	if(itB_left != B.end() && itB_right == B.end()) {
		bin2ord(B,itB_left,T,itT.lchild());
		T.insert(itT.lchild().right(),-1);
		
	}else if(itB_left == B.end() && itB_right  != B.end()){
		T.insert(itT.lchild(),-1);
		bin2ord(B,itB_right,T,itT.lchild().right());
	}else{
		bin2ord(B,itB_left,T,itT.lchild());
		bin2ord(B,itB_right,T,itT.lchild().right());
	}
	
}
void bin2ord(btree<int> &B, tree<int> &T){
	T.clear();
	bin2ord(B,B.begin(),T,T.begin());
}
int main() {
	string s_arbol("(1 (2 (4 7 .)(5))(3 . (6 8 9)))");
	btree<int> B;
	if(lisp2btree(s_arbol, B)) B
	
	return 0;
}








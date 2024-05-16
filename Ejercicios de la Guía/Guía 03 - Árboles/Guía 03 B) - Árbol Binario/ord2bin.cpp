#include <iostream>
using namespace std;

void ord2bin(tree<int> &T,tree<int>::iterator itT, btree<int>&B, btree<int>::iterator itB){
	if(itT == T.end() || *it == -1) return;
	
	itB = B.insert(itB, *itB);
	
	if(itT.lchild() !=  T.end()){
		ord2bin(T,itT.lchild(), B, itB.left());
		ord2bin(T,itT.lchild().right(), B, itB.right());
	}

}
void ord2bin(tree<int> &T, btree<int>&B){
	B.clear();
	ord2bbin(T,T.begin(),B,B.begin());
}

int main() {
	
	return 0;
}








#include <iostream>
#include "AVLTree.h"

using namespace std;
int main() {

    AVL<int> avl;
    int num=1;
    int num_2=3;
    BinNodePosi<int> p = avl.insert ( num );
    BinNodePosi<int> q = avl.insert ( num_2 );
    cout<<p->data<<q->data;
    cout << "Hello, World!" << endl;
}

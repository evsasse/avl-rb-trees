#include <iostream>
using std::cout;

#include "AvlTree.h"

int main(){
    AvlTree<char> avl;
    avl.insert('a');
    avl.insert('b');
    avl.insert('c');
    avl.remove('b');
    cout << avl.toString();
}
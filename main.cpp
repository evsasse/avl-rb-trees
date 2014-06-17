#include <iostream>
using std::cout;
using std::endl;

#include "AvlTree.h"
#include "RBTree.h"

int main(){
    AvlTree<char> avl;
    avl.insert('a');
    avl.insert('b');
    avl.insert('c');
    avl.remove('b');
    //cout << avl.toString();
    RBTree<char> rb;
    rb.insert('a');
    rb.insert('b');
    rb.insert('c');
    cout << rb.toString();
    //AvlTree<char>::Node* a = new AvlTree<char>::Node('a');
    //AvlTree<char>::Node* b = new AvlTree<char>::Node('b');
    //AvlTree<char>::Node* c = new AvlTree<char>::Node('c');
    //c->left = a;
    //a->right = b;
    //cout << c->toString() << endl;
    //c->left = a->rotateLeft();
    //cout << c->toString() << endl;
}
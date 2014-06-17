#include <iostream>
using std::cout;

#include "AvlTree.h"

int main(){
    AvlTree<char> tree;
    tree.insert('a');
    tree.insert('b');
    tree.insert('c');
    tree.insert('d');
    tree.insert('e');
    tree.insert('f');
    tree.insert('g');
    tree.insert('h');
    tree.insert('i');
    tree.insert('j');
    tree.insert('k');
    tree.insert('l');
    tree.insert('m');
    tree.insert('n');
    tree.insert('o');
    tree.remove('h');
    tree.remove('f');
    tree.remove('e');
    cout << tree.toString();
}
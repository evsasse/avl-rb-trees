#ifndef RBTREE_H
#define	RBTREE_H

#include <string>
using std::string;

template <typename T>
class RBTree{
    struct Node{
        Node *left, *right;
        T data;
        
        Node(const T& t):
        left(0),
        right(0),
        data(t),
        red(true){
        }
        
        bool setRed(){
            red = true;
        }
        bool setBlack(){
            red = false;
        }
        bool isRed(){
            if(this == 0) return false;
            return red;
        }
        bool isBlack(){
            if(this == 0) return true;
            return !red;
        }
    private:
        bool red;
    };
public:
    void insert(const T& t){
        root = insert(t,root);
        root->setBlack();
    }
    void remove(const T& t){
        root = remove(t,root);
        root->setBlack();
    }
private:
    Node* root;
    
    Node* insert(const T& t, Node* root){
        return root;
    }
    
    Node* remove(const T& t, Node* root){
        return root;
    }
};

#endif	/* RBTREE_H */


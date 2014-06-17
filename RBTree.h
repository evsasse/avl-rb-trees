#ifndef RBTREE_H
#define	RBTREE_H

#include <string>
using std::string;

template <typename T>
class RBTree{
    struct Node{
        Node *parent, *left, *right;
        T data;
        
        Node(const T& t):
            parent(0),
            left(0),
            right(0),
            data(t),
            red(true){
        }
        
        string toString(){
            if (this == 0) return "B@";
            char color = 'R';
            if(isBlack()) color = 'B';
            return "("+left->toString()+")"+color+data+"("+right->toString()+")";
        }
        
        bool isLeft(){
            return parent->left == this;
        }
        
        Node* getBrother(){
            return (isLeft())?parent->right:parent->left;
        }
        Node* getUncle(){
            return parent->getBrother();
        }
        Node* getGrand(){
            return parent->parent;
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
        
        Node* rotateLeft() {
            Node* root = right;
            right = right->left;
            root->left = this;
            return root;
        }

        Node* rotateRight() {
            Node* root = left;
            left = left->right;
            root->right = this;
            return root;
        }
    private:
        bool red;
    };
public:
    RBTree():
        root(0){
    }
    
    void insert(const T& t){
        root = insert(t,root);
    }
    void remove(const T& t){
        root = remove(t,root);
        root->setBlack();//root always black
    }
    string toString(){
        return root->toString();
    }
private:
    Node* root;
    int size;
    
    Node* insert(const T& t, Node* root) {
        if (root == 0) {
            ++size;
            return new Node(t);
        }
        if (t < root->data) {//left
            root->left = insert(t, root->left);
            root->left->parent = root;
        }else if (t > root->data) {//right
            root->right = insert(t, root->right);
            root->right->parent = root;
        }
        if(root->isBlack()){
            if(root->left != 0 && root->left->left != 0 && root->left->isRed() && root->left->left->isRed()){//case3e "/"
                root = root->rotateRight();
                root->setBlack();
                root->right->setRed();
            }else if(root->right != 0 && root->right->right != 0 && root->right->isRed() && root->right->right->isRed()){//case3d "\"
                root = root->rotateLeft();
                root->setBlack();
                root->left->setRed();
            }
            return root;
        }
        if(root->parent == 0){
            root->setBlack(); //root always black
            return root;
        }
        //red
        if(root->getBrother()->isRed()){//case1de
            root->setBlack();
            root->getBrother()->setBlack();
            root->parent->setRed();
        }
        if(root->getBrother()->isBlack()){//case23de
            if(root->isLeft()){//case23e
                if(root->right->isRed()){//case2e "<" //cause case3e "/"
                    root = root->rotateLeft();
                    root->parent = root->left->parent;
                    root->left->parent = root;
                }
            }else{//case23d
                if(root->left->isRed()){//case2d ">" //cause case3d "\"
                    root = root->rotateRight();
                    root->parent = root->right->parent;
                    root->right->parent = root;
                }
            }
        }
        return root;
    }
    
    Node* remove(const T& t, Node* root){
        return root;
    }
};

#endif	/* RBTREE_H */
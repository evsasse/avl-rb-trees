#ifndef AVLTREE_H
#define	AVLTREE_H

#include <string>
using std::string;

template <typename T>
class AvlTree {
    public:
    struct Node {
        Node *left, *right;
        T data;

        int getHeight() const {
            if (this == 0) return -1;
            return height;
        }

        Node(const T& t) :
        left(0),
        right(0),
        data(t),
        height(0) {
        }

        void updateHeight() {
            height = max(left->getHeight(), right->getHeight()) + 1;
        }

        Node* rightMost() {//biggest node of the subtree
            if (right == 0) return this;
            return right->rightMost();
        }

        Node* rotateLeft() {
            Node* root = right;
            right = right->left;
            root->left = this;
            updateHeight();
            root->updateHeight();
            return root;
        }

        Node* rotateRight() {
            Node* root = left;
            left = left->right;
            root->right = this;
            updateHeight();
            root->updateHeight();
            return root;
        }

        Node* doubleRotateLeft() {
            right = right->rotateRight();
            return rotateLeft();
        }

        Node* doubleRotateRight() {
            left = left->rotateLeft();
            return rotateRight();
        }

        string toString() {
            if (this == 0) return "@";
            return "(" + left->toString() + ")" + data + "(" + right->toString() + ")";

        }
    private:
        int height;

        int max(int a, int b) {
            if (a > b) return a;
            return b;
        }
    };
public:
    AvlTree() :
    root(0) {
    }

    void insert(const T& t) {
        root = insert(t, root);
    }

    void remove(const T& t) {
        root = remove(t, root);
    }

    string toString() {//works for <char>
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
            if (root->left->getHeight() - root->right->getHeight() > 1)
                if (t < root->left->data)//"/"
                    root = root->rotateRight();
                else//"<"
                    root = root->doubleRotateRight();
        } else if (t > root->data) {//right
            root->right = insert(t, root->right);
            if (root->right->getHeight() - root->left->getHeight() > 1)
                if (t > root->right->data) //"\"
                    root = root->rotateLeft();
                else //">"
                    root = root->doubleRotateLeft();
        }
        root->updateHeight();
        return root;
    }

    Node* remove(const T& t, Node* root) {
        if (root == 0)//data not on the tree
            return root;

        if (t < root->data) //left
            root->left = remove(t, root->left);
        else if(t > root->data) //right
            root->right = remove(t, root->right);
        else{//delete root
            --size;
            if(root->left == 0 && root->right == 0){//no child
                delete root;
                return 0;
            }else if(root->left == 0 || root->right == 0){//one child
                Node* aux = (root->left ? root->left : root->right); 
                delete root;
                root = aux;
            }else{//two children
                Node* aux = root->left->rightMost();
                root->data = aux->data;
                root->left = remove(aux->data,root->left);
                root->updateHeight();
            }
        }
        if (root->left->getHeight() - root->right->getHeight() > 1)
            if (t > root->left->data)//"/"
                root = root->rotateRight();
            else//"<"
                root = root->doubleRotateRight();
        else if (root->right->getHeight() - root->left->getHeight() > 1)
            if (t < root->right->data) //"\"
                root = root->rotateLeft();
            else //">"
                root = root->doubleRotateLeft();
        root->updateHeight();
        return root;
    }
};

#endif	/* AVLTREE_H */


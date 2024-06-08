#include <iostream>

using std::endl;
using std::cout;
using std::cin;

struct Node{
    int iPayload;
    Node *ptrLeft, *ptrRight, *ptrParent;

    Node(){}
    Node(int iPayload) : iPayload(iPayload), ptrLeft(nullptr), ptrRight(nullptr), ptrParent(nullptr) {}
    Node(int iPayload, Node* ptrParent) : iPayload(iPayload), ptrLeft(nullptr), ptrRight(nullptr), ptrParent(ptrParent) {}
};

template<typename T> T max(T a, T b){
    return a<b?b:a;
}

template<typename T> T min(T a, T b){
    return a<b?a:b;
}

class BinarySearchTree{

private:
    Node* ptrRoot;
    int size;

    Node* searchParent(Node* u, int iValue){ // retorna o "parente" de iValue
        if(u==nullptr){
            return nullptr;
        }
        if( iValue < (u->iPayload) ){
            if( (u->ptrLeft) != nullptr){
                return searchParent(u->ptrLeft, iValue);
            }
            else{
                return u;
            }
        }
        else{
            if( (u->ptrRight) != nullptr){
                return searchParent(u->ptrRight, iValue);
            }
            else{
                return u;
            }
        }
    }

    void clear(Node* u){
        if(u==nullptr){
            return;
        }

        clear(u->ptrRight);
        clear(u->ptrLeft);

        delete u;
    }

    void traversePreOrder(Node* u){
        if(u==nullptr){
            return;
        }

        cout << u->iPayload << " ";
        traversePreOrder(u->ptrLeft);
        traversePreOrder(u->ptrRight);
    }

    void traverseInOrder(Node* u){
        if(u==nullptr){
            return;
        }

        traverseInOrder(u->ptrLeft);
        cout << u->iPayload << " ";
        traverseInOrder(u->ptrRight);
    }

    void traversePostOrder(Node* u){
        if(u==nullptr){
            return;
        }

        traversePostOrder(u->ptrLeft);
        traversePostOrder(u->ptrRight);
        cout << u->iPayload << " ";
    }
    
    int height(Node* u){
        if(u==nullptr) return 0;

        return 1 + max(height(u->ptrLeft), height(u->ptrRight));
    }

public:
    BinarySearchTree() : ptrRoot(nullptr), size(0) {}

    ~BinarySearchTree(){
        clear();
    }

    void clear(){
        clear(ptrRoot);

        size = 0;
        ptrRoot = nullptr;
    }

    void insert(int iValue){
        if(ptrRoot==nullptr){
            ptrRoot = new Node(iValue);
        }
        else{
            Node* parent = searchParent(ptrRoot, iValue);
            
            if( iValue < (parent->iPayload) ){
                parent->ptrLeft = new Node(iValue, parent);
            }
            else{
                parent->ptrRight = new Node(iValue, parent);
            }
        }

        size++;
    }

    Node* searchNode(int iValue){
        if(ptrRoot==nullptr){
            return nullptr;
        }

        if(ptrRoot->iPayload == iValue){
            return ptrRoot;
        }

        Node* parent = searchParent(ptrRoot, iValue);
            
        if( (parent->ptrLeft->iPayload) == iValue ){
            return parent->ptrLeft;
        }
        else{
            return parent->ptrRight;
        }
    }

    void traversePreOrder(){
        traversePreOrder(ptrRoot);
        cout << endl;
    }
    void traverseInOrder(){
        traverseInOrder(ptrRoot);
        cout << endl;
    }
    void traversePostOrder(){
        traversePostOrder(ptrRoot);
        cout << endl;
    }

    int height(){
        return height(ptrRoot);
    }
};


int main(){

    BinarySearchTree mytree;

    mytree.insert(10);
    mytree.insert(5);
    mytree.insert(15);
    mytree.insert(4);
    mytree.insert(7);

    cout << mytree.height() << endl;

    mytree.traversePreOrder();
    mytree.traverseInOrder();
    mytree.traversePostOrder();

    return 0;
}
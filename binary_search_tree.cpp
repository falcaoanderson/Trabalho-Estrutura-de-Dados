#include <iostream>

using std::endl;
using std::cout;
using std::cin;

template<typename T> struct Node{
    T iPayload;
    Node<T> *ptrLeft, *ptrRight, *ptrParent;

    Node(){}
    Node(T iPayload) : iPayload(iPayload), ptrLeft(nullptr), ptrRight(nullptr), ptrParent(nullptr) {}
    Node(T iPayload, Node<T>* ptrParent) : iPayload(iPayload), ptrLeft(nullptr), ptrRight(nullptr), ptrParent(ptrParent) {}
};

template<typename T> T max(T a, T b){
    return a<b?b:a;
}

template<typename T> T min(T a, T b){
    return a<b?a:b;
}

template<typename T> 
class BinarySearchTree{

private:
    Node<T>* ptrRoot;
    int size;

    Node<T>* searchParent(Node<T>* u, T iValue){ // retorna o "parente" de iValue
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

    void clear(Node<T>* u){
        if(u==nullptr){
            return;
        }

        clear(u->ptrRight);
        clear(u->ptrLeft);

        delete u;
    }

    void traversePreOrder(Node<T>* u){
        if(u==nullptr){
            return;
        }

        cout << u->iPayload << " ";
        traversePreOrder(u->ptrLeft);
        traversePreOrder(u->ptrRight);
    }

    void traverseInOrder(Node<T>* u){
        if(u==nullptr){
            return;
        }

        traverseInOrder(u->ptrLeft);
        cout << u->iPayload << " ";
        traverseInOrder(u->ptrRight);
    }

    void traversePostOrder(Node<T>* u){
        if(u==nullptr){
            return;
        }

        traversePostOrder(u->ptrLeft);
        traversePostOrder(u->ptrRight);
        cout << u->iPayload << " ";
    }
    
    int height(Node<T>* u){
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

    void insert(T iValue){
        if(ptrRoot==nullptr){
            ptrRoot = new Node<T>(iValue);
        }
        else{
            Node<T>* parent = searchParent(ptrRoot, iValue);
            
            if( iValue < (parent->iPayload) ){
                parent->ptrLeft = new Node<T>(iValue, parent);
            }
            else{
                parent->ptrRight = new Node<T>(iValue, parent);
            }
        }

        size++;
    }

    Node<T>* searchNode(T iValue){
        if(ptrRoot==nullptr){
            return nullptr;
        }

        if(ptrRoot->iPayload == iValue){
            return ptrRoot;
        }

        Node<T>* parent = searchParent(ptrRoot, iValue);
            
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

    BinarySearchTree<int> mytree;

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
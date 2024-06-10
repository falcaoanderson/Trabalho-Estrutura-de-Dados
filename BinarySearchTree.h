#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

using std::endl;
using std::cout;
using std::cin;

namespace tree{

template<typename T> struct Node{
    T payload;
    Node<T> *ptrLeft, *ptrRight, *ptrParent;

    Node(){}
    Node(T payload) : payload(payload), ptrLeft(nullptr), ptrRight(nullptr), ptrParent(nullptr) {}
    Node(T payload, Node<T>* ptrParent) : payload(payload), ptrLeft(nullptr), ptrRight(nullptr), ptrParent(ptrParent) {}
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

    Node<T>* searchParent(Node<T>* u, T value){ // retorna o "parente" de value
        if(u==nullptr){
            return nullptr;
        }
        if( value < (u->payload) ){
            if( (u->ptrLeft) != nullptr){
                return searchParent(u->ptrLeft, value);
            }
            else{
                return u;
            }
        }
        else{
            if( (u->ptrRight) != nullptr){
                return searchParent(u->ptrRight, value);
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

        cout << u->payload << " ";
        traversePreOrder(u->ptrLeft);
        traversePreOrder(u->ptrRight);
    }

    void traverseInOrder(Node<T>* u){
        if(u==nullptr){
            return;
        }

        traverseInOrder(u->ptrLeft);
        cout << u->payload << " ";
        traverseInOrder(u->ptrRight);
    }

    void traversePostOrder(Node<T>* u){
        if(u==nullptr){
            return;
        }

        traversePostOrder(u->ptrLeft);
        traversePostOrder(u->ptrRight);
        cout << u->payload << " ";
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

    void insert(T value){
        if(ptrRoot==nullptr){
            ptrRoot = new Node<T>(value);
        }
        else{
            Node<T>* parent = searchParent(ptrRoot, value);
            
            if( value < (parent->payload) ){
                parent->ptrLeft = new Node<T>(value, parent);
            }
            else{
                parent->ptrRight = new Node<T>(value, parent);
            }
        }

        size++;
    }

    Node<T>* searchNode(T value){
        if(ptrRoot==nullptr){
            return nullptr;
        }

        if(ptrRoot->payload == value){
            return ptrRoot;
        }

        Node<T>* parent = searchParent(ptrRoot, value);
            
        if( (parent->ptrLeft->payload) == value ){
            return parent->ptrLeft;
        }
        else{
            return parent->ptrRight;
        }
    }

    int height(){
        return height(ptrRoot);
    }

    void traversePreOrder(){
        cout << "PreOrder: ";
        traversePreOrder(ptrRoot);
        cout << endl;
    }
    void traverseInOrder(){
        cout << "InOrder: ";
        traverseInOrder(ptrRoot);
        cout << endl;
    }
    void traversePostOrder(){
        cout << "PostOrder: ";
        traversePostOrder(ptrRoot);
        cout << endl;
    }

    void bfsTraversal(){
        cout << "BFSOrder: "; 

        if (ptrRoot == nullptr) return;
        
        // Parte 1 do Trabalho: Alterar para Lista Encadeada
        Node<T>* nodeQueue[100];
        int idxFront = 0, idxBack = 0;
        
        nodeQueue[idxBack] = ptrRoot;
        idxBack++;
        
        while (idxFront < idxBack){
            Node<T>* currentNode = nodeQueue[idxFront];
            idxFront++;
            
            cout << currentNode->payload << " ";
            
            if (currentNode->ptrLeft != nullptr){
                nodeQueue[idxBack] = currentNode->ptrLeft;
                idxBack++;
            }
            
            if (currentNode->ptrRight != nullptr){
                nodeQueue[idxBack] = currentNode->ptrRight;
                idxBack++;
            }
        }

        cout << endl;
    }

    void transplant(Node<T>* u, Node<T>* v){ // leva v para u
        if(u->ptrParent == nullptr){
            ptrRoot = v;
        }
        else if(u->ptrParent->ptrLeft == u){
            u->ptrParent->ptrLeft = v;
        }   
        else if(u->ptrParent->ptrRight == u){
            u->ptrParent->ptrRight = v;
        }

        if(v != nullptr){
            v->ptrParent = u->ptrParent;
        }
    }
    
    Node<T>* searchMinimum(Node<T>* u){
        if(u==nullptr) return nullptr;

        while(u->ptrLeft != nullptr){
            u = u->ptrLeft;
        }

        return u;
    }

    void deleteNode(T val){
        Node<T>* u = searchNode(val);

        cout << u->payload << endl;

        if(u == nullptr) return;

        if(u->ptrLeft == nullptr){
            transplant(u, u->ptrRight);
        }
        else if(u->ptrRight == nullptr){
            transplant(u, u->ptrLeft);
        }
        else{
            Node<T>* successor = searchMinimum(u->ptrRight);

            if(successor != u->ptrRight){
                transplant(successor, successor->ptrRight);

                successor->ptrRight = u->ptrRight;
                u->ptrRight->ptrParent = successor;
            }

            transplant(u, successor);
            successor->ptrLeft = u->ptrLeft;
            u->ptrLeft->ptrParent = successor;
        }

        delete u;
    }

};

}

#endif
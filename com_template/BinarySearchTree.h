#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include "Linked_list.h"
#include "utils.h"

using std::endl;
using std::cout;
using std::cin;

namespace bst{

template<typename T> struct Node{
    T payload;
    Node<T> *ptrLeft, *ptrRight, *ptrParent;

    Node(){}
    Node(T payload) : payload(payload), ptrLeft(nullptr), ptrRight(nullptr), ptrParent(nullptr) {}
    Node(T payload, Node<T>* ptrParent) : payload(payload), ptrLeft(nullptr), ptrRight(nullptr), ptrParent(ptrParent) {}
};

template<typename T> 
class BinarySearchTree{

private:
    Node<T>* ptrRoot;
    int iSize;

    Node<T>* searchParent(Node<T>* u, T value) const{ // retorna o "parente" de value
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

    void traversePreOrder(Node<T>* u) const{
        if(u==nullptr){
            return;
        }

        cout << u->payload << " ";
        traversePreOrder(u->ptrLeft);
        traversePreOrder(u->ptrRight);
    }

    void traverseInOrder(Node<T>* u) const{
        if(u==nullptr){
            return;
        }

        traverseInOrder(u->ptrLeft);
        cout << u->payload << " ";
        traverseInOrder(u->ptrRight);
    }

    void traversePostOrder(Node<T>* u) const{
        if(u==nullptr){
            return;
        }

        traversePostOrder(u->ptrLeft);
        traversePostOrder(u->ptrRight);
        cout << u->payload << " ";
    }
    
    int height(Node<T>* u) const{
        if(u==nullptr) return 0;

        return 1 + max(height(u->ptrLeft), height(u->ptrRight));
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
    
    Node<T>* searchMinimum(Node<T>* u) const{
        if(u==nullptr) return nullptr;

        while(u->ptrLeft != nullptr){
            u = u->ptrLeft;
        }

        return u;
    }


public:
    BinarySearchTree() : ptrRoot(nullptr), iSize(0) {}

    ~BinarySearchTree(){
        clear();
    }

    void clear(){ // Complexity: O(N)
        clear(ptrRoot);

        iSize = 0;
        ptrRoot = nullptr;
    }

    void insert(T value){ // Complexity: O(H)
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

        iSize++;
    }

    Node<T>* searchNode(T value) const{ // Complexity: O(H)
        Node<T>* u = ptrRoot;

        while(u!=nullptr){
            if(u->payload == value) break;
            
            if(value < (u->payload)){
                u = u->ptrLeft;
            }
            else{
                u = u->ptrRight;
            }
        }

        return u;
    }

    void deleteNode(T val){ // Complexity: O(H)
        Node<T>* u = searchNode(val);

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

        iSize--;
        delete u;
    }

    Node<T>* searchNodeBFS(T value) const{ // Complexity: O(N);
        if (ptrRoot == nullptr) return nullptr;
        
        List< Node<T>* > nodeQueue;
        nodeQueue.insertBack(ptrRoot);
        
        while (!nodeQueue.empty()){
            Node<T>* currentNode = nodeQueue.getFront();
            nodeQueue.popFront();
            
            if(currentNode->payload == value){
                return currentNode;
            }
            
            if(currentNode->ptrLeft != nullptr){
                nodeQueue.insertBack(currentNode->ptrLeft);
            }
            
            if(currentNode->ptrRight != nullptr){
                nodeQueue.insertBack(currentNode->ptrRight);
            }
        }

        return nullptr;
    }

    int height() const{ // Complexity: O(H)
        return height(ptrRoot);
    }

    void traversePreOrder() const{
        cout << "PreOrder: ";
        traversePreOrder(ptrRoot);
        cout << endl;
    }
    void traverseInOrder() const{
        cout << "InOrder: ";
        traverseInOrder(ptrRoot);
        cout << endl;
    }
    void traversePostOrder() const{
        cout << "PostOrder: ";
        traversePostOrder(ptrRoot);
        cout << endl;
    }

    void bfsTraversal() const{
        cout << "BFSOrder: "; 

        if (ptrRoot == nullptr) return;
        
        List< Node<T>* > nodeQueue;
        
        nodeQueue.insertBack(ptrRoot);
        
        while (!nodeQueue.empty()){
            Node<T>* currentNode = nodeQueue.getFront();
            nodeQueue.popFront();
            
            cout << currentNode->payload << " ";
            
            if (currentNode->ptrLeft != nullptr){
                nodeQueue.insertBack(currentNode->ptrLeft);
            }
            
            if (currentNode->ptrRight != nullptr){
                nodeQueue.insertBack(currentNode->ptrRight);
            }
        }
        
        cout << endl;
    }

    int size() const{
        return iSize;
    }

};

} // final tree namespace

#endif // BINARY_SEARCH_TREE_H
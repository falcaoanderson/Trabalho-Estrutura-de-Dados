#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>
#include <cassert>

using std::endl;
using std::cout;
using std::cin;

template <typename T> struct Node {
    T tVal;
    Node<T>* ptrNext;
    Node<T>* ptrPrev;

    Node(T tVal) : tVal(tVal), ptrNext(nullptr), ptrPrev(nullptr) {}
};

template <typename T> struct List {
private:
    int iSize;
    Node<T>* ptrFront;
    Node<T>* ptrBack;

public:
    List() : iSize(0), ptrFront(nullptr), ptrBack(nullptr) {}

    ~List(){
        clear();
    }

    void clear(){
        if(empty()) return;

        Node<T>* crrNode = ptrFront;

        while(crrNode != nullptr){
            Node<T>* aux = crrNode->ptrNext;
            delete crrNode;
            crrNode = aux;
        }

        ptrFront = nullptr;  
        ptrBack = nullptr;
        iSize = 0;
    }

    int size() const{
        return iSize;
    }
    bool empty() const{
        return (iSize==0);
    }

    void insertFront(T tVal){
        Node<T>* newNode = new Node<T>(tVal);

        if(ptrFront==nullptr){
            ptrBack  = newNode;
        }
        else{
            newNode ->ptrNext = ptrFront;
            ptrFront->ptrPrev = newNode;
        }

        ptrFront = newNode;

        iSize++;
    }

    void insertBack(T tVal){
        Node<T>* newNode = new Node<T>(tVal);

        if(ptrFront==nullptr){
            ptrFront = newNode;
        }
        else{
            newNode->ptrPrev = ptrBack;
            ptrBack->ptrNext = newNode;
        }

        ptrBack = newNode;

        iSize++;
    }

    Node<T>* SearchNodeByValue(T tVal) const{
        Node<T>* crrNode = ptrFront;

        while (crrNode!=nullptr && crrNode->tVal != tVal){
            crrNode = crrNode->ptrNext;
        }

        if(crrNode!=nullptr && crrNode->tVal == tVal){
            return crrNode;
        }
        else{
            return nullptr;
        }
    }

    void insertAfter(T tVal, T newValue){
        Node<T>* crrNode = SearchNodeByValue(tVal);

        if (crrNode!=nullptr){

            Node<T>* newNode = new Node<T>(newValue);

            newNode->ptrNext = crrNode->ptrNext;
            newNode->ptrPrev = crrNode;

            if(crrNode->ptrNext){
                crrNode->ptrNext->ptrPrev = newNode;
            } 
            else{
                ptrBack = newNode;
            }
            crrNode->ptrNext = newNode;

            iSize++;
        }
    }

    void insertBefore(T tVal, T newValue){
        Node<T>* crrNode=SearchNodeByValue(tVal);

        if (crrNode!=nullptr) {
            Node<T>* newNode = new Node<T>(newValue);

            newNode->ptrNext = crrNode;
            newNode->ptrPrev = crrNode->ptrPrev;

            if(crrNode->ptrPrev != nullptr){
                crrNode->ptrPrev->ptrNext = newNode;
            } 
            else{
                ptrFront = newNode;
            }

            crrNode->ptrPrev = newNode;

            iSize++;
        }
    }

    void deleteByValue(T tVal){
        Node<T>* crrNode = SearchNodeByValue(tVal);

        if (crrNode!=nullptr){
            if (crrNode->ptrPrev){
                crrNode->ptrPrev->ptrNext = crrNode->ptrNext;
            } 
            else{
                ptrFront = crrNode->ptrNext;
            }

            if(crrNode->ptrNext){
                crrNode->ptrNext->ptrPrev = crrNode->ptrPrev;
            } 
            else{
                ptrBack = crrNode->ptrPrev;
            }

            delete crrNode;

            iSize--;
        }
    }

    void popFront(){
        Node<T>* crrNode = ptrFront;

        if (crrNode!=nullptr){
            ptrFront = crrNode->ptrNext;

            if(crrNode->ptrNext != nullptr){
                crrNode->ptrNext->ptrPrev = nullptr;
            } 
            else{
                ptrBack = nullptr;
            }

            iSize--;
            delete crrNode;
        }
    }

    void displayList() const{
        Node<T>* crrNode = ptrFront;

        cout << "List: ";
        while(crrNode!=nullptr){
            cout << crrNode->tVal << " ";

            crrNode = crrNode->ptrNext;
        }
        cout << endl;
    }

    Node<T>* getPtrFront() const{
        return ptrFront;
    }

    T getFront() const{
        assert(ptrFront != nullptr);

        return ptrFront->tVal;
    }

    void resetList(const std::vector<T>& v){
        clear();

        for(T x: v){
            insertBack(x);
        }
    }
};

#endif
#include "Linked_list.h"

#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;

Node::Node(int iVal, Node* ptrNext=nullptr, Node* ptrPrev=nullptr){
    this->iVal     = iVal;
    this->ptrNext  = ptrNext;
    this->ptrPrev  = ptrPrev;
}


List::List() {
    this->iSize    = 0;
    this->ptrFront = nullptr;
    this->ptrBack  = nullptr;
}
List::~List(){
    clear();
}

void List::clear() {
    if(empty()) return;

    Node* crrNode = ptrFront;

    while(crrNode != nullptr){
        Node* aux = crrNode->ptrNext;
        delete crrNode;
        crrNode = aux;
    }

    ptrFront = nullptr;  
    ptrBack = nullptr;
    iSize = 0;
}

int List::size(){
    return iSize;
}
bool List::empty(){
    return (iSize==0);
}

void List::insertFront(int iVal){
    Node* newNode = new Node(iVal);

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

void List::insertBack(int iVal) {
    Node* newNode = new Node(iVal);

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

Node* List::SearchNodeByValue(int iVal) {
    Node* crrNode = ptrFront;

    while (crrNode!=nullptr && crrNode->iVal != iVal) {
        crrNode = crrNode->ptrNext;
    }

    if(crrNode!=nullptr && crrNode->iVal == iVal){
        return crrNode;
    }
    else{
        return nullptr;
    }
}

void List::insertAfter(int iVal, int newValue) {
    Node* crrNode = SearchNodeByValue(iVal);

    if (crrNode!=nullptr) {

        Node* newNode = new Node(newValue);

        newNode->ptrNext = crrNode->ptrNext;
        newNode->ptrPrev = crrNode;

        if(crrNode->ptrNext){
            crrNode->ptrNext->ptrPrev = newNode;
        } 
        else{
            ptrBack = newNode;
        }
        crrNode->ptrNext = newNode;
    }
}

void List::insertBefore(int iVal, int newValue) {
    Node* crrNode=SearchNodeByValue(iVal);

    if (crrNode!=nullptr) {
        Node* newNode = new Node(newValue);

        newNode->ptrNext = crrNode;
        newNode->ptrPrev = crrNode->ptrPrev;

        if(crrNode->ptrPrev != nullptr){
            crrNode->ptrPrev->ptrNext = newNode;
        } 
        else{
            ptrFront = newNode;
        }

        crrNode->ptrPrev = newNode;
    }
}

void List::deleteByValue(int iVal) {
    Node* crrNode = SearchNodeByValue(iVal);

    if (crrNode!=nullptr) {
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
    }
}

void List::displayList() {
    Node* crrNode = ptrFront;

    cout << "List: ";
    while(crrNode!=nullptr) {
        cout << crrNode->iVal << " ";

        crrNode = crrNode->ptrNext;
    }
    cout << endl;
}

Node* List::getPtrFront(){
    return ptrFront;
}

void List::resetList(const std::vector<int>& v) {
    clear();

    for(int x: v){
        insertBack(x);
    }
}

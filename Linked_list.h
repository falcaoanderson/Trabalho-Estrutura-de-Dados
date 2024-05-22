#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <vector>
#include <chrono>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using namespace std::chrono;

struct Node {

    int iVal;

    Node* ptrNext;

    Node* ptrPrev;

    Node(int iVal, Node* ptrNext=nullptr, Node* ptrPrev=nullptr){

        this->iVal     = iVal;

        this->ptrNext  = ptrNext;

        this->ptrPrev  = ptrPrev;

    }
};

struct List {
    int iSize;
    Node* ptrFront;
    Node* ptrBack;

    List(int iSize=0, Node* ptrFront = nullptr, Node* ptrBack = nullptr) {
        this->iSize    = iSize;
        this->ptrFront = ptrFront;
        this->ptrBack  = ptrBack;
    }
    ~List(){
        clear();
    }

    void clear() {
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


    int size(){
        return iSize;
    }
    bool empty(){
        return (iSize==0);
    }

    void insertFront(int iVal){
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

    void insertBack(int iVal) {
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

    Node* SearchNodeByValue(int iVal) {
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

    void insertAfter(int iVal, int newValue) {
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

    void insertBefore(int iVal, int newValue) {
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

    void deleteByValue(int iVal) {
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

    void displayList() {
        Node* crrNode = ptrFront;

        cout << "List: ";
        while(crrNode!=nullptr) {
            cout << crrNode->iVal << " ";

            crrNode = crrNode->ptrNext;
        }
        cout << endl;
    }

    Node* getPtrFront(){
        return ptrFront;
    }
};

// int measureAndSort(void (*sortFunction)(List&), List& list){
//     high_resolution_clock::time_point start = high_resolution_clock::now();

//     sortFunction(list);

//     high_resolution_clock::time_point stop = high_resolution_clock::now();

//     int duration = duration_cast<milliseconds>(stop - start).count();

//     return duration;
// }

// void prepareList(List& list, const std::vector<int>& v) {
//     for (int x : v) {

//         list.insertBack(x);

//     }

//     // cout << "Lista original:" << endl;

//     // list.displayList();
// }

// void resetList(List& list, const std::vector<int>& v) {

//     list.clear();

//     prepareList(list, v);

// }

#endif // GENERATE_EXAMPLE_H
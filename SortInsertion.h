#ifndef SORT_INSERTION
#define SORT_INSERTION

#include "Linked_list.h"
#include "utils.h"

void InsertionSort(List &list){
    Node* currentNode = list.getPtrFront();

    while(currentNode!=nullptr){
        Node* it = currentNode->ptrPrev;

        while(it!=nullptr && (it->iVal) > (it->ptrNext->iVal)){
            swap(it->iVal, it->ptrNext->iVal);
          
            it = it->ptrPrev;
        }

        currentNode = currentNode->ptrNext;
    }
}

void OptimizedInsertionSort(List &list){
    Node* currentNode = list.getPtrFront();

    while(currentNode!=nullptr){
        Node* it = currentNode;
        int aux = currentNode->iVal;

        while(it->ptrPrev!=nullptr && (it->ptrPrev->iVal) > aux){
            it->iVal = it->ptrPrev->iVal;
          
            it = it->ptrPrev;
        }
        it->iVal = aux;
    
        currentNode = currentNode->ptrNext;
    }
}

void InsertionSort(List &list, int gap, int start=0){
    Node* startNode = list.getPtrFront();

    while(startNode!=nullptr && start){
        startNode = startNode->ptrNext;
        start--;
    }
    
    Node* currentNode = startNode;
    startNode = startNode->ptrPrev;

    while(currentNode!=nullptr){
        Node* itp = currentNode;
        Node* it = currentNode;

        for(int k=0; k<gap && itp!=startNode; k++){
            itp = itp->ptrPrev;
        }

        while(itp!=startNode && itp->iVal > it->iVal){
            swap(itp->iVal, it->iVal);
            
            it = itp;
            for(int k=0; k<gap && itp!=startNode; k++){
                itp = itp->ptrPrev;
            }
        }

        for(int k=0; k<gap && currentNode!=nullptr; k++){
            currentNode = currentNode->ptrNext;
        }
    }
}

void OptimizedInsertionSort(List &list, int gap, int start=0){
    Node* startNode = list.getPtrFront();

    while(startNode!=nullptr && start){
        startNode = startNode->ptrNext;
        start--;
    }
    
    Node* currentNode = startNode;
    startNode = startNode->ptrPrev;

    while(currentNode!=nullptr){
        int aux = currentNode->iVal;
        Node* it  = currentNode;
        Node* itp = currentNode;

        for(int k=0; k<gap && itp!=startNode; k++){
            itp = itp->ptrPrev;
        }

        while(itp!=startNode && itp->iVal > aux){
            it->iVal = itp->iVal;
            
            it = itp;
            for(int k=0; k<gap && itp!=startNode; k++){
                itp = itp->ptrPrev;
            }
        }
        it->iVal = aux;

        for(int k=0; k<gap && currentNode!=nullptr; k++){
            currentNode = currentNode->ptrNext;
        }
    }
}


#endif
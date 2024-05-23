#ifndef SORT_INSERTION
#define SORT_INSERTION

#include "Linked_list.h"
#include "utils.h"

template<typename T>
void InsertionSort(List<T> &list){
    Node<T>* currentNode = list.getPtrFront();

    while(currentNode!=nullptr){
        Node<T>* it = currentNode->ptrPrev;

        while(it!=nullptr && (it->tVal) > (it->ptrNext->tVal)){
            swap(it->tVal, it->ptrNext->tVal);
          
            it = it->ptrPrev;
        }

        currentNode = currentNode->ptrNext;
    }
}

template<typename T>
void OptimizedInsertionSort(List<T> &list){
    Node<T>* currentNode = list.getPtrFront();

    while(currentNode!=nullptr){
        Node<T>* it = currentNode;
        int aux = currentNode->tVal;

        while(it->ptrPrev!=nullptr && (it->ptrPrev->tVal) > aux){
            it->tVal = it->ptrPrev->tVal;
          
            it = it->ptrPrev;
        }
        it->tVal = aux;
    
        currentNode = currentNode->ptrNext;
    }
}

template<typename T>
void InsertionSort(List<T> &list, int gap, int start=0){
    Node<T>* startNode = list.getPtrFront();

    while(startNode!=nullptr && start){
        startNode = startNode->ptrNext;
        start--;
    }
    
    Node<T>* currentNode = startNode;
    startNode = startNode->ptrPrev;

    while(currentNode!=nullptr){
        Node<T>* itp = currentNode;
        Node<T>* it = currentNode;

        for(int k=0; k<gap && itp!=startNode; k++){
            itp = itp->ptrPrev;
        }

        while(itp!=startNode && itp->tVal > it->tVal){
            swap(itp->tVal, it->tVal);
            
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

template<typename T>
void OptimizedInsertionSort(List<T> &list, int gap, int start=0){
    Node<T>* startNode = list.getPtrFront();

    while(startNode!=nullptr && start){
        startNode = startNode->ptrNext;
        start--;
    }
    
    Node<T>* currentNode = startNode;
    startNode = startNode->ptrPrev;

    while(currentNode!=nullptr){
        int aux = currentNode->tVal;
        Node<T>* it  = currentNode;
        Node<T>* itp = currentNode;

        for(int k=0; k<gap && itp!=startNode; k++){
            itp = itp->ptrPrev;
        }

        while(itp!=startNode && itp->tVal > aux){
            it->tVal = itp->tVal;
            
            it = itp;
            for(int k=0; k<gap && itp!=startNode; k++){
                itp = itp->ptrPrev;
            }
        }
        it->tVal = aux;

        for(int k=0; k<gap && currentNode!=nullptr; k++){
            currentNode = currentNode->ptrNext;
        }
    }
}

#endif
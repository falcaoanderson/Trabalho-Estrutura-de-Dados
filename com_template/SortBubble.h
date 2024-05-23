#ifndef SORT_BUBBLE
#define SORT_BUBBLE

#include "Linked_list.h"
#include "utils.h"

template<typename T>
void BubbleSort(List<T> &list) {
    Node<T>* it = list.getPtrFront();

    while(it!=nullptr){
        Node<T>* crrNode = list.getPtrFront();
        
        while(crrNode!=nullptr && crrNode->ptrNext!=nullptr){
            if((crrNode->tVal)>(crrNode->ptrNext->tVal)){
                swap(crrNode->tVal, crrNode->ptrNext->tVal); 
            }

            crrNode = crrNode->ptrNext;
        }

        it = it->ptrNext;
    }
}

template<typename T>
void OptimizedBubbleSort(List<T> &list){
    bool sorted = 0;

    while(!sorted){
        sorted = 1;

        Node<T>* crrNode = list.getPtrFront();
        while(crrNode!=nullptr && crrNode->ptrNext!=nullptr){
            if((crrNode->tVal)>(crrNode->ptrNext->tVal)){
                swap(crrNode->tVal, crrNode->ptrNext->tVal);

                sorted = 0;
            }

            crrNode = crrNode->ptrNext;
        }
    }
}

#endif
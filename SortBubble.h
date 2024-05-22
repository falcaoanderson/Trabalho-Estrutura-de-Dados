#ifndef SORT_BUBBLE
#define SORT_BUBBLE

#include "Linked_list.h"
#include "utils.h"

void BubbleSort(List &list) {
    Node* it = list.getPtrFront();

    while(it!=nullptr){
        Node* crrNode = list.getPtrFront();
        
        while(crrNode!=nullptr && crrNode->ptrNext!=nullptr){
            if((crrNode->iVal)>(crrNode->ptrNext->iVal)){
                int aux = crrNode->iVal;
                
                crrNode->iVal = crrNode->ptrNext->iVal;
                
                crrNode->ptrNext->iVal = aux;    
            }

            crrNode = crrNode->ptrNext;
        }

        it = it->ptrNext;
    }
}

void OptimizedBubbleSort(List &list){
    bool sorted = 0;

    while(!sorted){
        sorted = 1;

        Node* crrNode = list.getPtrFront();
        while(crrNode!=nullptr && crrNode->ptrNext!=nullptr){
            if((crrNode->iVal)>(crrNode->ptrNext->iVal)){
                int aux = crrNode->iVal;

                crrNode->iVal = crrNode->ptrNext->iVal;

                crrNode->ptrNext->iVal = aux;    

                sorted = 0;
            }

            crrNode = crrNode->ptrNext;
        }
    }
}

#endif
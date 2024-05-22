#ifndef SORT_BUBBLE
#define SORT_BUBBLE
#include "Linked_list.h"
#include "GenerateExample.h"
#include "utils.h"

void BubbleSort(List &list){
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

void OptimizedBubbleSort(List &list) {

    bool swapped;

    Node* endNode = nullptr;

    do {

        swapped = false;

        Node* currentNode = list.getPtrFront();

        while (currentNode->ptrNext != endNode) {

            if (currentNode->iVal > currentNode->ptrNext->iVal) {

                swap(currentNode->iVal, currentNode->ptrNext->iVal);

                swapped = true;

            }

            currentNode = currentNode->ptrNext;
        }

        endNode = currentNode;

    } while (swapped);
}
#endif
#ifndef SORT_SELECTION
#define SORT_SELECTION

#include "Linked_list.h"
#include "GenerateExample.h"
#include "utils.h"

void SelectionSort(List &list){
    Node* currentNode = list.getPtrFront();

    while (currentNode) {
        Node* j = currentNode->ptrNext;

        while (j) {
            if (j->iVal < currentNode->iVal) {
                swap(currentNode->iVal, j->iVal);
            }
            j = j->ptrNext;
        }

        currentNode = currentNode->ptrNext;
    }
}

void OptimizedSelectionSort(List &list) {
    Node* currentNode = list.getPtrFront();

    while (currentNode) {
        Node* minNode = currentNode;
        Node* j = currentNode->ptrNext;

        while (j) {
            if (j->iVal < minNode->iVal) {
                minNode = j;
            }
            j = j->ptrNext;
        }

        swap(currentNode->iVal, minNode->iVal);

        currentNode = currentNode->ptrNext;
    }
}

#endif
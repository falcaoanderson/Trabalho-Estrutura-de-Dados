#ifndef SORT_SELECTION
#define SORT_SELECTION

#include "Linked_list.h"
#include "GenerateExample.h"
#include "utils.h"

void SelectionSort(List &list){
    // List aux;
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

void OptimizedSelectionSort(List &list) {

    Node* startNode = list.getPtrFront();

    while (startNode) {

        Node* minNode = startNode;

        Node* currentNode = startNode->ptrNext;

        while (currentNode) {
            if (currentNode->iVal < minNode->iVal) {

                minNode = currentNode;

            }

            currentNode = currentNode->ptrNext;
        }
        if (minNode != startNode) {

            swap(minNode->iVal, startNode->iVal);

        }

        startNode = startNode->ptrNext;
    }
}
#endif
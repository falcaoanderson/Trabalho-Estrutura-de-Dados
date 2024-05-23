#include "SortSelection.h"
#include "Linked_list.h"
#include "utils.h"

void SelectionSort(List &list){
    Node* currentNode = list.getPtrFront();

    while (currentNode != nullptr) {
        Node* j = currentNode->ptrNext;

        while (j != nullptr) {
            if (j->iVal < currentNode->iVal) {
                swap(currentNode->iVal, j->iVal);
            }
            j = j->ptrNext;
        }

        currentNode = currentNode->ptrNext;
    }
}

void OptimizedSelectionSort(List &list){
    Node* currentNode = list.getPtrFront();

    while (currentNode != nullptr) {
        Node* minNode = currentNode;
        Node* j = currentNode->ptrNext;

        while (j != nullptr) {
            if (j->iVal < minNode->iVal) {
                minNode = j;
            }
            j = j->ptrNext;
        }

        swap(currentNode->iVal, minNode->iVal);

        currentNode = currentNode->ptrNext;
    }
}
#ifndef SORT_SELECTION
#define SORT_SELECTION

#include "Linked_list.h"
#include "utils.h"

template<typename T>
void SelectionSort(List<T> &list){
    Node<T>* currentNode = list.getPtrFront();

    while (currentNode != nullptr) {
        Node<T>* j = currentNode->ptrNext;

        while (j != nullptr) {
            if (j->tVal < currentNode->tVal) {
                swap(currentNode->tVal, j->tVal);
            }
            j = j->ptrNext;
        }

        currentNode = currentNode->ptrNext;
    }
}

template<typename T>
void OptimizedSelectionSort(List<T> &list){
    Node<T>* currentNode = list.getPtrFront();

    while (currentNode != nullptr) {
        Node<T>* minNode = currentNode;
        Node<T>* j = currentNode->ptrNext;

        while (j != nullptr) {
            if (j->tVal < minNode->tVal) {
                minNode = j;
            }
            j = j->ptrNext;
        }

        swap(currentNode->tVal, minNode->tVal);

        currentNode = currentNode->ptrNext;
    }
}

#endif
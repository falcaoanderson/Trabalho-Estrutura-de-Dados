#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>

struct Node {
    int iVal;
    Node* ptrNext;
    Node* ptrPrev;

    Node(int iVal, Node* ptrNext, Node* ptrPrev);
};

struct List {
    int iSize;
    Node* ptrFront;
    Node* ptrBack;

    List();

    ~List();

    void clear();

    int size();

    bool empty();

    void insertFront(int iVal);

    void insertBack(int iVal);

    Node* SearchNodeByValue(int iVal);

    void insertAfter(int iVal, int newValue);

    void insertBefore(int iVal, int newValue);

    void deleteByValue(int iVal);

    void displayList();

    Node* getPtrFront();

    void resetList(const std::vector<int>& v);
};

#endif
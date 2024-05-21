#include <iostream>
#include <vector>
#include <chrono>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using namespace std::chrono;

struct Node {

    int iVal;

    Node* ptrNext;

    Node* ptrPrev;

    Node(int iVal, Node* ptrNext=nullptr, Node* ptrPrev=nullptr){

        this->iVal     = iVal;

        this->ptrNext  = ptrNext;

        this->ptrPrev  = ptrPrev;

    }
};

struct List {
    int iSize;
    Node* ptrFront;
    Node* ptrBack;

    List(int iSize=0, Node* ptrFront = nullptr, Node* ptrBack = nullptr) {
        this->iSize    = iSize;
        this->ptrFront = ptrFront;
        this->ptrBack  = ptrBack;
    }
    ~List(){
        clear();
    }

    void clear() {
        if(empty()) return;

        Node* crrNode = ptrFront;

        while(crrNode != nullptr){
            Node* aux = crrNode->ptrNext;
            delete crrNode;
            crrNode = aux;
        }

        ptrFront = nullptr;  
        ptrBack = nullptr;
        iSize = 0;
    }


    int size(){
        return iSize;
    }
    bool empty(){
        return (iSize==0);
    }

    void insertFront(int iVal){
        Node* newNode = new Node(iVal);

        if(ptrFront==nullptr){
            ptrBack  = newNode;
        }
        else{
            newNode ->ptrNext = ptrFront;
            ptrFront->ptrPrev = newNode;
        }

        ptrFront = newNode;

        iSize++;
    }

    void insertBack(int iVal) {
        Node* newNode = new Node(iVal);

        if(ptrFront==nullptr){
            ptrFront = newNode;
        }
        else{
            newNode->ptrPrev = ptrBack;
            ptrBack->ptrNext = newNode;
        }

        ptrBack = newNode;

        iSize++;
    }

    Node* SearchNodeByValue(int iVal) {
        Node* crrNode = ptrFront;

        while (crrNode!=nullptr && crrNode->iVal != iVal) {
            crrNode = crrNode->ptrNext;
        }

        if(crrNode!=nullptr && crrNode->iVal == iVal){
            return crrNode;
        }
        else{
            return nullptr;
        }
    }

    void insertAfter(int iVal, int newValue) {
        Node* crrNode = SearchNodeByValue(iVal);

        if (crrNode!=nullptr) {

            Node* newNode = new Node(newValue);

            newNode->ptrNext = crrNode->ptrNext;
            newNode->ptrPrev = crrNode;

            if(crrNode->ptrNext){
                crrNode->ptrNext->ptrPrev = newNode;
            } 
            else{
                ptrBack = newNode;
            }
            crrNode->ptrNext = newNode;
        }
    }

    void insertBefore(int iVal, int newValue) {
        Node* crrNode=SearchNodeByValue(iVal);

        if (crrNode!=nullptr) {
            Node* newNode = new Node(newValue);

            newNode->ptrNext = crrNode;
            newNode->ptrPrev = crrNode->ptrPrev;

            if(crrNode->ptrPrev != nullptr){
                crrNode->ptrPrev->ptrNext = newNode;
            } 
            else{
                ptrFront = newNode;
            }

            crrNode->ptrPrev = newNode;
        }
    }

    void deleteByValue(int iVal) {
        Node* crrNode = SearchNodeByValue(iVal);

        if (crrNode!=nullptr) {
            if (crrNode->ptrPrev){
                crrNode->ptrPrev->ptrNext = crrNode->ptrNext;
            } 
            else{
                ptrFront = crrNode->ptrNext;
            }

            if(crrNode->ptrNext){
                crrNode->ptrNext->ptrPrev = crrNode->ptrPrev;
            } 
            else{
                ptrBack = crrNode->ptrPrev;
            }

            delete crrNode;
        }
    }

    void displayList() {
        Node* crrNode = ptrFront;

        cout << "List: ";
        while(crrNode!=nullptr) {
            cout << crrNode->iVal << " ";

            crrNode = crrNode->ptrNext;
        }
        cout << endl;
    }

    Node* getPtrFront(){
        return ptrFront;
    }
};


void swap(int &a, int &b){

    int c = a;

    a = b;

    b = c;

}

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

void measureAndSort(void (*sortFunction)(List&), const string& sortName, List& list, const std::vector<int>& v) {

    high_resolution_clock::time_point start = high_resolution_clock::now();

    sortFunction(list);

    high_resolution_clock::time_point stop = high_resolution_clock::now();

    nanoseconds duration = duration_cast<nanoseconds>(stop - start);

    cout << sortName << " tiempo: " << duration.count() << " nanosegundos" << endl;

    list.displayList();

    list.clear();

    for (int x : v) {
        list.insertBack(x);
    }

}

void prepareList(List& list, const std::vector<int>& v) {
    for (int x : v) {

        list.insertBack(x);

    }

    cout << "Lista original:" << endl;

    list.displayList();
}

void resetList(List& list, const std::vector<int>& v) {

    list.clear();

    prepareList(list, v);

}

int main() {
    List list;
    std::vector<int> v = {20, 10, 15, 25, 30};

    prepareList(list, v);
    measureAndSort(SelectionSort, "SelectionSort", list, v);
    cout << "-----------------------" << endl << endl;

    resetList(list, v);
    measureAndSort(OptimizedSelectionSort, "OptimizedSelectionSort", list, v);
    cout << "-----------------------" << endl << endl;

    resetList(list, v);
    measureAndSort(BubbleSort, "BubbleSort", list, v);
    cout << "-----------------------" << endl << endl;

    resetList(list, v);
    measureAndSort(OptimizedBubbleSort, "OptimizedBubbleSort", list, v);
    cout << "-----------------------" << endl << endl;

    return 0;
}

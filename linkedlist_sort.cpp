#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::string;

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

    void clear(){
        if(empty()) return;

        Node* crrNode = ptrFront;

        while(crrNode != nullptr){
            Node* aux = crrNode->ptrNext;

            delete crrNode;

            crrNode = aux;
        }

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


int main() {
    List list;

    std::vector<int> v({20, 10, 15, 25, 30});

    for(int x: v){
        cout << x << endl;
        list.insertBack(x);
    }

    list.displayList();
    SelectionSort(list);
    list.displayList();

    list.deleteByValue(30);
    list.displayList();
    list.deleteByValue(20);
    list.displayList();
    list.deleteByValue(15);
    list.displayList();
    list.deleteByValue(10);
    list.displayList();
    list.deleteByValue(25);
    list.displayList();


    for(int x: v){
        cout << x << endl;
        list.insertBack(x);
    }

    list.displayList();
    BubbleSort(list);
    list.displayList();

    list.insertAfter(30, 50);
    list.displayList();
    list.insertBefore(10, 5);
    list.displayList();
    list.insertBefore(15, 30);
    list.displayList();

    SelectionSort(list);
    list.displayList();

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

#include "Linked_list.h"

#include "SortBubble.h"
#include "SortSelection.h"
#include "SortInsertion.h"
#include "SortShell.h"

#include "Measure.h"
#include "GenerateExample.h"

#include "BinarySearchTree.h"

using std::cout;
using std::cin;
using std::endl;

void sortAlgorithmsTest(int numTests=10, int n=1e4){
    List<int> list;

    std::vector<int> deltaTime(8);
    std::vector<std::string> label = {"SelectionSort", "OptimizedSelectionSort", 
    "BubbleSort", "OptimizedBubbleSort", "InsertionSort", "OptimizedInsertionSort", "ShellSort", "OptimizedShellSort"};

    for(int i=1; i<=numTests; i++){
        std::vector<int> v = GenerateList(n);

        list.resetList(v);
        deltaTime[0] += measureAndSort(SelectionSort, list);
        
        list.resetList(v);
        deltaTime[1] += measureAndSort(OptimizedSelectionSort, list);
        
        list.resetList(v);
        deltaTime[2] += measureAndSort(BubbleSort, list);
        
        list.resetList(v);
        deltaTime[3] += measureAndSort(OptimizedBubbleSort, list);

        list.resetList(v);
        deltaTime[4] += measureAndSort(InsertionSort, list);
        
        list.resetList(v);
        deltaTime[5] += measureAndSort(OptimizedInsertionSort, list);

        list.resetList(v);
        deltaTime[6] += measureAndSort(ShellSort, list);
        
        list.resetList(v);
        deltaTime[7] += measureAndSort(OptimizedShellSort, list);
    }

    for(int i=0; i<8; i++){
        cout << label[i] << ": " << deltaTime[i] << " ms." << endl;
    }

    cout << "sortAlgorithmsTest OK" << endl;
}

void BstTest(){
    bst::BinarySearchTree<int> mytree;

    mytree.insert(10);
    mytree.insert(5);
    mytree.insert(15);
    mytree.insert(4);
    mytree.insert(7);
    mytree.insert(6);
    mytree.insert(9);

    cout << "Tree Height: " << mytree.height() << endl;

    mytree.traversePreOrder();
    mytree.traverseInOrder();
    mytree.traversePostOrder();
    mytree.bfsTraversal();

    cout << (mytree.searchNodeBFS(5)!=nullptr) << endl;

    mytree.deleteNode(5); cout << "deleteNode" << endl;
    
    cout << (mytree.searchNodeBFS(5)!=nullptr) << endl;

    mytree.traversePreOrder();
    mytree.traverseInOrder();
    mytree.traversePostOrder();
    mytree.bfsTraversal();

    cout << "BstTest OK" << endl;
}

int main(){

    // sortAlgorithmsTest();

    BstTest();

    return 0;
}
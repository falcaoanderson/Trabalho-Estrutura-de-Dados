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
#include "RandomGenerator.h"

#include "BinarySearchTree.h"

using std::cout;
using std::cin;
using std::endl;

void sortAlgorithmsTest(int numTests, int sizeList){
    List<int> list;
    RandomGenerator myrng(13, 1, 100);

    std::vector<int> deltaTime(8);
    std::vector<std::string> label = {"SelectionSort", "OptimizedSelectionSort", 
    "BubbleSort", "OptimizedBubbleSort", "InsertionSort", "OptimizedInsertionSort", "ShellSort", "OptimizedShellSort"};

    for(int i=1; i<=numTests; i++){
        std::vector<int> v = myrng.GenerateList(sizeList);

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

void BstTest(int n){
    bst::BinarySearchTree<int> mytree;

    std::vector<int> v = GenerateList(1e4, 1e9);

    for(int x: v){
        // cout << x << " ";
        mytree.insert(x);
    }
    // cout << endl;

    cout << "Tree Height: " << mytree.height() << endl;
    // mytree.traversePreOrder();
    // mytree.traverseInOrder();
    // mytree.traversePostOrder();
    // mytree.bfsTraversal();

    // cout << (mytree.searchNodeBFS(86)!=nullptr) << endl;
    // mytree.deleteNode(86); cout << "deleteNode" << endl;
    // cout << (mytree.searchNodeBFS(86)!=nullptr) << endl;

    cout << "Tree Height: " << mytree.height() << endl;
    // mytree.traversePreOrder();
    // mytree.traverseInOrder();
    // mytree.traversePostOrder();
    // mytree.bfsTraversal();

    cout << "BstTest OK" << endl;
}

int main(){

    sortAlgorithmsTest(10, 1e4);

    // BstTest(1e1);
    // std::vector<int> v;

    return 0;
}
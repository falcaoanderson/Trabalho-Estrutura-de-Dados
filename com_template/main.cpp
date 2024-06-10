#include <iostream>
#include <string>
#include <vector>

#include "Linked_list.h"

#include "SortBubble.h"
#include "SortSelection.h"
#include "SortInsertion.h"
#include "SortShell.h"

#include "Measure.h"
// #include "GenerateExample.h"
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

void BstTest(int sizeTree){
    bst::BinarySearchTree<int> mytree;
    RandomGenerator myrng(13, 1, 1e9);
    std::chrono::high_resolution_clock::time_point start, stop; int duration;

    std::vector<int> v = myrng.GenerateList(sizeTree);

    start = std::chrono::high_resolution_clock::now();
    for(int x: v) mytree.insert(x);
    stop = std::chrono::high_resolution_clock::now();
    
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    cout << "Build Tree Time: " << duration << "ms." << endl;
    
    cout << "Tree Height: " << mytree.height() << endl;

    start = std::chrono::high_resolution_clock::now();
    cout << (mytree.searchNode(213123) == nullptr) << endl;
    stop = std::chrono::high_resolution_clock::now();
    
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    cout << "Build Tree Time: " << duration << "ms." << endl;

    cout << "BstTest OK" << endl;
}

int main(){

    // sortAlgorithmsTest(1, 1e4);

    BstTest(1e4);

    return 0;
}
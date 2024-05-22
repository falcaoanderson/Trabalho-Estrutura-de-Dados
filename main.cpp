#include <iostream>
#include <string>
#include <vector>

#include "Linked_list.h"

#include "SortBubble.h"
#include "SortSelection.h"
#include "SortInsertion.h"
#include "SortShell.h"

#include "utils.h"
#include "Measure.h"
#include "GenerateExample.h"

int main(){
    int numTests = 10, n = 1e4;
    List list;

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

    return 0;
}
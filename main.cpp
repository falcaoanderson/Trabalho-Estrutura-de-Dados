#include <iostream>
#include "Linked_list.h"
#include "SortBubble.h"
#include "SortSelection.h"
#include "utils.h"


int main(){
    int numTests = 100, n = 1e4;
    List list;

    int deltaTime1 = 0;
    int deltaTime2 = 0;
    int deltaTime3 = 0;
    int deltaTime4 = 0;

    for(int i=1; i<=numTests; i++){
        std::vector<int> v = GenerateList(n);

        resetList(list, v);
        deltaTime1 += measureAndSort(SelectionSort, list);
        
        resetList(list, v);
        deltaTime2 += measureAndSort(OptimizedSelectionSort, list);
        
        resetList(list, v);
        deltaTime3 += measureAndSort(BubbleSort, list);
        
        resetList(list, v);
        deltaTime4 += measureAndSort(OptimizedBubbleSort, list);
    }

    cout << "SelectionSort: "          << deltaTime1 << endl;
    cout << "OptimizedSelectionSort: " << deltaTime2 << endl;
    cout << "BubbleSort: "             << deltaTime3 << endl;
    cout << "OptimizedBubbleSort: "    << deltaTime4 << endl;

    return 0;
}
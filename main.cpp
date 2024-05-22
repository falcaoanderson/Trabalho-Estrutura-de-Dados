#include <iostream>

#include "Linked_list.h"
#include "SortBubble.h"
#include "SortSelection.h"
#include "utils.h"
#include "Measure.h"

int main(){
    int numTests = 10, n = 1e4;
    List list;

    int deltaTime1 = 0;
    int deltaTime2 = 0;
    int deltaTime3 = 0;
    int deltaTime4 = 0;

    for(int i=1; i<=numTests; i++){
        std::vector<int> v = GenerateList(n);

        list.resetList(v);
        deltaTime1 += measureAndSort(SelectionSort, list);
        
        list.resetList(v);
        deltaTime2 += measureAndSort(OptimizedSelectionSort, list);
        
        list.resetList(v);
        deltaTime3 += measureAndSort(BubbleSort, list);
        
        list.resetList(v);
        deltaTime4 += measureAndSort(OptimizedBubbleSort, list);
    }

    cout << "SelectionSort: "          << deltaTime1 << endl;
    cout << "OptimizedSelectionSort: " << deltaTime2 << endl;
    cout << "BubbleSort: "             << deltaTime3 << endl;
    cout << "OptimizedBubbleSort: "    << deltaTime4 << endl;

    return 0;
}
#include <iostream>
#include "Linked_list.h"
#include "SortBubble.h"
#include "SortSelection.h"
#include "utils.h"


int main(){
    int numTests = 1;

    while (numTests)
    {
        List list;
        int n = 1e4;

        std::vector < int > v = GenerateList(n);
        
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

        numTests--;
    }

    return 0;
}
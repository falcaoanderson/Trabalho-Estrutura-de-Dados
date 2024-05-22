#ifndef MEASURE_
#define MEASURE_

#include "Linked_list.h"
#include "SortBubble.h"
#include "SortSelection.h"
#include <iostream>


int measureAndSort(void (*sortFunction)(List&), List& list){
    high_resolution_clock::time_point start = high_resolution_clock::now();

    sortFunction(list);

    high_resolution_clock::time_point stop = high_resolution_clock::now();

    int duration = duration_cast<milliseconds>(stop - start).count();

    return duration;
}

void prepareList(List& list, const std::vector<int>& v) {
    for (int x : v) {

        list.insertBack(x);

    }

    // cout << "Lista original:" << endl;

    // list.displayList();
}

void resetList(List& list, const std::vector<int>& v) {

    list.clear();

    prepareList(list, v);

}

#endif
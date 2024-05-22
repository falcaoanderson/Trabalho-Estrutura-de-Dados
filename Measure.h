#ifndef MEASURE_
#define MEASURE_

#include <chrono>

#include "Linked_list.h"
#include "SortBubble.h"
#include "SortSelection.h"

int measureAndSort(void (*sortFunction)(List&), List& list){
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    sortFunction(list);

    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();

    int duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

    return duration;
}

#endif
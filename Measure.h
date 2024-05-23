#ifndef MEASURE_H
#define MEASURE_H

#include <chrono>

#include "Linked_list.h"

int measureAndSort(void (*sortFunction)(List&), List& list);

#endif
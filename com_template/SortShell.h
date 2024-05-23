#ifndef SORT_SHELL
#define SORT_SHELL

#include "Linked_list.h"
#include "SortInsertion.h"

template<typename T>
void ShellSort(List<T> &list){
    int gap = list.size()/2;

    while(gap>1){

        for(int start=0; start<gap; start++){
            InsertionSort(list, gap, start);
        }

        gap /= 2;
    }
    InsertionSort(list);
}

template<typename T>
void OptimizedShellSort(List<T> &list){
    int gap = list.size()/2;

    while(gap>1){

        for(int start=0; start<gap; start++){
            OptimizedInsertionSort(list, gap, start);
        }

        gap /=2;
    }
    OptimizedInsertionSort(list);
}

#endif


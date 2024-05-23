#include "SortShell.h"
#include "Linked_list.h"
#include "SortInsertion.h"

void ShellSort(List &list){
    int gap = list.size()/2;

    while(gap>1){

        for(int start=0; start<gap; start++){
            InsertionSort(list, gap, start);
        }

        gap /= 2;
    }
    InsertionSort(list);
}

void OptimizedShellSort(List &list){
    int gap = list.size()/2;

    while(gap>1){

        for(int start=0; start<gap; start++){
            OptimizedInsertionSort(list, gap, start);
        }

        gap /=2;
    }
    OptimizedInsertionSort(list);
}
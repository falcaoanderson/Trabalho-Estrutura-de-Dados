#ifndef GENERATE_EXAMPLE_H
#define GENERATE_EXAMPLE_H
#include "Linked_list.h"
#include <vector>
#include <random>

std::vector<int> GenerateList(int n) {
    std::vector<int> list;
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(1, 100); 

    for (int i = 0; i < n; ++i) {
        list.push_back(dis(gen));
    }
    return list;
}

#endif // GENERATE_EXAMPLE_H
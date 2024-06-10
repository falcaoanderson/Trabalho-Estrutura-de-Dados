#include "GenerateExample.h"
#include <vector>
#include <random>

std::vector<int> GenerateList(int n, int high) {
    // std::random_device rd;  
    std::mt19937 gen(13); 
    std::uniform_int_distribution<> unifDis(1, high); 

    std::vector<int> temp;
    
    for (int i = 0; i < n; ++i) {
        temp.push_back(unifDis(gen));
    }

    return temp;
}
#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>

class Clock{
private:
    std::chrono::high_resolution_clock::time_point start, stop;
public:
    void tic(){
        start = std::chrono::high_resolution_clock::now();
    }
    int toc(){
        stop = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    }
};

#endif
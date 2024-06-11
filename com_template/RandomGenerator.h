#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <vector>
#include <random>

class RandomGenerator {
private:
    std::mt19937 gen;
    std::uniform_int_distribution<> unifDis;

public:
    RandomGenerator() : gen(0), unifDis(1, 100) {}

    RandomGenerator(int seed, int low, int high) : gen(seed), unifDis(low, high) {}

    std::vector<int> GenerateList(int size) {
        std::vector<int> temp;

        for (int i = 0; i < size; ++i) {
            temp.push_back(unifDis(gen));
        }

        return temp;
    }
};

#endif
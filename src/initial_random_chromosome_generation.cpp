#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>  // For std::mt19937 and std::random_device

#include "random_coord_generation.h"

std::vector<int> initial_random_chromosome(int n) {
    std::vector<int> genes;
    for (int i = 1; i <= n; ++i) {
        genes.push_back(i);
    }

    std::random_device rd;
    std::mt19937 generator(rd());  // Use Mersenne Twister random number generator
    std::shuffle(genes.begin(), genes.end(), generator);

    return genes;
}

int main() {
    int n = 6; 

    std::vector<int> chromosome = initial_random_chromosome(n - 1);

    std::cout << "Randomly gen chromosome: { ";
    for (int genes : chromosome) {
        std::cout << genes << " ";
    }
    std::cout << "}" << std::endl;

    create_random_coordinates(n);

    return 0;
}

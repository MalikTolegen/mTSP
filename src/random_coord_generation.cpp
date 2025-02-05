#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <random>  // For std::mt19937 and std::random_device

#include "random_coord_generation.h"

double euclidean(const std::vector<double>& p1, const std::vector<double>& p2) {
    return std::sqrt(std::pow(p1[0] - p2[0], 2) + std::pow(p1[1] - p2[1], 2));
}

std::tuple<std::vector<std::vector<double>>, std::vector<double>, std::vector<std::vector<double>>>
create_random_coordinates(int n) {
    std::srand(std::time(0));

    // Generate random coordinates
    std::vector<std::vector<double>> allNodes(n + 1, std::vector<double>(2));
    for (int i = 0; i < n + 1; i++) {
        allNodes[i][0] = static_cast<double>(std::rand()) / RAND_MAX;
        allNodes[i][1] = static_cast<double>(std::rand()) / RAND_MAX;
    }

    // Create distance matrix
    std::vector<std::vector<double>> T(n, std::vector<double>(n, 0.0));

    std::vector<double> depot = allNodes[0];
    std::vector<std::vector<double>> Nodes(allNodes.begin() + 1, allNodes.begin() + n + 1);

    for (int i = 0; i < n; i++) {
        T[0][i] = euclidean(depot, Nodes[i]);
        T[i][0] = T[0][i];

        for (int j = 0; j < n; j++) {
            if (i != j) {
                T[i][j] = euclidean(Nodes[i], Nodes[j]);
            }
        }
    }

    // Return the tuple containing the distance matrix, depot, and nodes
    return {T, depot, Nodes};
}


#include <iostream>
#include "random_coord_generation.h"

double euclidean(const std::vector<double>& p1, const std::vector<double>& p2) {
    return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
}

std::tuple<std::vector<std::vector<double> >, std::vector<double>, std::vector<std::vector<double> > > create_random_coordinates(int n) {
    srand(time(0));

    std::vector<std::vector<double> > allNodes(n + 1, std::vector<double>(2));
    for (int i = 0; i < n + 1; i++) {
        allNodes[i][0] = (double)rand() / RAND_MAX;
        allNodes[i][1] = (double)rand() / RAND_MAX;
    }
    
    std::vector<std::vector<double> > T(n, std::vector<double>(n, 0.0));

    std::vector<double> depot = allNodes[0];
    std::vector<std::vector<double> > Nodes(allNodes.begin() + 1, allNodes.begin() + n);

    for (int i = 0; i < n - 1; i++) {
        T[0][i + 1] = euclidean(depot, Nodes[i]);
        T[i + 1][0] = T[0][i + 1];

        for (int j = 0; j < n - 1; j++) {
            T[i + 1][j + 1] = euclidean(Nodes[i], Nodes[j]);
            T[j + 1][i + 1] = T[i + 1][j + 1];
        }
    }

    return {T};
}

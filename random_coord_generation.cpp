#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <algorithm>

using namespace std;

double euclidean(const vector<double>& p1, const vector<double>& p2) {
    return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
}

tuple<vector<vector<double>>, vector<double>, vector<vector<double>>> create_random_coordinates(int n) {
    srand(time(0));

    vector<vector<double>> allNodes(n + 1, vector<double>(2));
    for (int i = 0; i < n + 1; i++) {
        allNodes[i][0] = (double)rand() / RAND_MAX;
        allNodes[i][1] = (double)rand() / RAND_MAX;
    }
    
    vector<vector<double>> T(n, vector<double>(n, 0.0));

    vector<double> depot = allNodes[0];
    vector<vector<double>> Nodes(allNodes.begin() + 1, allNodes.begin() + n);

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

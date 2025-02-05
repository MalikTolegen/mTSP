#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>  // For std::max

std::vector<std::vector<int>> split(const std::vector<std::vector<double>>& T, const std::vector<int>& chromosome, int K) {
    int n = chromosome.size();
    std::vector<std::vector<double>> V(n + 1, std::vector<double>(K + 1, std::numeric_limits<double>::max()));
    std::vector<std::vector<int>> P(n + 1, std::vector<int>(K + 1, -1));

    V[0][0] = 0;

    for (int k = 1; k <= K; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                double cost = 0;
                int prevCity = 0;

                for (int x = j; x < i; ++x) {
                    cost += (T[prevCity][chromosome[x]] + (x > j ? T[chromosome[x - 1]][chromosome[x]] : 0));
                    prevCity = chromosome[x];
                }
                cost += T[prevCity][0];

                double maxTour = std::max(V[j][k - 1], cost);
                if (maxTour < V[i][k]) {
                    V[i][k] = maxTour;
                    P[i][k] = j;
                }
            }
        }
    }

    std::vector<std::vector<int>> bestTours(K);
    int i = n, k = K;
    while (k > 0) {
        int start = P[i][k];
        for (int j = start; j < i; ++j) {
            bestTours[k - 1].push_back(chromosome[j]);
        }
        i = start;
        k--;
    }

    return bestTours;
}

double calculate_tour_distance(const std::vector<std::vector<double>>& T, const std::vector<int>& tour) {
    double totalDistance = 0;
    int prevCity = 0;

    for (int city : tour) {
        totalDistance += T[prevCity][city];
        prevCity = city;
    }

    totalDistance += T[prevCity][0];
    return totalDistance;
}

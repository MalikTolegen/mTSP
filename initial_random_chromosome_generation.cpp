#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;


vector<int> initial_random_chromosome(int n) {
    vector<int> genes;
    for (int i = 1; i <= n; ++i) {
        genes.push_back(i);
    }

    random_shuffle(genes.begin(), genes.end());

    return genes;
}

int main() {
    int n = 6; 

    vector<int> chromosome = initial_random_chromosome(n - 1);

    cout << "Randomly gen chromosome: { ";
    for (int genes : chromosome) {
        cout << genes << " ";
    }
    cout << "}" << endl;

    return 0;
}

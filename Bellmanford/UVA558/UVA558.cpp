
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Road {
    int start, end, cost;
};

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int nodes, edgesCount;
        cin >> nodes >> edgesCount;

        vector<Road> roads(edgesCount);
        for (int i = 0; i < edgesCount; ++i) {
            cin >> roads[i].start >> roads[i].end >> roads[i].cost;
        }

        vector<long long> minDist(nodes, LLONG_MAX);
        minDist[0] = 0;

        for (int i = 0; i < nodes - 1; ++i) {
            for (const Road& r : roads) {
                if (minDist[r.start] != LLONG_MAX && minDist[r.start] + r.cost < minDist[r.end]) {
                    minDist[r.end] = minDist[r.start] + r.cost;
                }
            }
        }

        bool negativeCycle = false;
        for (const Road& r : roads) {
            if (minDist[r.start] != LLONG_MAX && minDist[r.start] + r.cost < minDist[r.end]) {
                negativeCycle = true;
                break;
            }
        }

        cout << (negativeCycle ? "possible" : "not possible") << "\n";
    }

    return 0;
}

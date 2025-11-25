#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Wormhole {
    int from, to, timeShift;
};

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n, m;
        cin >> n >> m;

        vector<Wormhole> wormholes(m);
        for (int i = 0; i < m; ++i) {
            cin >> wormholes[i].from >> wormholes[i].to >> wormholes[i].timeShift;
        }

        vector<long long> earliestTime(n, LLONG_MAX);
        earliestTime[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int u = wormholes[j].from;
                int v = wormholes[j].to;
                int w = wormholes[j].timeShift;

                if (earliestTime[u] != LLONG_MAX && earliestTime[u] + w < earliestTime[v]) {
                    earliestTime[v] = earliestTime[u] + w;
                }
            }
        }

        bool negativeCycle = false;
        for (int j = 0; j < m; ++j) {
            int u = wormholes[j].from;
            int v = wormholes[j].to;
            int w = wormholes[j].timeShift;

            if (earliestTime[u] != LLONG_MAX && earliestTime[u] + w < earliestTime[v]) {
                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle) cout << "possible\n";
        else cout << "not possible\n";
    }

    return 0;
}


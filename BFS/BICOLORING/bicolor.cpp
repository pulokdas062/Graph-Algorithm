#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int nodes;
        cin >> nodes;
        if (nodes == 0) break;

        int edges;
        cin >> edges;

        vector<vector<int>> adj(nodes);

        for (int i = 0; i < edges; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> mark(nodes, -1);
        queue<int> bfs;

        mark[0] = 0;
        bfs.push(0);

        bool ok = true;

        while (!bfs.empty() && ok) {
            int cur = bfs.front();
            bfs.pop();

            for (int nxt : adj[cur]) {
                if (mark[nxt] == -1) {
                    mark[nxt] = 1 - mark[cur];
                    bfs.push(nxt);
                } else if (mark[nxt] == mark[cur]) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok)
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}


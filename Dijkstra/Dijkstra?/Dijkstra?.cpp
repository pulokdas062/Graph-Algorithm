#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll,int>;

const ll MAX_DIST = 1e18;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

```
int nodes, edges;
cin >> nodes >> edges;

vector<vector<pair<int,int>>> adj(nodes + 1);
for(int i=0;i<edges;i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v,w);
    adj[v].emplace_back(u,w);
}

vector<ll> minCost(nodes+1, MAX_DIST);
vector<int> prev(nodes+1, -1);
vector<bool> done(nodes+1, false);

priority_queue<pii, vector<pii>, greater<pii>> heap;
minCost[1] = 0;
heap.push({0,1});

while(!heap.empty()){
    auto [curCost, curr] = heap.top(); heap.pop();
    if(done[curr]) continue;
    done[curr] = true;

    if(curr == nodes) break;

    for(auto &[next, wt] : adj[curr]){
        if(!done[next] && curCost + wt < minCost[next]){
            minCost[next] = curCost + wt;
            prev[next] = curr;
            heap.push({minCost[next], next});
        }
    }
}

if(minCost[nodes] == MAX_DIST){
    cout << -1 << "\n";
} else {
    vector<int> route;
    for(int x = nodes; x != -1; x = prev[x]) route.push_back(x);
    reverse(route.begin(), route.end());
    for(int i=0;i<route.size();i++){
        cout << route[i] << (i+1<route.size() ? ' ' : '\n');
    }
}
```

}


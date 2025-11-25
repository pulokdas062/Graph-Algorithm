#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct E { int u,v; int w; };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC; if(!(cin>>TC)) return 0;
    for(int tc=1; tc<=TC; ++tc){
        int n,m; cin>>n>>m;
        vector<E> edges; edges.reserve(m);
        vector<vector<int>> rev(n);
        for(int i=0;i<m;++i){
            int a,b,t; cin>>a>>b>>t;
            edges.push_back({a,b,t});
            rev[b].push_back(a);
        }
        const ll INF = (1LL<<60);
        vector<ll> d(n,0);
        for(int iter=0; iter<n-1; ++iter){
            bool any=false;
            for(auto &e: edges){
                if(d[e.u] + e.w < d[e.v]){
                    d[e.v] = d[e.u] + e.w;
                    any = true;
                }
            }
            if(!any) break;
        }
        vector<int> start_nodes;
        vector<char> mark(n,0);
        queue<int> q;
        for(auto &e: edges){
            if(d[e.u] + e.w < d[e.v]){
                if(!mark[e.v]){ mark[e.v]=1; q.push(e.v); }
            }
        }
        while(!q.empty()){
            int x=q.front(); q.pop();
            for(int y: rev[x]){
                if(!mark[y]){ mark[y]=1; q.push(y); }
            }
        }
        for(int i=0;i<n;++i) if(mark[i]) start_nodes.push_back(i);
        cout<<"Case "<<tc<<":";
        if(start_nodes.empty()){
            cout<<" impossible\n";
        } else {
            for(int v: start_nodes) cout<<" "<<v;
            cout<<"\n";
        }
    }
    return 0;
}


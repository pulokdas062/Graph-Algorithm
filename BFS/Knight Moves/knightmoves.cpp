#include <bits/stdc++.h>
using namespace std;

struct Node {
    int r, c, dist;
};

static const int kx[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
static const int ky[8] = { 1, -1, 2, -2,  2, -2,  1, -1 };

bool insideBoard(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int knightDistance(const string &s, const string &t) {
    if (s == t) return 0;

    bool vis[8][8] = {};
    int sr = s[0] - 'a', sc = s[1] - '1';
    int tr = t[0] - 'a', tc = t[1] - '1';

    queue<Node> q;
    q.push({sr, sc, 0});
    vis[sr][sc] = true;

    while (!q.empty()) {
        Node u = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = u.r + kx[i];
            int nc = u.c + ky[i];

            if (!insideBoard(nr, nc) || vis[nr][nc]) continue;

            if (nr == tr && nc == tc)
                return u.dist + 1;

            vis[nr][nc] = true;
            q.push({nr, nc, u.dist + 1});
        }
    }
    return -1; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string fromSq, toSq;
    while (cin >> fromSq >> toSq) {
        int res = knightDistance(fromSq, toSq);
        cout << "To get from " << fromSq
             << " to " << toSq
             << " takes " << res
             << " knight moves.\n";
    }
    return 0;
}


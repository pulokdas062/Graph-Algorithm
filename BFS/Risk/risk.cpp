
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Node {
    int r, c, steps;
};

int mx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int my[] = {1, -1, 2, -2, 2, -2, 1, -1};

bool inside(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int knightMoves(const string& s, const string& t) {
    if (s == t) return 0;

    bool used[8][8];
    memset(used, false, sizeof(used));

    int sr = s[0] - 'a';
    int sc = s[1] - '1';
    int tr = t[0] - 'a';
    int tc = t[1] - '1';

    queue<Node> q;
    q.push({sr, sc, 0});
    used[sr][sc] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = cur.r + mx[i];
            int nc = cur.c + my[i];

            if (inside(nr, nc) && !used[nr][nc]) {
                if (nr == tr && nc == tc) {
                    return cur.steps + 1;
                }
                used[nr][nc] = true;
                q.push({nr, nc, cur.steps + 1});
            }
        }
    }

    return -1;
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        int ans = knightMoves(a, b);
        cout << "To get from " << a << " to " << b
             << " takes " << ans << " knight moves." << endl;
    }
    return 0;
}

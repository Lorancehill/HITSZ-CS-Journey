#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005, MAXM = 400005;
int n;
long long s[MAXN], t[MAXN];
int head[MAXN], nxt[MAXM], to[MAXM], weight[MAXM];
int toDeg[MAXN], parent[MAXN], parentW[MAXN];
int idx = 0;

void add(int u, int v, int c) {
    parent[v] = u;
    parentW[v] = c;
    to[++idx] = v;
    nxt[idx] = head[u];
    weight[idx] = c;
    head[u] = idx;
}

long long topoSort() {
    long long sum = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (toDeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int u = parent[v];

        if (s[v] != t[v]) {
            long long diff = s[v] - t[v];
            int w = parentW[v];
            long long ops = (abs(diff) + w - 1) / w;
            sum += ops;
            s[v] = t[v];
            s[u] += diff;
        }
        if (u != 0) {
            toDeg[u]--;
            if (toDeg[u] == 0) {
                q.push(u);
            }
        }
    }
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        add(u, v, c);
        toDeg[u]++;
    }
    cout << topoSort() << endl;
    return 0;
}
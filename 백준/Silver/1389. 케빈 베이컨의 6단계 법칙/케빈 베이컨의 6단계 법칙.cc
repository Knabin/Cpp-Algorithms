#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int p1, p2;
        cin >> p1 >> p2;
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);   // 양방향 그래프
    }

    // bfs
    int min = INT_MAX, res = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {
                if (dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }

        int sum = 0;
        for (int j = 1; j <= n; ++j) sum += dist[j];
        if (sum < min) {
            min = sum;
            res = i;
        }
    }

    cout << res;

    return 0;
}
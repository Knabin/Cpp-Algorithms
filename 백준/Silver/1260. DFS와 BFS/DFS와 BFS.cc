#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int p1, p2;
        cin >> p1 >> p2;
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);   // 양방향 그래프
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    // dfs
    vector<bool> visited(n + 1, false);
    stack<int> s;
    s.push(v);

    while (!s.empty()) {
        int cur = s.top();
        s.pop();

        if (visited[cur]) 
            continue;
        
        visited[cur] = true;
        cout << cur << ' ';
        
        for (int i = graph[cur].size() - 1; i >= 0; --i) {
            int next = graph[cur][i];
            if (!visited[next]) {
                s.push(next);
            }
        }   
    }

    // bfs
    cout << '\n';
    fill(visited.begin(), visited.end(), false);
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        
        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return 0;
}
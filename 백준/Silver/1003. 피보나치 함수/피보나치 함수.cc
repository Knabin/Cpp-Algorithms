#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    vector<int> ns(t, 0);
    int max_n = INT_MIN;    // 최대값
    for (int i = 0; i < t; i++) {
        cin >> ns[i];
        max_n = max(max_n, ns[i]);
    }

    vector<pair<int, int>> dp;
    dp.emplace_back(make_pair(1, 0));   // 0의 0의 개수, 1의 개수
    dp.emplace_back(make_pair(0, 1));   // 1의 0의 개수, 1의 개수

    for (int i = 2; i <= max_n; i++) {
        int zero = dp[i - 1].first + dp[i - 2].first;
        int one = dp[i - 1].second + dp[i - 2].second;
        dp.emplace_back(make_pair(zero, one));
    }

    for (auto n : ns) {
        cout << dp[n].first << " " << dp[n].second << "\n";
    }

    return 0;
}
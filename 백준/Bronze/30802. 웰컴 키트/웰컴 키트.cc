#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t, p;
    cin >> n;

    vector<int> vt(6, 0);
    for (int i = 0; i < vt.size(); ++i)
        cin >> vt[i];

    cin >> t >> p;

    int total = 0, ptotal = 0;
    for (const auto& sz : vt) {
        if (sz == 0)
            continue;

        total += sz / t;
        if (sz % t != 0)
            total += 1;
    }

    ptotal = n / p;

    cout << total << '\n' << ptotal << ' ' << n % p;

    return 0;
}
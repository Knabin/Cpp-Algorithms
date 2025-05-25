#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> arr(3);
    for (int i = 0; i < arr.size(); ++i)
        cin >> arr[i];

    int sum = stoi(arr[0]) + stoi(arr[1]) - stoi(arr[2]);
    string tmp = arr[0] + arr[1];
    int sum2 = stoi(tmp) - stoi(arr[2]);

    cout << sum << '\n' << sum2 << '\n';

    return 0;
}
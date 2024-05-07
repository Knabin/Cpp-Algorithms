#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    cin >> n;
    vector<int> arr(n);

    // 아직 아무 의견이 없다면 문제의 난이도는 0으로 결정
    if (n == 0) {
        cout << 0;
        return 0;
    }

    // 의견이 하나 이상 있다면, 문제의 난이도는 모든 사람의 난이도 의견의 30% 절사평균으로 결정
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 절사평균 계산 (위에서 15%, 아래에서 15%를 제외하고 평균을 계산)
    int cnt = round(n * 0.15);
    sort(arr.begin(), arr.end());

    double sum = 0;
    for (int i = cnt; i < n - cnt; ++i) {
        sum += arr[i];
    }

    cout << round(sum / (n - 2 * cnt)) << endl;

    return 0;
}
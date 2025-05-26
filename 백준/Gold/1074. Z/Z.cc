#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, r, c;
    cin >> N >> r >> c;

    int len = 1 << N;   // 2^N

    function<int(int, int, int)> solve = [&](int r, int c, int len) -> int {
        if (len == 1) 
            return 0;

        int half = len / 2;
        int quad = (r >= half ? 2 : 0) + (c >= half ? 1 : 0);   // 몇 사분면인지
        int offset = quad * (half * half);                  // 각 사분면의 시작값

        return offset + solve(r % half, c % half, half);    // 사분면 속 사분면 계산
    };

    int result = solve(r, c, len);
    cout << result << '\n';

    return 0;
}
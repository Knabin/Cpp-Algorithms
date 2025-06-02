#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int res = 0;
    string num = "";
    bool bNegative = false;

    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size() || s[i] == '+' || s[i] == '-') {
            int n = stoi(num);
            if (bNegative) {
                res -= n;
            } else {
                res += n;
            }

            if (i < s.size() && s[i] == '-') {
                bNegative = true;
            }

            num.clear();
        } else {
            num += s[i];
        }
    }

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<string> arr(3);
    for (int i = 0; i < arr.size(); ++i)
        cin >> arr[i];
    int idx = -1, num = -1;
    for (int i = 0; i < 3; i++) {
        if (all_of(arr[i].begin(), arr[i].end(), ::isdigit)) {
            idx = i;
            num = stoi(arr[i]);
            break;
        }
    }

    int start = num - idx;
    int next = start + 3;
    if (next % 15 == 0) 
        cout << "FizzBuzz\n";
    else if (next % 3 == 0) 
        cout << "Fizz\n";
    else if (next % 5 == 0) 
        cout << "Buzz\n";
    else 
        cout << next << '\n';

    return 0;
}
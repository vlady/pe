#include <iostream>
#include <set>
using namespace std;
int v[1000001];
int main() {
    int offset[] = {4, 4, 6, 6, 4, 4, 6, 4, 4, 12, 4, 4, 10, 4};
    int looser = 1, pos = 0;
    int n = 1000000;
    int total = n;
    while (looser <= n) {
        total--;
        looser += offset[pos];
        ++pos; if (pos == 14) pos = 9;
    }
    cout << total << '\n';
    /* Grundy to figure out the pattern.
    v[0] = 0;
    v[1] = 0;
    int total = 0;
    int lst = 0;
    for (int i = 2; i <= 10000; ++i) {
        set<int> s;
        for (int j = 0; i - j - 2 >= 0; ++j) {
            s.insert(v[j] ^ v[i-j-2]);
        }
        v[i] = 0;
        while (s.find(v[i]) != s.end()) ++v[i];
        total += (v[i] > 0);
        if (v[i] == 0) {
            cout << i - lst << ' ';
            lst = i;
        }
    }
    cout << total << '\n';
    */

    return 0;        
}

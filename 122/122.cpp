#include <iostream>

using namespace std;
int best[201];

int v[100];
void back() {
    for (int i = v[0]; i >= 1; --i) {
        int nxt = v[v[0]] + v[i];
        if (best[nxt] >= v[0] && nxt <= 200) {
            best[nxt] = v[0];
            v[++v[0]] = nxt;
            back();
            --v[0];
        }
    }    
}
int main() {
    for (int i = 1; i <= 200; ++i)
        best[i] = i - 1;
    v[++v[0]] = 1;
    back();
    int sum = 0;
    for (int i = 1; i <= 200; ++i)
        sum += best[i];
    cout << sum << '\n';
    return 0;    
}

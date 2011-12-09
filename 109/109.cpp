#include <iostream>

using namespace std;
int s[1000];
int d[1000];
int main() {
    for (int i = 1; i <= 20; ++i) s[++s[0]] = 2 * i;
    s[++s[0]] = 50;
    int pp = s[0];
    for (int t = 1; t <= 3; t+=2)
    for (int i = 1; i <= 20; ++i) s[++s[0]] = i * t;
    s[++s[0]] = 25;
    int N = 100;
    int total = 0;
    int total2 = 0;
    // chose a double
    for (int i = 1; i <= pp; ++i) {
        if (s[i] < N) ++total;
        total2++;
        for (int j = 1; j <= s[0]; ++j) {
            if (s[i] + s[j] < N) ++total;
            total2++;
            for (int k = j; k <= s[0]; ++k) {
                if (s[i] + s[j] + s[k] < N) ++total;
                total2++;
            }
        }
    }
    cout << total << '\n';
    cout << total2 << '\n';
    return 0;
}

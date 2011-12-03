#include <iostream>

using namespace std;

typedef long long LL;
int sol[1000000];
int main() {
    // (x+k)^2 - (x)^2 - (x-k)^2
    // x^2 + 2kx + k^2 - x^2 - x^2 - k^2 +2kx
    // 4kx - x^2 with k < x and k >= x/4
    for (LL x = 0; x < 1000000; ++x) {
        for (LL k = x / 4; k < x; k++) {
            LL n = 4 * k * x - x * x;
            if (n > 0 && n < 1000000) sol[n]++;
            if (n >= 1000000) break;
        }
    } 
    LL total = 0;
    for (int i = 0; i < 1000000; ++i)
        total += (sol[i] == 10);
    cout << sol[1155] << '\n';
    cout << total << '\n';
    return 0;
}

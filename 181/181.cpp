#include <iostream>

using namespace std;
typedef long long LL;
LL dp[61][61][61][61];
int was[61][61][61][61];
LL f(int lB, int lW, int b, int w) {
    if (lB < 0 || lW < 0) return 0;
    if (lB == 0 && lW == 0) return 1;
    if (was[lB][lW][b][w])
        return dp[lB][lW][b][w];
    was[lB][lW][b][w] = 1;
    LL total = 0;
    for (int b2 = b; b2 <= lB; ++b2)
        for (int w2 = 0; w2 <= lW; ++w2) {
            if (b2 == b && w2 < w) continue;
            total += f(lB-b2, lW-w2, b2, w2);
        }
    return dp[lB][lW][b][w] = total;
}
int main() {
    cout << f(60, 40, 0, 0) << '\n';
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
double F[10001][101][10][10];
int  was[10001][101][10][10];
int inf = 30;
int has(int n) {
    while (n > 100) {
        if ((n % 1000)%111 == 0) return 1;
        n /= 10;
    }
    return 0;
}
double f(int i, int j, int d1, int d2) {
    if (j > inf) return 0.0;
    if (i < 2) cout << "asdasdasd";
    if (was[i][j][d1][d2]) return F[i][j][d1][d2];
    was[i][j][d1][d2] = 1;
    // base case
    if (i == 2) {
        if (d1 == 0) return F[i][j][d1][d2] = 0.0;
        double X = d1 * 10 + d2;
        double ans = 1.0;
        for (int k = 0; k < j; ++k) ans /= X;
        return F[i][j][d1][d2] = ans;
    }
    double P = 1.0;
    for (int k = 0; k < j; ++k) P /= 10.0;
    double sgn = 1.0;
    double sum = 0.0;
    for (int n = 0; n < inf;
        ++n, sgn *= -1.0,
        P = P * (double(j + n - 1) * double(d2) / (double(n) * 10.0)) ) {
        double sum2 = 0.0;
        for (int d3 = 0; d3 < 10; ++d3) {
            if (d1 == d2 && d3 == d1) continue;
            sum2 += f(i-1, j + n, d3, d1);
        }
        sum += sgn * P * sum2;
    }
    return F[i][j][d1][d2] = sum;
}
int main() {
    double ret = 0.0;
    for (int d = 1; d <= 9; ++d) ret += 1.0 / double(d);
    for (int i = 2; i <= 10000; ++i)
        for (int d1 = 0; d1 <= 9; ++d1)
            for (int d2 = 0; d2 <= 9; ++d2) {
                ret += f(i, 1, d1, d2);
                printf("%.010lf\n", ret);
            }
    double v = 0.0;
    for (int i = 1; i <= 99999999; ++i) if (!has(i))
        v = (v + 1.0 / double(i));
    printf("%.010lf\n", v);
    return 0;
}

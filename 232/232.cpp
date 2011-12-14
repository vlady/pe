#include <iostream>
#include <cstdio>

using namespace std;
int was[2][101][101];
double dp[2][101][101];

double f(int who, int x, int y) {
    if (x >= 100) {
        if (who == 0) return 1.0;
        return 0.0;
    }
    if (y >= 100) {
        if (who == 0) return 0.0;
        return 1.0;
    }
    if (was[who][x][y]) return dp[who][x][y];
    was[who][x][y] = 1;
    if (who == 0) {
        return dp[who][x][y] = 0.5 * (2.0 - f(1, x, y) - f(1, x + 1, y));
    }
    double p = 0.5;
    double best = 0.0;
    for (int t = 1; t <= 10; ++t, p *= 0.5) {
        double X = p * (1.0 - f(0, x, y + (1<<(t-1)))) + (1.0 - p) * (0.5*f(1, x + 1, y));
        double Y = (1.0 - p) * 0.5;
        X /= (1 - Y);
        if (X > best) best = X;
    }
    return dp[who][x][y] = best;
}
int main() {
    printf("%.08lf\n", 1.0 - f(0, 0, 0));
    return 0;
}

#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;
double P[10110];
int was[10100][2];
double dp[10100][2];
double T(int n, double p, bool k) {
    if (n == 1) {
        if (k == true) return 0;
        return 1.0;
    } 
    if (was[n][k]) return dp[n][k];
    was[n][k] = 1;
    double best = 1000000000.0;
    // test all flock. 1 + P * T(n, p, k)
    if (k == false) {
        double aux = 1.0 + (1.0 - P[n]) * T(n, p, true); 
        if (aux < best) best = aux;
        // divide the flock in two
        for (int f1 = 1; f1 < n; ++f1) {
            aux = T(f1, p, false) + T(n - f1, p, false);
            if (aux < best) best = aux;
        }
    } else {
        // I know at least one is sick.
        // divide the flock in two

        for (int f1 = 1; f1 < n; ++f1) {
            // test f1 flock
            // cel putin una sick
            double p2 = 0.0;
            p2 = (1.0 - P[f1]);
            p2 /= (1.0  - P[n]);
            double P1 = p2;
            double aux = 1.0 + P1 * (T(f1, p, true) + T(n-f1,p,false))
                + (1.0 - P1) * T(n-f1,p,true);
            if (aux < best) best = aux;
        }
    }
    dp[n][k] = best;
    return best;
}

int main() {
    double total = 0;
    for (double p = 0.01; p <= 0.501; p += 0.01) {
        cout << p << '\n';
        P[0] = 1.0;
        for (int i = 1; i <= 10000; ++i) P[i] = P[i-1] * (1.0 - p);
        memset(was,0,sizeof(was));
        total += T(10000, p, false);
    }
    printf("%.06lf\n", total);
    return 0;
}

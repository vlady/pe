#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
// Formula E(d) = 1.0 + 8/36 * E(d-1) + 8/36 * E(d+1) + 18/36 * E(d) + 1/36 * E(d-2) + 1/36 * E(d+2)
//                      
int was[101][50001];;
double dp[101][50001];
double E(int d, int s) {
    d = d % 100;
    if (d == 0) return 0.0;
    if (s > 40000) return 0.0;
    if (was[d][s]) return dp[d][s];
    dp[d][s] = 2.0 * (1.0 + 8.0/36.0 * E(d+99, s + 1) + 8.0/36.0 *E(d+1, s + 1) + 1.0/36.0*E(d+98, s + 1) + 1.0/36.0 * E(d+2, s+ 1));
    was[d][s] = 1;
    return dp[d][s];
}
int main() {
    printf("%0.06lf\n", E(50, 0));
    return 0;    
}

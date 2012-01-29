#include <iostream>

using namespace std;
typedef unsigned long long LL;
int p[20000001];
inline LL path(LL n) {
    LL total = 0;
    while (p[n]) {
        total += p[n];
        n /= p[n];
    }
    if (n > 1)
      total += n;
    return total;
}
int main() {
    for (LL i = 2; i * i <= 20000000LL; ++i) if (p[i] == 0)
        for (LL j = i * i; j <= 20000000LL; j += i) p[j] = i;
    LL sum = 0;
    LL N = 20000000LL,
       K = 15000000LL;
//       N = 10, K = 3;
    cout << path(120) << '\n';
    for (LL i = K + 1; i <= N; ++i) sum += path(i);
    for (LL i = 1; i <= N - K; ++i) sum -= path(i);
    cout << sum << '\n';
    return 0;
}

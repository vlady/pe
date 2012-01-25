#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

typedef long long LL;

void gcd(LL &x, LL &y, LL a, LL b) {
    if (b == 0) {x = 1; y = 0; return;}
    gcd(x, y, b, a % b);
    LL aux = x;
    x = y;
    y = aux - y * (a / b);
}
LL inv(LL x, LL P) {
    LL ret1, ret2;
    gcd(ret1, ret2, x, P);
    return (ret1 + P) % P;
}
map<LL, LL> F[5001];

LL fac(LL n, LL P) {
    if (n == 0) return 1;
    if (F[P][n]) return F[P][n];
    return F[P][n] = (fac(n-1, P) * n) % P;
}
LL lucas(LL n, LL k, LL P) {
    if (k == 0) return 1;
    if (n == 0) return 0;
    if (k > n) return 0;
    if (n < P && k < P) {
        return (fac(n, P) * inv(fac(n-k, P), P) * inv(fac(k, P), P)) % P;
    }
    LL ans = 1;
    while (n) {
        ans *= lucas(n % P, k % P, P);
        ans %= P;
        n /= P; k /= P;
    }
    return ans;
}
bool ciur[5001];
void prepare_ciur() {
    ciur[0] = ciur[1] = true;
    for (LL i = 2; i * i <= 5000; ++i) if (!ciur[i])
        for (LL j = i * i; j <= 5000; j += i) ciur[j] = true;
}
LL N = 1000000000000000000LL;
LL K = 1000000000LL;
LL CACHE[5001];
LL PRIMES[5001];
int main() {
    prepare_ciur();
    for (LL p = 1000; p <= 5000; ++p) if (!ciur[p]) {
        CACHE[p] = lucas(N, K, p);
        PRIMES[++PRIMES[0]] = p;
    }
    LL total = 0;
    cerr << N << ' ' << K << '\n';
    for (int i = 1; i <= PRIMES[0]; ++i)
        for (int j = i + 1; j <= PRIMES[0]; ++j)
            for (int k = j + 1; k <= PRIMES[0]; ++k) {
        LL p = PRIMES[i], q = PRIMES[j], r = PRIMES[k];
        LL M1 = CACHE[p];
        LL M2 = CACHE[q];
        LL M3 = CACHE[r];
        // M % p = M1
        // M % q = M2
        // M % q = M3
        LL Y = (inv(p, q) * (q + M2 - M1)) % q;
        LL Z = (inv((p * q) % r, r) * (r + M3 - (Y*p + M1) % r)) % r;
        total += Z * p * q + Y * p + M1;
    }
    cout << total << '\n';
    return 0;
}

#include <iostream>

using namespace std;
typedef long long LL;
int rep(int x) {
    int mod = 1;
    int steps = 1;
    while (mod) {
        mod = (mod * 10) + 1;
        mod %= x;
        ++steps;
    }
    return steps;
}
int prime[1000001];
int main() {
    for (LL i = 2; i*i <= 1000000; i++) if (prime[i] == 0)
        for (LL j = i * i; j <= 1000000; j+=i) prime[j] = 1;
    int sum = 0;
    int n = 25;
    for (int i = 3;;i += 2) {
        if (i % 5 == 0 || prime[i] == 0) continue;
        int x = rep(i);
        if ((i-1)%x == 0) {
            n--; sum += i;
            cout << i << '\n';
            if (n == 0) break;
        }
    } 
    cout << sum << '\n';
    return 0;
}

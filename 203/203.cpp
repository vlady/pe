#include <iostream>
#include <set>

using namespace std;
typedef long long LL;

int main() {
    set<LL> S;
    LL sum = 0;
    for (LL i = 0; i < 51; ++i) {
        LL F = 1, K = 0;
        // n! / (n-k)! * k!
        while (F) {
            bool bad = false;
            for (LL j = 2; j <= 51; ++j) if (F % (j*j) == 0) bad = true;
            if (!bad && S.find(F) == S.end()) S.insert(F), sum += F;
            F *= (i - K); F /= ++K;
        }
    }
    cout << sum << '\n';
    return 0;
}

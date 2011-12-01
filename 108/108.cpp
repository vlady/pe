#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
map<LL, int> S;
int main() {
    LL best = -1;
    LL sofar = 0;
    for (LL sum = 2; sum <= 1000; sum += 1) {
        for (LL x = 1; x < sum; ++x) {
            LL y = sum - x;
            LL P = x * y;
            if (P % (x + y)) continue;
            P /= (x + y);
            if (x <= y) {
                LL t = x * P / __gcd(x, P);
                if (t != y)
                cout << x << ' ' << y << ' ' << P << '\n';
            }
            S[P]++;
            if (S[P] > sofar) {
                cout << "SOFAR: " << sofar << ' ' << P << '\n';;
                sofar = S[P];
            }
            if ((best == -1 || P < best) && S[P] == 1001) {
                best = P;
                cout << best << '\n';
            }
        }
    }    
    for (int i = 1; i <= 10; ++i)
        cout << S[i] << ' ';
    return 0;    
}

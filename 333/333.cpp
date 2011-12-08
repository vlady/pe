#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
map<pair<int, int>, int> P[1000001];
int sol[1000001];
int ciur[1000001];
LL p2[31], p3[31];
using namespace std;
int main() {
    // init
    for (LL i = 2; i * i <= 1000000; ++i) if (ciur[i] == 0)
        for (LL j = i * i; j <= 1000000; j += i) ciur[j] |= 1;
    p2[0] = p3[0] = 1;
    for (int i = 1; i <= 20; ++i) p2[i] = p2[i-1] * 2, p3[i] = p3[i-1] * 3; 
    for (int i2 = 0; i2 <= 20; ++i2) {
        for (int i3 = 0; i3 <= 12; ++i3) {
            if (p2[i2] * p3[i3] >= 1000000) break;
            P[p2[i2] * p3[i3]][make_pair(i2, i3)]++;
            sol[p2[i2]*p3[i3]] += 1;
        }
    }
    LL sum = 0;
    ciur[1] = 1;
    for (int i = 1; i <= 1000000; ++i) {
        if (sol[i] == 1 && ciur[i] == 0) {
//            cout << i << '\n';
            sum += i;
        }
        for (map<pair<int,int>, int>::const_iterator it = P[i].begin();
            it != P[i].end(); ++it) {
            int i2 = it->first.first; 
            for (i2++; i2 <= 20; ++i2) {
                int i3 = it->first.second;
                for (i3--; i3 >= 0; --i3) {
                    LL nxt = p2[i2] * p3[i3] + i;    
                    if (nxt > 1000000) continue;
                    P[nxt][make_pair(i2,i3)] += it->second;
                    sol[nxt] += it->second;
                }
            }
        }
    }
    cout << sum << '\n';
    return 0;
}

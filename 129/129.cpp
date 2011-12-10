#include <iostream>

using namespace std;
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
int main() {
    // upper bound at least: 1000023
    for (int i = 1000001;;i += 2) {
        if (i % 5 == 0) continue;
        int x = rep(i);
        if (x > 1000000) {
            cout << i << '\n';
            break;
        }
    } 
    return 0;
}

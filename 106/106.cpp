#include <iostream>

using namespace std;
int goal = 4;
int total = 0;
int a[100];
int b[100];
void back(int n) {
    if (n == goal) {
        int bate = 0;
        if (a[0] == b[0] && a[0] > 1) {
            for (int i = 1; i <= a[0]; ++i) if (a[i] < b[i]) ++bate;
            if (bate != a[0])
            ++total;
        }
        return;
    }
    back(n+1);
    a[++a[0]] = n; 
    back(n+1);
    --a[0];
    if (a[0]) {
        b[++b[0]] = n;
        back(n+1);
        --b[0];
    }
}
int main() {
    goal = 12;
    a[0] = b[0] = 0;
    back(0); 
    cout << total << '\n';
    return 0;
}

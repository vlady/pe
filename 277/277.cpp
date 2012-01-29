#include <iostream>

using namespace std;
char v[] = "UDDDUdddDDUDDddDdDddDDUDDdUUDd";
int n = 30;
typedef long long LL;
void go(LL i) {
    int pos = n;
    while (pos) {
        char d = v[pos - 1];
        i *= 3LL;
        if (d == 'U') {i -= 2; if (i % 4) return; i /= 4;}
        if (d == 'd') {i += 1; if (i % 2) return; i /= 2;}
        pos--;
    }
    cerr << i << '\n';
}
int main() {
  for (LL i = 1;;++i) go(i);
  return 0;
}

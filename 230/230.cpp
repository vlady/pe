#include <iostream>

using namespace std;
char* A = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
char* B = "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";
typedef long long LL;
LL lenT[1001];
int findKth(int k, LL n) {
    if (k == 0) return A[n-1] - '0';
    if (k == 1) return B[n-1] - '0';
    // lenT[k-2] lenT[k-1]
    if (lenT[k-2] >= n) return findKth(k-2, n);
    else return findKth(k-1, n - lenT[k-2]);
}
int DAB(LL n) {
    int k = 0;
    while (lenT[k] < n) ++k;
    return findKth(k, n);
}
int main() {
    LL answer = 0;
    LL p10 = 1;
    LL p7 = 1;
    lenT[0] = lenT[1] = 100;
    for (int i = 2; i <= 100; ++i) lenT[i] = lenT[i-1] + lenT[i-2];
    for (int n = 0; n < 18; ++n) {
        answer += p10 * DAB((127 + 19 * n) * p7);
        p10 *= 10; p7 *= 7;
    }
    cout << answer << '\n';
    return 0;    
}

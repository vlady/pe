#include <iostream>
#include <set>
#include <cmath>
#include <vector>
using namespace std;
int n;
double v[12];
vector<double> solve(int a, int b) {
    if (a > b) return vector<double>();
    vector<double> ret;
    if (a == b) {
        ret.push_back(v[a]);
        return ret;
    }
    for (int i = a; i < b; ++i) {
        vector<double> A = solve(a, i);
        vector<double> B = solve(i+1, b);
        for (int j = 0; j < A.size(); ++j)
            for (int k = 0; k < B.size(); ++k) {
                ret.push_back(A[j] + B[k]);
                ret.push_back(A[j] - B[k]);
                ret.push_back(A[j] * B[k]);
                if (abs(B[k] - 0) > 1e-9)
                ret.push_back(A[j] / B[k]);
            }
    }
    return ret;
}
vector<double> all;
void back(int k ) {
    if (k == 10) {
        vector<double> x = solve(0, n-1);
        all.insert(all.end(), x.begin(), x.end());
        return;
    }
    v[n] = k; n++;
    back(k+1);
    --n;
    if (k > 1) {
        double aux = v[n - 1];
        v[n - 1] = v[n - 1] * 10 + k;
        back(k+1);
        v[n - 1] = aux;
    }
}
long long is_int(double x) {
    if (x < 0) return 0;
    long long X = (long long)(x + 0.5);
    if (abs(x - double(X)) < 1e-10) return X;
    return 0;
}
int main() {
    n = 0;
    back(1);
    long long total = 0;
    set<long long> hash;
    for (int i = 0; i < all.size(); ++i) { 
        long long X = is_int(all[i]);
        if (hash.find(X) == hash.end()) {
            total += X;
            hash.insert(X);
        }
    }
    cout << total << '\n';
    return 0;    
}

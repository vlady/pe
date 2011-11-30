#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int is_prime(int x) {
	for (int i = 2; i * i <= x; ++i) if (x % i == 0) return 0;
	return 1;
}
int v[50];
double L[50];
typedef long long LL;
int main() {
	for (int i = 2; i < 190; ++i) if (is_prime(i))
		v[++v[0]] = i, L[v[0]] = log(i);
	cerr << v[0] << '\n';
	// divide in two groups
	int n = v[0];
	int m = n / 2;
	vector<pair<double, int> > g1, g2;
	for (int i = 0; i < (1 << m); ++i) {
		double sum = 0;
		for (int j = 0; j < m; ++j) if (i&(1<<j))
			sum += L[j+1];
		g1.push_back(make_pair(sum, i));
	} 
	for (int i = 0; i < (1 << m); ++i) {
		double sum = 0;
		for (int j = 0; j < m; ++j) if (i&(1<<j))
			sum += L[m+j+1];
		g2.push_back(make_pair(sum, i));
	} 
	sort(g1.begin(), g1.end());
	sort(g2.rbegin(), g2.rend());
	double target = g1[g1.size() - 1].first + g2[0].first;
	target /= 2.0;
	cerr << "Target: " << target << '\n';
	double best_sum = 0.0;
	int mask1, mask2;
	int i = 0, j = 0;
	while (i < g1.size()) {
		while (j < g2.size() && g1[i].first + g2[j].first >= target) ++j;
		if (j >= g2.size()) break;
		double sum = g1[i].first + g2[j].first;
		if (sum  < target && sum > best_sum) {
			best_sum = sum;
			mask1 = g1[i].second;
			mask2 = g2[j].second;
		}
		++i;
	}
	cerr << "Best sum: " << best_sum << '\n';
	LL mod = 10000000000000000LL;	
	LL P = 1;
	for (int i = 0; i < m; ++i) {
		if (mask1 & (1 << i)) P = (P * v[i+1]) % mod;
		if (mask2 & (1 << i)) P = (P * v[m+i+1]) % mod;
	}
	cout << P << '\n';
	return 0;
}

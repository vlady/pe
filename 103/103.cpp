#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int is_good(int n, int v[]);
int pp[100];
int best_sum = 0;
// 1
// 1 1
// 2 1 1
// 3 2 1 1
// 7 1 1 2 3
// 11 7 1 1 2 3
void back(int k, int sum) {
    if (sum <= best_sum) return; 
    if (k == 7) {
        if (is_good(k, pp)) {
            best_sum = sum;
            for (int i = 0; i < k; ++i) cout << pp[i] << ' ';
            cout << '\n';
        }
        return;
    }
    for (int i = 1; i <= sum; ++i) {
        pp[k] = pp[k-1] + i;
        back(k+1, sum - i);
    }
    
}
int is_good(int n, int v[]) {
    vector<pair<int, int> > all;
    for (int i = 1; i < (1 << n); ++i) {
        int sum = 0;
        int cate = 0;
        for (int j = 0; j < n; ++j) if (i & (1 << j)) {
            sum += v[j];
            cate++;
        }
        all.push_back(make_pair(sum, cate));
    }
    sort(all.begin(), all.end());
    for (int i = 1; i < all.size(); ++i) {
        if (all[i].first == all[i-1].first) return 0;
        if (all[i].second < all[i-1].second) return 0;
    }
    return 1;
}
int main() {
    int n;
    n = 1;
    int v[] = {1};
    cout << is_good(n, v) << '\n';;



    n = 2;
    int v2[] = {1, 2};
    cout << is_good(n, v2) << '\n';;

    n = 3;
    int v3[] = {2, 3, 4};
    cout << is_good(n, v3) << '\n';;
    
    n = 4;
    int v4[] = {3, 5, 6, 7};
    cout << is_good(n, v4) << '\n';;

    n = 5;
    int v5[] = {6, 9, 11, 12, 13};
    cout << is_good(n, v5) << '\n';;

    n = 6;
    int v6[] = {11, 18, 19, 20, 22, 25};
    cout << is_good(n, v6) << '\n';
    // 7, 1, 1, 2, 3
    // 
    n = 7;
    while (1) {
        int b = 20;
        int v7[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        v7[0] = 20;
        v7[1] = v7[0] + 15;
        v7[2] = v7[1] + 3;
        v7[3] = v7[2] + 2;
        v7[4] = v7[3] + 1;
        v7[5] = v7[4] + 1;
        v7[6] = v7[5] + 7;
        //7, 1, 1, 2, 3
        if (is_good(n, v7)) {
            for (int i = 0; i < 7; ++i) {
                cout << v7[i] << ' ';
            }
            break;
        }
    }
    cout << "Good solution, but need better!\n";
    int sum = 15 + 3 + 2 + 1 + 1 + 7;
    pp[0] = 20;
    best_sum = 0;
    back(1, sum);
    return 0;
}

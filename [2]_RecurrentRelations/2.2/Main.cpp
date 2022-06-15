#include <iostream>
#include <vector>
using namespace std;

void sochet(vector<vector<long long>>& ans, const int& n, const int& k) {
    for (int i = 0; i < n + 1; ++i) {
        ans[i][i] = 1;
        ans[i][0] = 1;
    }
    int p = 0;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j]) % 1000000007;
        }
    }
    cout << ans[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<long long>> ans(n + 1, vector<long long>(n + 1));
    sochet(ans, n, k);
    //cout << endl;
    //for (int i = 0; i < n + 1; ++i) {
    //    for (int j = 0; j < n + 1; ++j) {
    //        cout << ans[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    return 0;
}

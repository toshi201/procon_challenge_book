#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N = 4;
    vector<int> A{2, 1, 3, 2}; // weight
    vector<int> B{3, 2, 4, 2}; // value
    int W = 5;
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= W; ++j) {
            dp[i+1][j] = std::max(dp[i+1][j], dp[i][j]);

            if (j >= A[i]) {
                dp[i+1][j] = std::max(dp[i+1][j], dp[i][j - A[i]] + B[i]);
            }
        }
    }

    cout << *std::max_element(dp[N].begin(), dp[N].end()) << endl;
    return 0;
}
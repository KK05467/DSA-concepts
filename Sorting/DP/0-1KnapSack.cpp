#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack
int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], 
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120}; // values
    vector<int> wt = {10, 20, 30};    // weights
    int W = 50;                       // capacity of knapsack
    int n = val.size();

    cout << "Maximum value in Knapsack = " << knapSack(W, wt, val, n);
    return 0;
}



// Time Complexity

// O(n × W)
// (n = number of items, W = capacity)

// 💾 Space Complexity

// O(n × W) (can be optimized to O(W))
#include <iostream>
#include <climits>
using namespace std;

// Function to find minimum number of multiplications
int matrixChainOrder(int p[], int n) {
    int m[n][n];  // DP table

    // cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1]; // Minimum cost
}

int main() {
    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is " 
         << matrixChainOrder(arr, n);

    return 0;
}


// Time and Space Complexity
// Type	Complexity
// Time Complexity	O(n³) (3 nested loops: i, j, k)
// Space Complexity	O(n²) (DP table)



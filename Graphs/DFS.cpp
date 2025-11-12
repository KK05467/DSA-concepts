#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;
    cout << node << " ";

    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, adj, visited);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {1, 2};

    vector<int> visited(n, 0);
    cout << "DFS Traversal: ";
    dfs(0, adj, visited);

    cout << endl;
    return 0;
}

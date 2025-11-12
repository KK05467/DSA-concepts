#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(int start, vector<vector<int>>& adj, int n) {
    vector<int> visited(n, 0);
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 5; // number of vertices
    vector<vector<int>> adj(n);

    // create undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {1, 2};

    bfsTraversal(0, adj, n);

    return 0;
}

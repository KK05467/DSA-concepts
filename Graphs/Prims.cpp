#include <bits/stdc++.h>
using namespace std;

void primsMST(int V, vector<vector<pair<int, int>>>& adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = -1;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }

        inMST[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int wt = it.second;
            if (!inMST[v] && wt < key[v]) {
                parent[v] = u;
                key[v] = wt;
            }
        }
    }

    cout << "Edges in MST using Prim's:\n";
    int total = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
        total += key[i];
    }
    cout << "Total cost of MST: " << total << endl;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    adj[0] = {{1, 2}, {2, 4}};
    adj[1] = {{0, 2}, {2, 1}, {3, 7}};
    adj[2] = {{0, 4}, {1, 1}, {4, 3}};
    adj[3] = {{1, 7}, {4, 2}};
    adj[4] = {{2, 3}, {3, 2}};

    primsMST(V, adj);
    return 0;
}

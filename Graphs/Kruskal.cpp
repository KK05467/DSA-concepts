#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find)
int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v]) parent[u] = v;
    else if (rank[v] < rank[u]) parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalMST(int V, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        return a[2] < b[2];
    });

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    vector<pair<int, int>> mstEdges;
    int total = 0;

    for (auto it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        if (findParent(u, parent) != findParent(v, parent)) {
            total += wt;
            mstEdges.push_back({u, v});
            unionSet(u, v, parent, rank);
        }
    }

    cout << "Edges in MST using Kruskal's:\n";
    for (auto it : mstEdges) {
        cout << it.first << " - " << it.second << endl;
    }
    cout << "Total cost of MST: " << total << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 2, 4}, {1, 2, 1},
        {1, 3, 7}, {2, 4, 3}, {3, 4, 2}
    };

    kruskalMST(V, edges);
    return 0;
}

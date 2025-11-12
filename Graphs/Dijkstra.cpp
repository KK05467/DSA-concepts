#include <bits/stdc++.h>
using namespace std;

void dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Min-heap {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto it : adj[node]) {
            int next = it.first;
            int wt = it.second;

            if (d + wt < dist[next]) {
                dist[next] = d + wt;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "Dijkstra shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // undirected weighted graph
    adj[0] = {{1, 2}, {2, 4}};
    adj[1] = {{0, 2}, {2, 1}, {3, 7}};
    adj[2] = {{0, 4}, {1, 1}, {4, 3}};
    adj[3] = {{1, 7}, {4, 2}};
    adj[4] = {{2, 3}, {3, 2}};

    dijkstra(V, adj, 0);
    return 0;
}

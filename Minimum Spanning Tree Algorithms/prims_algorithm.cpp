#include <bits/stdc++.h>
using namespace std;

int primsMST(int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> visited(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});  // {weight, node}
    int totalWeight = 0;

    while (!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;
        visited[node] = 1;
        totalWeight += wt;

        for (auto [adjNode, adjWt] : adj[node]) {
            if (!visited[adjNode]) pq.push({adjWt, adjNode});
        }
    }

    return totalWeight;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adj[2] = {{1, 3}, {4, 7}};
    adj[3] = {{0, 6}, {1, 8}, {4, 9}};
    adj[4] = {{1, 5}, {2, 7}, {3, 9}};

    cout << "Minimum Spanning Tree weight: " << primsMST(n, adj);
    return 0;
}

/*
Logic:
- Always pick the minimum-weight edge that expands the tree.
- Greedy ensures globally minimal weight without cycles.
Time Complexity: O(E log V)
Space Complexity: O(V + E)

Algorithm Steps:
1. Start from any node (usually 0).
2. Use a min-heap (priority queue) to select the smallest edge leading to an unvisited node.
3. Mark nodes as visited once added to the MST.
4. Repeat until all nodes are included in the MST.

Prim's algorithm is a greedy technique used to find the Minimum Spanning Tree (MST) 
of a weighted undirected graph. It grows the MST from one vertex, adding the next 
smallest edge that connects a vertex inside the MST to a vertex outside it.
*/
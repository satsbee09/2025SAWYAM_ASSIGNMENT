#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int kruskalMST(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        return a[2] < b[2];
    });

    DisjointSet ds(n);
    int totalWeight = 0;

    for (auto& e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        if (ds.find(u) != ds.find(v)) {
            totalWeight += wt;
            ds.unite(u, v);
        }
    }
    return totalWeight;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    cout << "Minimum Spanning Tree weight: " << kruskalMST(n, edges);
    return 0;
}

/*
Logic:
- Sort all edges by increasing weight.
- Use Union-Find to avoid cycles.
- Continue until MST has (V - 1) edges.
Time Complexity: O(E log E)
Space Complexity: O(V)

Algorithm Steps:
1. Sort all edges by weight (ascending).
2. Initialize disjoint sets for all vertices.
3. For each edge (u, v, w):
   - If u and v belong to different sets, include the edge and unite the sets.
4. Stop when (V-1) edges are included.

Kruskal's algorithm also finds an MST using a greedy approach but works by sorting 
all edges and adding them one by one provided they don't form a cycle.
It uses a Disjoint Set Union (Union-Find) data structure to check cycles efficiently.
*/
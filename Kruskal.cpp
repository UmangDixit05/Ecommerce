// Kruskal's Minimum Spanning Tree Algorithm (Greedy Algorithm)
// Takes input from the user

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Compare edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (Union-Find)
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(V);

    vector<Edge> mst;
    int totalWeight = 0;

    // Kruskal's Algorithm
    for (Edge edge : edges) {

        int u = edge.src;
        int v = edge.dest;

        // Check if adding this edge forms a cycle
        if (dsu.find(u) != dsu.find(v)) {

            mst.push_back(edge);
            totalWeight += edge.weight;

            dsu.unite(u, v);
        }
    }

    // Output MST
    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (Edge edge : mst) {
        cout << edge.src << " -- "
             << edge.dest << " == "
             << edge.weight << endl;
    }

    cout << "\nTotal Weight of MST = " << totalWeight << endl;

    return 0;
}
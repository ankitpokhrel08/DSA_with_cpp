#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
class Graph {
    int V; // Number of vertices
    vector<Edge> edges; // Vector to store all edges

public:
    Graph(int V) {
        this->V = V;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    // Function to find the MST using Kruskal's algorithm
    void kruskalMST();
};

// To represent Disjoint Sets
class DisjointSets {
    vector<int> parent, rank;
    int n;

public:
    DisjointSets(int n) {
        this->n = n;
        parent.resize(n);
        rank.resize(n);

        // Initially, all vertices are in different sets and have rank 0
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Each vertex is its own parent
            rank[i] = 0;
        }
    }

    // Find the parent of a node 'u' using path compression
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (rank[x] > rank[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }

        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
};

// Comparison function to sort edges based on their weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find MST using Kruskal's algorithm
void Graph::kruskalMST() {
    // Result vector to store the MST
    vector<Edge> result;

    // Sort all edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Create disjoint sets
    DisjointSets ds(V);

    // Process all sorted edges
    for (Edge& edge : edges) {
        int u = edge.src;
        int v = edge.dest;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // Check if the selected edge creates a cycle
        if (set_u != set_v) {
            // Include this edge in result
            result.push_back(edge);
            
            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }

    // Print the MST
    cout << "Edges in the Minimum Spanning Tree (Kruskal's):\n";
    int totalWeight = 0;
    for (Edge& edge : result) {
        cout << "(" << edge.src << ", " << edge.dest << ") with weight " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    // Create a sample graph
    int V = 6;  // Number of vertices
    Graph g(V);

    // Adding edges to the graph (example graph)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 5);

    // Display the graph
    cout << "Graph representation: \n";
    cout << "Edge  Weight\n";
    cout << "0-1    4\n";
    cout << "0-2    3\n";
    cout << "1-2    1\n";
    cout << "1-3    2\n";
    cout << "2-3    4\n";
    cout << "2-4    3\n";
    cout << "3-4    2\n";
    cout << "3-5    1\n";
    cout << "4-5    5\n\n";

    // Find and print MST
    g.kruskalMST();

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for pair
#include <climits> // for INT_MAX
using namespace std;

// Graph class representing a weighted undirected graph using adjacency list
class Graph {
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Adjacency list representation

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int w) {
        // Since the graph is undirected, add edges in both directions
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    // Function to find MST using Prim's algorithm
    void primMST();
};

void Graph::primMST() {
    // Create a priority queue to store vertices sorted by their key value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with vertex 0
    int src = 0;

    // Create vectors for storing key values, MST set, and parent of each vertex
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    // Add source to priority queue and set its key value to 0
    pq.push(make_pair(0, src));
    key[src] = 0;

    // Loop until priority queue becomes empty
    while (!pq.empty()) {
        // Extract the minimum key vertex from priority queue
        int u = pq.top().second;
        pq.pop();

        // If vertex is already in MST, continue
        if (inMST[u]) continue;

        // Include vertex in MST
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If v is not in MST and weight of (u,v) is smaller than current key of v
            if (!inMST[v] && weight < key[v]) {
                // Update key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edges in the Minimum Spanning Tree (Prim's):\n";
    int totalWeight = 0;
    for (int i = 1; i < V; ++i) {
        cout << "(" << parent[i] << ", " << i << ") with weight " << key[i] << endl;
        totalWeight += key[i];
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    // Create a sample graph
    int V = 6;  // Number of vertices
    Graph g(V);

    // Adding edges to the graph (same example as in Kruskal's)
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
    g.primMST();

    return 0;
}
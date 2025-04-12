#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <string>
using namespace std;

// Graph class representing a weighted undirected graph
class Graph {
    // Number of vertices
    int V;
    
    // Names of locations (vertices)
    map<int, string> locationNames;
    
    // Map from location names to vertex indices
    map<string, int> nameToIndex;
    
    // Adjacency list representation
    vector<vector<pair<int, int>>> adjList; // pair: (destination, weight)

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight)); // For undirected graph
    }

    // Add a location name for a vertex
    void addLocation(int index, string name) {
        locationNames[index] = name;
        nameToIndex[name] = index;
    }

    // Get location name by index
    string getLocationName(int index) {
        return locationNames[index];
    }

    // Get index by location name
    int getLocationIndex(string name) {
        return nameToIndex[name];
    }

    // Get all location names
    vector<string> getAllLocations() {
        vector<string> locations;
        for (const auto& entry : locationNames) {
            locations.push_back(entry.second);
        }
        return locations;
    }

    // Dijkstra's algorithm to find shortest path from src to all other vertices
    void dijkstra(int src, int dest) {
        // Min heap to store vertices and their distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Create vectors for distances and parent (to reconstruct path)
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);

        // Insert source with distance 0
        pq.push(make_pair(0, src));
        dist[src] = 0;

        // Process vertices
        while (!pq.empty()) {
            // Get vertex with minimum distance
            int u = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            // If we already found a shorter path or reached destination
            if (distance > dist[u]) continue;
            if (u == dest) break; // Optional optimization if we only care about src to dest

            // Process all adjacent vertices
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If we find a shorter path to v through u
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // Print the shortest path from src to dest
        if (dist[dest] == INT_MAX) {
            cout << "No path exists from " << getLocationName(src) << " to " << getLocationName(dest) << endl;
            return;
        }

        // Reconstruct path
        vector<int> path;
        for (int at = dest; at != -1; at = parent[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        // Print the path
        cout << "\nShortest path from " << getLocationName(src) << " to " << getLocationName(dest) << ":\n";
        for (int i = 0; i < path.size(); i++) {
            cout << getLocationName(path[i]);
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << "\nTotal distance: " << dist[dest] << " units" << endl;
    }
};

int main() {
    // Create a graph with 8 cities/locations
    Graph g(8);
    
    // Add locations (cities)
    g.addLocation(0, "New York");
    g.addLocation(1, "Los Angeles");
    g.addLocation(2, "Chicago");
    g.addLocation(3, "Houston");
    g.addLocation(4, "Phoenix");
    g.addLocation(5, "Philadelphia");
    g.addLocation(6, "San Antonio");
    g.addLocation(7, "San Diego");

    // Add edges (roads between cities) with distances
    g.addEdge(0, 2, 800);  // NY - Chicago
    g.addEdge(0, 5, 100);  // NY - Philly
    g.addEdge(1, 4, 400);  // LA - Phoenix
    g.addEdge(1, 7, 120);  // LA - San Diego
    g.addEdge(2, 3, 1000); // Chicago - Houston
    g.addEdge(3, 6, 200);  // Houston - San Antonio
    g.addEdge(4, 6, 800);  // Phoenix - San Antonio
    g.addEdge(4, 7, 300);  // Phoenix - San Diego
    g.addEdge(5, 2, 700);  // Philly - Chicago
    
    // Display the graph
    cout << "City Road Network:\n";
    cout << "------------------------\n";
    cout << "Roads and Distances:\n";
    cout << "New York -- Chicago: 800\n";
    cout << "New York -- Philadelphia: 100\n";
    cout << "Los Angeles -- Phoenix: 400\n";
    cout << "Los Angeles -- San Diego: 120\n";
    cout << "Chicago -- Houston: 1000\n";
    cout << "Houston -- San Antonio: 200\n";
    cout << "Phoenix -- San Antonio: 800\n";
    cout << "Phoenix -- San Diego: 300\n";
    cout << "Philadelphia -- Chicago: 700\n";
    cout << "------------------------\n";

    // Display available cities
    vector<string> cities = g.getAllLocations();
    cout << "\nAvailable cities:\n";
    for (int i = 0; i < cities.size(); i++) {
        cout << i + 1 << ". " << cities[i] << endl;
    }

    // Ask user for starting point
    string startCity;
    cout << "\nEnter your starting city: ";
    getline(cin, startCity);

    // Ask user for destination
    string endCity;
    cout << "Enter your destination city: ";
    getline(cin, endCity);

    try {
        int startIndex = g.getLocationIndex(startCity);
        int endIndex = g.getLocationIndex(endCity);

        cout << "\nCalculating shortest path...\n";
        g.dijkstra(startIndex, endIndex);
    }
    catch (const exception& e) {
        cout << "Error: One or both of the cities were not found in our network." << endl;
        cout << "Please check the spelling and try again." << endl;
    }

    return 0;
}
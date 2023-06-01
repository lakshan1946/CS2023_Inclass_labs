#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a node and its weight in the graph
struct Node {
    int vertex;
    int weight;

    // Comparison operator for priority queue
    bool operator<(const Node& otherNode) const {
        return weight > otherNode.weight;
    }
};
// Dijkstra's algorithm implementation
void dijkstra(vector<vector<int>>& graph, int source) {
    int numVertices = graph.size();

    // Create a priority queue to store nodes with their weights
    priority_queue<Node> pq;

    // Create a vector to store distances from the source
    vector<int> distance(numVertices, INT_MAX);

    // Set the distance of the source vertex to 0
    distance[source] = 0;

    // Push the source vertex to the priority queue
    pq.push({source, 0});

    // Loop until the priority queue is empty
    while (!pq.empty()) {
        // Get the vertex with the minimum weight
        int u = pq.top().vertex;
        pq.pop();

        // Iterate through all the adjacent vertices of u
        for (int v = 0; v < numVertices; ++v) {
            int weight = graph[u][v];

            // If a shorter path is found, update the distance and push it to the priority queue
            if (weight != 0 && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({v, distance[v]});
            }
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from source vertex " << source << ":\n";
    int total;
    for (int i = 0; i < numVertices; ++i) {
        total+=distance[i];
        cout << "Vertex " << source << " to " <<i<<" : " <<distance[i] << endl;
    }
    cout<<"Average Time: "<<(double)total/5;
}

int main() {
    vector<vector<int>> graph = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}
    };

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    dijkstra(graph, source);

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int source, dest, weight;
};

// find the MST using Prim's algorithm
vector<Edge> primMST(vector<vector<int>>& graph, int vertices, int source) {
    // priority queue to store edges
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> key(vertices, INT_MAX); // to store key values & set all as infinite
    vector<int> parent(vertices, -1); // to track the parent of each vertex in MST
    vector<Edge> mst; // to store the MST
    vector<bool> inMST(vertices, false); // to track if a vertex is included in MST or not


    // Insert the source vertex into the priority queue
    pq.push(make_pair(0, source));
    key[source] = 0;

    // Iterate until all vertices are included in MST
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Include the vertex in MST
        inMST[u] = true;

        // Explore all adjacent vertices of u
        for (int v = 0; v < vertices; ++v) {
            // When the weight is less than the current key and v is an adjacent vertex of u but not included by MST
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                // Update the key value and parent
                key[v] = graph[u][v];
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Construct the MST using the parent vector
    for (int i = 0; i < vertices; ++i) {
        if (parent[i] != -1) {
            mst.push_back({ parent[i], i, graph[parent[i]][i] });
        }
    }

    return mst;
}

int main() {
    // graph represented by an adjacency matrix
    vector<vector<int>> graph = {
            {0,3,0,0,0,1},
            {3,0,2,1,10,0},
            {0,2,0,3,0,5},
            {0,1,3,0,5,0},
            {0,10,0,5,0,4},
            {1,0,5,0,4,0}
    };

    int vertices = graph.size();
    int source;
    cout<<"Enter source vertex: ";
    cin>>source;

    vector<Edge> mst = primMST(graph, vertices, source);

    // Print the MST edges and their weights
    cout << "MST Edges:\n";
    int cost;
    for (const auto& edge : mst) {
        cout << edge.source << " - " << edge.dest << " : " << edge.weight << endl;
        cost+=edge.weight;
    }
    //print the minimum cost
    cout<<"Cost from "<<source<<" is: "<<cost;

    return 0;
}

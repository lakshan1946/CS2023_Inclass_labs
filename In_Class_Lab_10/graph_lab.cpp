#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    //2. a int type list called neighbours
    int label;
    list <int> neighbours;
};

struct Graph {
    //graph will have an array of type "node" with length specified by n
    int n = 8;
    Node *nodes = new Node[n];

    void intializenodes() {
        //iterate through the nodes and assign labels
        for (int i = 0; i < n; i++) {
            nodes[i].label = i+1;
        }
    }

    void addEdge(int u, int v) {
        //select node u and push v into u's neighbour
        nodes[u-1].neighbours.push_back(v);
        //select node v and push u into v's neighbour
        nodes[v-1].neighbours.push_back(u);
    }

    void print() {
        //lets iterate through each node and print its neighbours
        for (int i = 0; i < n; i++) {
            cout << nodes[i].label << " [ ] ---> ";
            for (int neighbour: nodes[i].neighbours) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    };
};

int main() {
        Graph *g = new Graph;
        g->intializenodes();
        //add edges for the graphs here.
        g->addEdge(1, 2);
        g->addEdge(1, 3);
        g->addEdge(1, 4);
        g->addEdge(1, 5);

        g->addEdge(2, 3);
        g->addEdge(2, 6);

        g->addEdge(4, 6);
        g->addEdge(4, 8);
        g->addEdge(4, 7);

        g->addEdge(5, 6);
        g->addEdge(5, 7);
        g->addEdge(5, 8);

    //print the graph adjaceny list
        g->print();
        delete g;  // Don't forget to free the memory allocated with 'new'
        return 0;
    }
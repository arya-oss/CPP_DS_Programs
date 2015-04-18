/**
 * Depth first traversal of a graph
 *
 */
#include <iostream>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> * adj;
public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int src, int dest) {
        sdj[src].push_back(dest);
    }
};

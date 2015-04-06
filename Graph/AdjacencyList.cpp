/**
 * Adjacency Matrix Representation of Graph
 *
 */
#include <iostream>
#include <stdlib.h>

using namespace std;

class Graph{
    int ** Adj; // 2-d matrix
    int V; // no. of vertex
public:
    Graph(int V){
        this->V = V;
        Adj = new int * [V];
        for(int i=0; i<V; i++)
            Adj[i] = new int[V];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++)
                Adj[i][j]=0;
        }
    }
    void addEdge(int src, int dest){
        Adj[src][dest] = 1;
        Adj[dest][src] = 1;
    }
    void print(){
        for(int i=0; i<V; i++){
            cout << "\n";
            for(int j=0; j<V; j++) {
                cout<< " " << Adj[i][j];
            }
        }
    }
};


int main() {
    Graph * g;
    g = new Graph(4);
    g->addEdge(0,1);
    g->print();
    return 0;
}

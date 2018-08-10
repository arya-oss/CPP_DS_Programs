/**
 * Breadth first traversal of a graph
 *
 */
#include <iostream>
#include <list>
#include <queue>

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
        adj[src].push_back(dest);
    }

    void bfs(int start) {
        queue<int> s;
        bool visited[V];
        for (int i=0; i < V; i++) {
            visited[i] = false;
        }
        s.push(start);
        visited[start] = true;
        while(!s.empty()) {
            int st = s.front();
            s.pop();
            cout << st << " ";
            for (list<int>::iterator it = adj[st].begin(); it != adj[st].end(); it++) {
                if (!visited[*it]) {
                    s.push(*it);
                    visited[*it] = true;
                }
            }
        }
    }
};

int main (int argc, char const * argv[]) {
    Graph * graph = new Graph(5);
    graph->addEdge(0, 3);
    graph->addEdge(1, 3);
    graph->addEdge(0, 2);
    graph->addEdge(1, 2);
    graph->addEdge(2, 4);
    graph->addEdge(4, 3);
    
    graph->bfs(0);

    return 0;
}

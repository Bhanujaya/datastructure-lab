#include <list>
#include <iostream>
using namespace std;


class Graph {
    int v; //number of nodes
    list<int> *adj; //adj list 

    public:
        Graph(int v);
        void addEdge(int v, int w);
        void BFSVisit(int s);

};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);


}

void Graph::BFSVisit(int s) {
    //create array of visit contain boolen and get it pointer
    bool *visited = new bool[v];
    //mark all false (inidicate unvisited)
    for (int i = 0 ; i < v ; i++) {
        visited[i] = false;
    }

    //create queue to temporary store level node
    list<int> queue;
    //mark current node visited
    visited[s] = true;
    queue.push_back(s);

    //create iterator
    list<int>::iterator i;
    //initialize to get current adjlist index
    int u ;
    //while queue is not empty
    while (!queue.empty()) {
        //get current node from queue
        u = queue.front();
        cout << u << "\n";
        //pop current node out
        queue.pop_front();

        //loop inside of the list of that index
        for (i = adj[u].begin() ; i != adj[u].end() ; i++) {
            //if not yet visited make it as visit and add it to queue
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);

            }
        }
             

    }


}

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);

    cout << "Following BFS start from vertex 0\n";
    g.BFSVisit(0);
    cout << "\n" ; 
    cout << "Following BFS start from vertex 2\n";
    g.BFSVisit(2);
}




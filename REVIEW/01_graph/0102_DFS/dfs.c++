#include <iostream>
#include <list>
using namespace std;


//create graph class with function prototype of it
class Graph {
    int v;  // number of nodes
    list<int> *adj ; //list of pointer to each index of adj list

    void DFSVisit(int s , bool visited[]);

    public: 
        Graph(int v); //constructor 
        void addEdge(int v, int w);
        void DFSInit(int s);

}; 

//implement prototype

//constructor
Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v]; //create new array of pointer of size v

}

//addEdge 
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}


void Graph::DFSVisit(int s, bool visited[]) {
    visited[s] = true;
    cout << "MARKED: " << s << " \n";
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); i++) {
        cout << "IN: " << *i << " ";
        if (!visited[*i]) {
            cout << "UNVISIT: " << *i << "\n";
            DFSVisit(*i , visited);
        }
        
    }
    

}

void Graph::DFSInit(int s) {
    //create boolean array of size v
    bool * visited = new bool[v];
    for (int i = 0 ; i < v ; i++) {
        visited[i] = false;
    }

    DFSVisit(s, visited);

    
}

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);

    cout << "Following DFS start from vertex 2\n";
    g.DFSInit(2);
    cout << "\n" ; 
    cout << "Following DFS start from vertex 3\n";
    g.DFSInit(3);
}



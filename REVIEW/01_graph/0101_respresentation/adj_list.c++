//use STL C++ implementation
#include <iostream>
#include <vector>
using namespace std;


vector<int> * createGraph(int n) {
    //create new vector of int size n
    return new vector<int>[n];

}


void addEdge(vector<int>* adjList, int u, int v) {
    //push v to adjList index u (vertex u ) make u---v
    adjList[u].push_back(v);

}

void removeEdge(vector<int> * adjList, int u , int v) {
     //find v in index u of list
    for (int i = 0 ; i < adjList[u].size() ; i++ ) {
        //if find at index i  
        if (adjList[u].at(i) == v) {
            //use .erase function of vector at index 0 + i (index i )
            adjList[u].erase(adjList[u].begin() + i);
            return ;
        }

    }
}

// //teacher 
// void addVertex(int &n , int u) {
//     n = u + 1;
// }
void addVertex(vector<int>* &adjList, int &n, int u) {
    // create a new array of vectors with an additional slot for the new vertex.
    vector<int>* newAdjList = new vector<int>[n + 1];

    // Copy the existing data from the old adjacency list to the new one.
    for (int i = 0; i < n; i++) {
        newAdjList[i] = adjList[i];
    }

    newAdjList[n] = vector<int>();
    newAdjList[n].push_back(u);

    // Update the adjacency list and increment the number of vertices.
    delete[] adjList;
    adjList = newAdjList;
    n++;
}

void removeVertex(vector<int> *adjList, int &n , int u) {
    //if index u is more than size of adjList
    if (u < n -1 ) {
        //return because it is invalid
        return ;
    }

    for (int v = 0 ; v < n ; v++) {
        //use removeEdge()
        removeEdge(adjList, v, u); 
    }

    adjList[u].clear();
    n--;
}


bool isAdjacent(vector <int> * adjList, int u , int v) {
    for (int i = 0 ; i < adjList[u].size() ; i++) {
        //check if at index u there's v
        if (adjList[u].at(i) == v) {
            return true;
        }
    }
    return false;
}


//n is number of vertex u is vertex that we want to find
int inDegree(vector <int> * adjList , const int n , int u  ) {
    int count = 0 ;
    for (int v = 0 ; v < n ; v++) {
        for (int i = 0 ;  i < adjList[v].size() ; i++) {
              if (adjList[v].at(i) == u) {
            count++;
        }

        }
      
    }
    return count;


}

int outDegree(vector <int> * adjList, int u) {
    //size at index u 
    return adjList[u].size();
  
}


void printGraph(vector <int>* adjList , int V) {
    for (int v = 0 ; v < V ; ++v ) {
        cout << "[" << v  << "] head" ;
        for (int i = 0 ; i < adjList[v].size() ; i++) {
            cout << "->" << adjList[v].at(i);

        }
        cout << endl;


    }
    cout << endl;

}


int main() {
    int n = 5;
    vector<int>* adjList = createGraph(n);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 1);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 4, 3);

    printGraph(adjList, n);
    cout << "=======================================================" << endl;


    // Example usage of other functions
    addVertex(adjList, n, 5);
    removeVertex(adjList, n, 2);
    printGraph(adjList, n);

    // Check if vertices are adjacent
    cout << "Is 0 adjacent to 1? " << (isAdjacent(adjList, 0, 1) ? "Yes" : "No") << endl;
    cout << "Is 0 adjacent to 2? " << (isAdjacent(adjList, 0, 2) ? "Yes" : "No") << endl;

    // Calculate in-degree and out-degree
    cout << "In-degree of vertex 1: " << inDegree(adjList, n, 1) << endl;
    cout << "Out-degree of vertex 1: " << outDegree(adjList, 1) << endl;

}
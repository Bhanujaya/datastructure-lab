//dfs 
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n , m, k , i, u ,v;
    cin >> n >> m >> k ;
    vector<int> graph[n];
    for (i = 0  ;  i < m+2 ; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    cout << "SIZE" << graph[k].size() << "\n" ;
    vector<int>::iterator j;
    for (j = graph[k].begin() ; j != graph[k].end() ; j++) {
        cout << *j << " ";
    }
    


}
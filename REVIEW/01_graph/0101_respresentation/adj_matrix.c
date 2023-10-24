//use c implemenation
#include <stdio.h>


int ** createGraph (const int n) {

    
    int * adjMatrix = malloc(sizeof(int) * n);
    //row initialize [] size n
    //               [] 
    //               [] 
    //               [] 
    //               [] 
    for (int i = 0 ; i < n ; i++) {
      
        adjMatrix[i] = malloc(sizeof(int)*n);
        //column initialize [ / / / / ] size n      
        for (int j = 0 ; j <n ; j++) {
            //initialize with 0 
            adjMatrix[i][j] = 0;
        
        }

    }
    return adjMatrix;

}

void addEdge(int **adjMatrix , int u , int v) {
    adjMatrix[u][v] = 1;
}

void removeEdge(int ** adjMatrix, int u , int v) {
    adjMatrix[u][v] = 0;

}


void printGraph(int ** adjMatrix , int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            printf("%d" , adjMatrix[i][j]);

        }
        printf("\n");

 }}

void deleteGraph(int ** adjMatrix , int n ) {
    for (int i = 0 ; i < n ; i++) {
        //free each row
        free(adjMatrix[i]);
        

    }
    free(adjMatrix);

}

int ** addVertex(int ** adjMatrix, int *n, int u ) {
    int ** adjMatrix_new = createGraph(u+1);
    //pointer to newly create graph
    for (int i = 0 ; i < *n ; i++) {
        for (int j =0 ; j < *n ; j++ ) {
            //copy value from oldGraph to newGraph check if value is 1
            if (adjMatrix[i][j] == 1) {
                
                adjMatrix_new[i][j] = 1;
            }
        }
    }
    //delete oldGraph
    deleteGraph(adjMatrix, *n);
    //make size n + 1
    *n = u+1;
    return adjMatrix_new;
}


int ** removeVertex(int ** adjMatrix , int * n , int u) {
    //loop check for the row first 
    for (int i =0 ; i < *n ; i++) {
        for (int j = u ; j < *n-1 ; j++) {
            adjMatrix[i][j] = adjMatrix[i][j+1];

        }
    }

    //loop check for the column
    for (int i = 0 ; i < *n ; i++) {
        for (int j = u ; j < *n-1 ; j++) {
            adjMatrix[j][i] = adjMatrix[j+1][i];
        }
    }
    
    //create new graph with size n-1
    int ** adjMatrix_new = createGraph(*n - 1);
    for (int i = 0 ; i < *n-1 ; i++) {
        for (int j = 0; j < *n-1 ; j++) {
            adjMatrix_new[i][j] = adjMatrix[i][j];
        }
    }
    
    deleteGraph(adjMatrix, *n);
    (*n)--;

    return adjMatrix_new;
}

int isAdjacent(int ** adjMatrix , int u , int v) {
    if (adjMatrix[u][v] ==1) {
        return 1;
    } else {
        return 0;
    }
}


int inDegree(int ** adjMatrix , const  int n, int u ) {
    int in_deg = 0 ;
    for (int i = 0 ; i < n ; i++) {
        if (adjMatrix[i][u]) {
            in_deg++;
        }

        return in_deg; 
    }
}

int outDegree(int ** adjMatrix , const int n , int u) {
    int out_deg = 0;
    for (int i = 0 ; i < n ; i++) {
        if (adjMatrix[u][i]) {
            out_deg++;
        }
    }

    return out_deg;
}





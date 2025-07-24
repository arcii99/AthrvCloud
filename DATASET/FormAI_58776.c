//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>

#define MAX_VERTICES 5

int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix representing the graph
int color[MAX_VERTICES]; // array to store the color of each vertex

int isSafe(int v, int c){
    for(int i=0; i<MAX_VERTICES; i++){
        if(graph[v][i] && c == color[i]){ // if adjacent vertex is already colored with same color
            return 0; // color is not safe
        }
    }
    return 1; // color is safe
}

void graphColor(int vertex){
    if(vertex == MAX_VERTICES){ // base case: all vertices have been assigned a color
        printf("Colors for vertices:\n");
        for(int i=0; i<MAX_VERTICES; i++){
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
        return;
    }

    for(int c=1; c<=MAX_VERTICES; c++){ // try all possible colors for current vertex
        if(isSafe(vertex, c)){ // check if the color is safe to use
            color[vertex] = c; // assign the color to the vertex
            graphColor(vertex+1); // move on to the next vertex
            color[vertex] = 0; // reset the color for backtracking
        }
    }
}

int main(){
    // initialize graph adjacency matrix
    for(int i=0; i<MAX_VERTICES; i++){
        for(int j=0; j<MAX_VERTICES; j++){
            graph[i][j] = 0;
        }
    }

    // add edges to the graph
    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[1][2] = 1;
    graph[2][1] = 1;

    graph[1][3] = 1;
    graph[3][1] = 1;

    graph[2][3] = 1;
    graph[3][2] = 1;

    graph[3][4] = 1;
    graph[4][3] = 1;

    graphColor(0);

    return 0;
}
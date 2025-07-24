//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int vertices[MAX_VERTICES], edges[MAX_VERTICES][MAX_VERTICES];        //Graph Declaration

bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int c[], int col) {
    for(int i = 0; i < MAX_VERTICES; i++) {                //Check if vertex is not already colored with the same color
        if(graph[v][i] && col == c[i]) 
            return false;
    }
    return true;                                        //Vertex is safe to be colored with this color
}

bool graphColoringRec(int graph[MAX_VERTICES][MAX_VERTICES], int m, int c[], int v) {
    if(v == MAX_VERTICES) {                //All Vertices have been assigned colors
        for(int i = 0; i < MAX_VERTICES; i++)
            printf("Vertex %d ---> %d\n", i, c[i]);
    return true;
    }
    for(int col = 1; col <= m; col++) {                        //Try out different colors for current vertex
        if(isSafe(v, graph, c, col)) {                            //Check if safe to color vertex with color col
            c[v] = col;
            if(graphColoringRec(graph, m, c, v+1) == true)        //Assign color and proceed to next vertex
                return true;
            c[v] = 0;                        //Backtrack if no color assignment works
        }
    }
    return false;                            //Cannot assign any color to vertex v
}

bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m) {
    int c[MAX_VERTICES];                                //Array to store assigned colors
    
    for(int i = 0; i < MAX_VERTICES; i++)
        c[i] = 0;                                //Assign no colors initially
        
    if(graphColoringRec(graph, m, c, 0) == false) {            //Start from vertex 0 and proceed recursively
        printf("Failed to Color Graph");
        return false;
    }
    return true;
}

int main() {
    for(int i = 0; i < MAX_VERTICES; i++) {                //Generate Random Graph with Irregular Edges
        for(int j = 0; j < MAX_VERTICES; j++) {
            if(i < j) {
            edges[i][j] = rand()%2;        //Assign Edge or No Edge Randomly
            edges[j][i] = edges[i][j];    //Make Undirected Graph
            } 
        }
    }
    printf("Graph:\n");                        //Print Graph Edges
    for(int i = 0; i < MAX_VERTICES; i++) {
        for(int j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", edges[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int m = 3;                            //Number of Colors Available
    if(graphColoring(edges, m) == true)
        printf("Graph has been colored with %d colors successfully", m);
    return 0;
}
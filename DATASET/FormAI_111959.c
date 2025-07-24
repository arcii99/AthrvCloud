//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum number of vertices
#define MAX_VERTICES 10

// Defining the colors to be used
#define RED 1
#define BLUE 2
#define GREEN 3
#define YELLOW 4

// Function to check if it is safe to assign a color to a vertex
int isSafe(int graph[][MAX_VERTICES], int vertices[], int currentVertex, int color, int numVertices){
    for(int i=0;i<numVertices;i++){
        // If a vertex is adjacent to the current vertex and has the same color, then it is unsafe
        if(graph[currentVertex][i] && color==vertices[i]){
            return 0;
        }
    }
    return 1; // Safe to assign the color
}

// Recursive function to assign colors to the vertices
void assignColors(int graph[][MAX_VERTICES], int numVertices, int vertices[], int currentVertex){
    // If all the vertices have been assigned a color, then print the solution
    if(currentVertex == numVertices){
        printf("The colors assigned to vertices are: \n");
        for(int i=0;i<numVertices;i++){
            printf("%d ",vertices[i]);
        }
        printf("\n");
        return;
    }

    // Assigning color to the vertex
    for(int i=RED;i<=YELLOW;i++){
        if(isSafe(graph,vertices,currentVertex,i,numVertices)){
            vertices[currentVertex]=i;
            assignColors(graph,numVertices,vertices,currentVertex+1);
            vertices[currentVertex]=0; // Backtracking
        }
    }
}

// Main function
int main(){
    int graph[MAX_VERTICES][MAX_VERTICES], numVertices;

    printf("Enter the number of vertices (Max: 10): ");
    scanf("%d",&numVertices);

    // Taking adjacency matrix as input
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    // Initializing the vertices array as 0
    int vertices[MAX_VERTICES]={0};

    // Assigning colors to the vertices
    assignColors(graph,numVertices,vertices,0);

    return 0;
}
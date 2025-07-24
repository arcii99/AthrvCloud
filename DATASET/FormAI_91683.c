//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Initializing the graph matrix with 0's
int graph[5][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

// Function to add an edge between two vertices
void addEdge(int v1, int v2) {
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
}

// Function to remove an edge between two vertices
void removeEdge(int v1, int v2) {
    graph[v1][v2] = 0;
    graph[v2][v1] = 0;
}

// Function to display the graph
void displayGraph() {
    printf("The graph matrix is:\n");
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Adding edges to form a graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);

    // Displaying the graph
    displayGraph();

    // Removing an edge and displaying the graph again
    removeEdge(0, 2);
    displayGraph();

    return 0;
}
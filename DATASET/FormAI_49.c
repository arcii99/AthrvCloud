//FormAI DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
/*
 * C Graph Representation
 *
 * Written by [Your Name, Email]
 *
 * This program represents an undirected graph using an adjacency matrix approach.
 */

#include <stdio.h>
#include <stdlib.h>

// Defining constants
#define MAX_VERTICES 25

// Defining boolean data type
typedef enum { false, true } bool;

// Array to store vertices
char vertices[MAX_VERTICES];

// Adjacency matrix
int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// Number of vertices in the graph
int numVertices = 0;

// Function to add vertex to graph
void addVertex(char vertex) {
    if (numVertices == MAX_VERTICES) {
        printf("Maximum number of vertices reached\n");
        return;
    }
    vertices[numVertices] = vertex;
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[numVertices][i] = 0;
        adjMatrix[i][numVertices] = 0;
    }
    numVertices++;
}

// Function to add edge between two vertices
void addEdge(char start, char end) {
    int startIndex = -1, endIndex = -1;
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i] == start) {
            startIndex = i;
        }
        if (vertices[i] == end) {
            endIndex = i;
        }
    }
    if (startIndex == -1 || endIndex == -1) {
        printf("One or both vertices not found\n");
        return;
    }
    adjMatrix[startIndex][endIndex] = 1;
    adjMatrix[endIndex][startIndex] = 1;
}

// Function to display the graph
void displayGraph() {
    printf("   ");
    for (int i = 0; i < numVertices; i++) {
        printf("%c ", vertices[i]);
    }
    printf("\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%c| ", vertices[i]);
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Adding vertices to the graph
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');

    // Adding edges to the graph
    addEdge('A', 'B');
    addEdge('B', 'C');
    addEdge('C', 'D');
    addEdge('D', 'A');

    // Displaying the graph
    printf("The graph:\n\n");
    displayGraph();

    return 0;
}
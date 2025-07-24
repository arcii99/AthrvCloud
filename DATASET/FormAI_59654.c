//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int numOfColors;
//adjacency matrix
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
bool usedColors[MAX_VERTICES];

//function to get a new adjacent vertex
int getAdjacent(int vertex, int vertices[], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        j = vertices[i];
        if (adjacencyMatrix[vertex][j]) return j; 
    }
    return -1;
}

//function to check if a color can be used for a vertex
bool canColorBeUsed(int vertex, int color, int vertices[], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        j = vertices[i];
        if (adjacencyMatrix[vertex][j] && usedColors[j] == color) return false;
    }
    return true;
}

//function to print the coloring of vertices
void printColors(int vertexColors[]) {
    int i;
    printf("\nColors of vertices: ");
    for (i = 0; i < MAX_VERTICES; i++) {
        printf("%d ", vertexColors[i]);
    }
    printf("\n");
}

//function to color vertices recursively
bool colorVertices(int vertexColors[], int vertices[], int size) {
    int i, j, adjVertex, color;
    bool found;
    if (size == 0) return true; //we have colored all vertices
    int vertex = vertices[size - 1];
    for (color = 1; color <= numOfColors; color++) {
        found = true;
        //check if this color can be used for the vertex
        if (canColorBeUsed(vertex, color, vertices, size)) {
            //update usedColors for adjacent vertices
            for (adjVertex = getAdjacent(vertex, vertices, size); adjVertex != -1; adjVertex = getAdjacent(vertex, vertices, size)) {
                usedColors[adjVertex] = true;
            }
            //color the vertex with the selected color
            vertexColors[vertex] = color;
            //call recursively to color the other vertices
            if (colorVertices(vertexColors, vertices, size - 1)) {
                return true; //we are done!
            }
            //backtracking step
            vertexColors[vertex] = 0;
            for (adjVertex = getAdjacent(vertex, vertices, size); adjVertex != -1; adjVertex = getAdjacent(vertex, vertices, size)) {
                usedColors[adjVertex] = false;
            }

        }
    }
    return false; //can't color any vertices
}

int main() {
    int i, j, numOfEdges, vertex1, vertex2, vertexColors[MAX_VERTICES], vertices[MAX_VERTICES];
    for (i = 0; i < MAX_VERTICES; i++) {
        vertexColors[i] = 0;
        usedColors[i] = false;
        vertices[i] = i;
    }
    printf("Enter number of colors to use: ");
    scanf("%d", &numOfColors);
    printf("Enter number of edges: ");
    scanf("%d", &numOfEdges);
    printf("Enter edges (two vertices): \n");
    for (i = 0; i < numOfEdges; i++) {
        scanf("%d %d", &vertex1, &vertex2);
        adjacencyMatrix[vertex1][vertex2] = 1;
        adjacencyMatrix[vertex2][vertex1] = 1;
    }
    //color the vertices recursively
    if (colorVertices(vertexColors, vertices, MAX_VERTICES)) {
        //print the colors of the vertices
        printColors(vertexColors);
    } else {
        printf("Couldn't color the vertices with %d colors.\n", numOfColors);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Max number of vertices in the Graph
#define MAX_VERTICES 100

// Max number of colors that can be used for graph coloring
#define MAX_COLORS 10

// Struct to represent the Graph
typedef struct graph {
    int numVertices;
    int numEdges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Struct to represent the Color
typedef struct color {
    int value;
    int isUsed;
} Color;

/**
 * Function to initialize the Graph
 */
void initGraph(Graph *graph) {
    graph->numVertices = 0;
    graph->numEdges = 0;
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++){
        for (j = 0; j < MAX_VERTICES; j++){
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

/**
 * Function to add an Edge to the Graph
 */
void addEdge(Graph *graph, int startVertex, int endVertex) {
    graph->adjacencyMatrix[startVertex][endVertex] = 1;
    graph->adjacencyMatrix[endVertex][startVertex] = 1;
    graph->numEdges++;
}

/**
 * Function to check if the given Color is present in the List of Colors
 */
int colorExists(Color colors[], int numColors, int colorValue) {
    int i;
    for (i = 0; i < numColors; i++) {
        if (colors[i].value == colorValue && colors[i].isUsed == 0) {
            return 1;
        }
    }
    return 0;
}

/**
 * Function to get the available colors for a given Vertex of the Graph
 */
void getAvailableColors(Graph *graph, int vertex, Color availableColors[], int numAvailableColors) {
    int i, j, flag;
    for (i = 1; i <= numAvailableColors; i++) {
        flag = 1;
        for (j = 0; j < graph->numVertices; j++) {
            if (graph->adjacencyMatrix[vertex][j] == 1) {
                if (colorExists(availableColors, numAvailableColors, i) && availableColors[i-1].value == j) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            availableColors[i-1].value = i;
            availableColors[i-1].isUsed = 0;
        } else {
            availableColors[i-1].isUsed = 1;
        }
    }
}

/**
 * Function to color the Graph
 */
void colorGraph(Graph *graph, Color colors[], int numColors) {
    int i, j;
    for (i = 0; i < graph->numVertices; i++) {
        Color availableColors[numColors];
        for (j = 0; j < numColors; j++) {
            availableColors[j].value = 0;
            availableColors[j].isUsed = 0;
        }
        getAvailableColors(graph, i, availableColors, numColors);
        for (j = 0; j < numColors; j++) {
            if (availableColors[j].isUsed == 0) {
                colors[i].value = availableColors[j].value;
                colors[i].isUsed = 1;
                break;
            }
        }
    }
}

/**
 * Function to print the colored Graph
 */
void printColoredGraph(Graph *graph, Color colors[]) {
    int i, j;
    printf("Colored Graph:\n");
    for (i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d - Color %d\n", i, colors[i].value);
    }
}

int main() {
    // Initialize the Graph
    Graph graph;
    initGraph(&graph);

    // Add the Edges to the Graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    graph.numVertices = 5;

    // Define the Colors
    Color colors[MAX_COLORS];
    int i;
    for (i = 0; i < MAX_COLORS; i++) {
        colors[i].value = 0;
        colors[i].isUsed = 0;
    }

    // Color the Graph
    colorGraph(&graph, colors, 4);

    // Print the colored Graph
    printColoredGraph(&graph, colors);

    return 0;
}
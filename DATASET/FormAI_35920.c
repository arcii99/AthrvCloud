//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>

/* Define constant maximum number of nodes */
#define MAX_NODES 10

/* Function prototype for graph coloring algorithm */
void graphColoring(int nodes, int edges[MAX_NODES][MAX_NODES], int numColors);

int main() {
    /* Initialize the graph with edges and nodes */
    int numNodes = 5;
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };
    int numColors = 3;

    printf("Graph Coloring Problem\n\n");
    printf("The graph has %d nodes and %d colors must be used.\n\n", numNodes, numColors);
    printf("The graph is represented as an adjacency matrix:\n\n");

    /* Print graph matrix */
    for(int i = 0; i < numNodes; i++) {
        for(int j = 0; j < numNodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    /* Call graph coloring algorithm */
    graphColoring(numNodes, graph, numColors);

    return 0;
}

/* Graph coloring algorithm function */
void graphColoring(int nodes, int edges[MAX_NODES][MAX_NODES], int numColors) {
    /* Initialize color array with zeros */
    int colors[MAX_NODES] = {0};

    /* Assign first color to first node */
    colors[0] = 1;

    /* Iterate through remaining nodes */
    for(int i = 1; i < nodes; i++) {
        /* Check which colors are used by adjacent nodes */
        int usedColors[numColors+1];
        for(int j = 0; j < numColors+1; j++) {
            usedColors[j] = 0;
        }
        for(int j = 0; j < nodes; j++) {
            if(edges[i][j] == 1) {
                usedColors[colors[j]] = 1;
            }
        }

        /* Find the first unused color */
        int color;
        for(color = 1; color <= numColors; color++) {
            if(usedColors[color] == 0) {
                break;
            }
        }

        /* Assign the node the first unused color */
        colors[i] = color;
    }

    printf("\n\nThe graph can be colored using %d colors. ", numColors);
    printf("The nodes are colored as follows:\n\n");
    for(int i = 0; i < nodes; i++) {
        printf("Node %d: Color %d\n", i+1, colors[i]);
    }
}
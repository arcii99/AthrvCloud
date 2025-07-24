//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NODES 6    /* Total number of nodes in the graph */
#define COLORS 3   /* Total number of colors available */

/* Graph definition */
int Graph[NODES][NODES] = {
        {0,1,0,1,0,0},
        {1,0,1,0,1,1},
        {0,1,0,0,0,1},
        {1,0,0,0,1,0},
        {0,1,0,1,0,1},
        {0,1,1,0,1,0},
};

/* Colors of nodes */
int NodeColors[NODES] = {-1, -1, -1, -1, -1, -1};

/* Check if it is safe to assign a color to a node */
bool isSafe(int node, int color) {
    for(int i = 0; i < NODES; ++i) {
        /* If node is adjacent and has the same color, it is not safe */
        if(Graph[node][i] && color == NodeColors[i]) 
            return false;
    }
    return true;
}

/* Color the graph starting from a particular node */
bool colorGraph(int node) {
    if(node == NODES)
        return true;

    /* Try all colors for the current node */
    for(int c = 0; c < COLORS; ++c) {
        if(isSafe(node, c)) {
            NodeColors[node] = c;

            /* Recursively color the rest of the graph */
            if(colorGraph(node+1))
                return true;

            /* If the current color doesn't work, backtrack and try a different color */
            NodeColors[node] = -1;              
        }
    }
    /* If no color works, return false */
    return false;
}

int main() {
    /* Initialize colors to -1 */
    for(int i = 0; i < NODES; ++i)
        NodeColors[i] = -1;

    /* Color the graph starting from the first node */
    if(colorGraph(0)) {
        /* Print the color of each node */
        printf("Node Colors:\n");
        for(int i = 0; i < NODES; ++i)
            printf("Node%d - Color%d\n", i, NodeColors[i]);
    }
    else
        printf("Solution does not exist.\n");

    return 0;
}
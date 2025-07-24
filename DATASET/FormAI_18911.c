//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct {
    int nodes[MAX_NODES][MAX_NODES];
    int color[MAX_NODES];
    int numColors;
} Graph;

int isValid(Graph g, int nodeIndex, int colorIndex) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (g.nodes[nodeIndex][i] && colorIndex == g.color[i]) {
            return 0;
        }
    }
    return 1;
}

int colorGraphRecur(Graph g, int nodeIndex) {
    if (nodeIndex == MAX_NODES) {
        return 1;
    }

    for (int i = 0; i < g.numColors; i++) {
        if (isValid(g, nodeIndex, i)) {
            g.color[nodeIndex] = i;

            if (colorGraphRecur(g, nodeIndex + 1)) {
                return 1;
            }

            g.color[nodeIndex] = -1;
        }
    }

    return 0;
}

int colorGraph(Graph g) {
    for (int i = 0; i < MAX_NODES; i++) {
        g.color[i] = -1;
    }
    return colorGraphRecur(g, 0);
}

void printGraph(Graph g) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (g.color[i] == -1) {
            break;
        }
        printf("Node %d: Color %d\n", i, g.color[i]);
    }
}

int main() {
    Graph g = {{{0,1,1,1,0,0,0,0},{1,0,0,1,1,0,0,0},{1,0,0,1,0,1,1,0},{1,1,1,0,1,1,1,1},{0,1,0,1,0,0,0,0},{0,0,1,1,0,0,0,0},{0,0,1,1,0,0,0,1},{0,0,0,1,0,0,1,0}}, {-1,-1,-1,-1,-1,-1,-1,-1}, 3};
    if (colorGraph(g)) {
        printGraph(g);
    } else {
        printf("Unable to color graph with %d colors\n", g.numColors);
    }

    return 0;
}
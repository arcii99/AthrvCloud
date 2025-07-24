//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100

int nodeColors[MAX_NODES];

void setNodeColor(int node, int color) {
    nodeColors[node] = color;
}

bool canColorNodeWith(int node, int color, int graph[MAX_NODES][MAX_NODES], int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] && color == nodeColors[i]) {
            return false;
        }
    }
    return true;
}

void colorGraph(int graph[MAX_NODES][MAX_NODES], int numNodes) {
    for (int node = 0; node < numNodes; node++) {
        for (int color = 1; ; color++) {
            if (canColorNodeWith(node, color, graph, numNodes)) {
                setNodeColor(node, color);
                break;
            }
        }
    }
}

int main() {
    int numNodes = 5;
    int graph[MAX_NODES][MAX_NODES] = {{0, 1, 0, 1, 1},
                                       {1, 0, 1, 0, 1},
                                       {0, 1, 0, 1, 0},
                                       {1, 0, 1, 0, 1},
                                       {1, 1, 0, 1, 0}};

    colorGraph(graph, numNodes);

    printf("Node colors:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: Color %d\n", i, nodeColors[i]);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];
int num_nodes;

void paint(int node, int color) {
    colors[node] = color;
    int valid_color = 1;
    for (int i=0; i<num_nodes; i++) {
        if (graph[node][i] && colors[i] == color) {
            valid_color = 0;
            break;
        }
    }
    if (valid_color) {
        for (int i=1; i<=4; i++) {
            if (i != color) {
                paint(node+1, i);
            }
        }
    } else {
        paint(node, color+1);
    }
}

int main() {
    printf("Welcome to a unique Graph Coloring Problem example program!\n");
    printf("Please input the number of nodes in your graph (up to %d): ", MAX_NODES);
    scanf("%d", &num_nodes);
    printf("Please enter the adjacency matrix:\n");
    for (int i=0; i<num_nodes; i++) {
        for (int j=0; j<num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Solving...\n");
    paint(0, 1);
    printf("Solution found!\n");
    printf("The colors for each node are:\n");
    for (int i=0; i<num_nodes; i++) {
        printf("Node %d: Color %d\n", i, colors[i]);
    }
    printf("Thanks for using our program!\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODE 10

bool is_safe(int node, int color, bool graph[MAX_NODE][MAX_NODE], int colors[MAX_NODE]) {
    for (int i = 0; i < MAX_NODE; i++) {
        if (graph[node][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(int node, int max_color, bool graph[MAX_NODE][MAX_NODE], int colors[MAX_NODE]) {
    if (node == MAX_NODE) {
        for (int i = 0; i < MAX_NODE; i++) {
            printf("Node %d is colored %d\n", i, colors[i]);
        }
        return true;
    }

    for (int i = 0; i < max_color; i++) {
        if (is_safe(node, i, graph, colors)) {
            colors[node] = i;
            if (graph_coloring(node + 1, max_color, graph, colors)) {
                return true;
            }
            colors[node] = -1;
        }
    }

    return false;
}

int main() {
    bool graph[MAX_NODE][MAX_NODE] = {
        // Node 0 1 2 3 4 5 6 7 8 9
            {0,1,1,1,0,0,0,0,0,0}, //0
            {1,0,0,0,1,1,0,0,0,0}, //1
            {1,0,0,0,0,0,1,1,0,0}, //2
            {1,0,0,0,0,0,0,1,0,0}, //3
            {0,1,0,0,0,0,0,0,0,0}, //4
            {0,1,0,0,0,0,0,0,0,0}, //5
            {0,0,1,0,0,0,0,0,0,0}, //6
            {0,0,1,1,0,0,0,0,0,0}, //7
            {0,0,0,0,0,0,0,0,0,1}, //8
            {0,0,0,0,0,0,0,0,1,0}  //9
        };
        
    int colors[MAX_NODE];
    for (int i = 0; i < MAX_NODE; i++) {
        colors[i] = -1;
    }

    int max_color;
    printf("Enter maximum number of colors: ");
    scanf("%d", &max_color);

    if (graph_coloring(0, max_color, graph, colors)) {
        printf("Graph can be colored using %d colors.\n", max_color);
    } else {
        printf("Graph cannot be colored using %d colors.\n", max_color);
    }

    return 0;
}
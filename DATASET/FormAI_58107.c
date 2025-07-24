//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>

#define MAX_NODES 5
#define MAX_COLORS 3

int graph[MAX_NODES][MAX_NODES] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {0, 1, 0, 1, 0}
};

int colors[MAX_NODES];

void print_colors() {
    printf("Node Colors:\n");
    
    for (int i = 0; i < MAX_NODES; i++) {
        printf("%d -> Color %d\n", i, colors[i]);
    }
}

int is_safe(int node, int color) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[node][i] == 1 && color == colors[i]) {
            return 0;
        }
    }
    
    return 1;
}

int graph_color(int node) {
    if (node == MAX_NODES) {
        return 1;
    }
    
    for (int color = 1; color <= MAX_COLORS; color++) {
        if (is_safe(node, color)) {
            colors[node] = color;
            
            if (graph_color(node + 1)) {
                return 1;
            }
            
            colors[node] = 0;
        }
    }
    
    return 0;
}

int main() {
    if (graph_color(0)) {
        printf("Solution Found:\n");
        print_colors();
    } else {
        printf("No Solution Found\n");
    }
    
    return 0;
}
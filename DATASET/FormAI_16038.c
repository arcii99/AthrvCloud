//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

bool is_safe(int vertex, int color, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && color == colors[i]) {
            return false;
        }
    }
    return true;
}

bool graph_color(int vertex, int num_vertices, int num_colors) {
    if (vertex == num_vertices) {
        return true;
    }
    for (int color = 1; color <= num_colors; color++) {
        if (is_safe(vertex, color, num_vertices)) {
            colors[vertex] = color;
            if (graph_color(vertex + 1, num_vertices, num_colors)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

int main() {
    // initialize graph here...
    
    int num_vertices = 10;
    int num_colors   = 4;
    
    if (graph_color(0, num_vertices, num_colors)) {
        printf("Solution found!\n");
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}
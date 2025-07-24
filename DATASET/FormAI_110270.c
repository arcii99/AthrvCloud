//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdbool.h>

// Define the maximum number of vertices
#define MAX_VERTICES 100

// Define the graph structure
typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
    int num_edges;
} graph;

// Define the colors for the vertices
typedef enum {
   RED = 1,
   BLUE,
   GREEN
} color;

// Define the function to check if a color is valid for a vertex
bool is_valid_color(graph *g, int vertex, color c) {
    int i;
    for (i = 0; i < g->num_vertices; i++) {
        if (g->vertices[vertex][i] && c == g->vertices[i][i]) {
            return false;
        }
    }
    return true;
}

// Define the function to print the colors of each vertex
void print_colors(color *colors, int num_vertices) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d: ", i+1);
        switch(colors[i]) {
            case RED:
                printf("Red\n");
                break;
            case BLUE:
                printf("Blue\n");
                break;
            case GREEN:
                printf("Green\n");
                break;
            default:
                printf("Undefined color\n");
                break;
        }
    }
}

// Define the function to solve the graph coloring problem
bool graph_color(graph *g, color *colors, int vertex) {
    int i;
    if (vertex == g->num_vertices) {
        return true;
    }
    for (i = 1; i <= 3; i++) {
        if(is_valid_color(g, vertex, i)) {
            colors[vertex] = i;
            if(graph_color(g, colors, vertex+1)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

int main() {
    // Create a new graph
    graph g;
    g.num_vertices = 6;
    g.num_edges = 7;
    g.vertices[0][2] = 1;
    g.vertices[1][2] = 1;
    g.vertices[2][0] = 1;
    g.vertices[2][1] = 1;
    g.vertices[2][3] = 1;
    g.vertices[3][2] = 1;
    g.vertices[3][4] = 1;
    g.vertices[3][5] = 1;
    g.vertices[4][3] = 1;
    g.vertices[5][3] = 1;

    // Create an array of colors for the vertices
    color colors[MAX_VERTICES] = {0};
    
    // Solve the graph coloring problem
    if(graph_color(&g, colors, 0)) {
        printf("Graph can be colored with the following colors:\n");
        print_colors(colors, g.num_vertices);
    } else {
        printf("Graph cannot be colored with three colors\n");
    }

    return 0;
}
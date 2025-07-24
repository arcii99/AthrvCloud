//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Define constants */
#define MAX_VERTICES 5
#define MAX_COLORS 3

/* Define struct for graph */
struct graph {
    int vertices[MAX_VERTICES][MAX_COLORS];
    int edges[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
    int num_edges;
};

/* Function to initialize graph */
void initialize_graph(struct graph *g) {
    /* Set number of vertices and edges */
    g->num_vertices = MAX_VERTICES;
    g->num_edges = 0;
    
    /* Set all vertices to -1, indicating no color has been assigned */
    for(int i = 0; i < g->num_vertices; i++) {
        for(int j = 0; j < MAX_COLORS; j++) {
            g->vertices[i][j] = -1;
        }
    }
    
    /* Set all edges to 0, indicating no edges exist between vertices */
    for(int i = 0; i < g->num_vertices; i++) {
        for(int j = 0; j < g->num_vertices; j++) {
            g->edges[i][j] = 0;
        }
    }
}

/* Function to add an edge between two vertices */
void add_edge(struct graph *g, int v1, int v2) {
    g->edges[v1][v2] = 1;
    g->edges[v2][v1] = 1;
    g->num_edges++;
}

/* Function to check if a vertex can be assigned a certain color */
bool can_color_vertex(struct graph *g, int v, int color) {
    /* Check if any adjacent vertices have already been assigned the same color */
    for(int i = 0; i < g->num_vertices; i++) {
        if(g->edges[v][i] == 1 && g->vertices[i][color] != -1) {
            return false;
        }
    }
    return true;
}

/* Function to color a vertex with a given color */
void color_vertex(struct graph *g, int v, int color) {
    /* Loop through all colors and set vertex to given color */
    for(int i = 0; i < MAX_COLORS; i++) {
        if(i == color) {
            g->vertices[v][i] = 1;
        }
        else {
            g->vertices[v][i] = 0;
        }
    }
}

/* Function to find the next uncolored vertex */
int find_next_vertex(struct graph *g) {
    /* Loop through all vertices */
    for(int i = 0; i < g->num_vertices; i++) {
        bool is_colored = true;
        /* Check if vertex is already colored */
        for(int j = 0; j < MAX_COLORS; j++) {
            if(g->vertices[i][j] == -1) {
                is_colored = false;
                break;
            }
        }
        /* If vertex is uncolored, return its index */
        if(!is_colored) {
            return i;
        }
    }
    /* If all vertices are colored, return -1 */
    return -1;
}

/* Function to perform graph coloring */
void color_graph(struct graph *g) {
    int vertex_to_color = find_next_vertex(g);
    /* Loop through all vertices */
    while(vertex_to_color != -1) {
        /* Loop through all colors */
        for(int i = 0; i < MAX_COLORS; i++) {
            /* Check if vertex can be colored with this color */
            if(can_color_vertex(g, vertex_to_color, i)) {
                color_vertex(g, vertex_to_color, i);
                break;
            }
        }
        /* Move on to the next uncolored vertex */
        vertex_to_color = find_next_vertex(g);
    }
}

int main() {
    /* Create graph */
    struct graph g;
    initialize_graph(&g);
    
    /* Add edges */
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);
    
    /* Perform graph coloring */
    color_graph(&g);
    
    /* Print results */
    printf("Vertex Colors:\n");
    for(int i = 0; i < g.num_vertices; i++) {
        printf("Vertex %d: ", i);
        for(int j = 0; j < MAX_COLORS; j++) {
            if(g.vertices[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    
    return 0;
}
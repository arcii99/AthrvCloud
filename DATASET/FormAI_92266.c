//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 128
#define MAX_COLORS 16
#define MAX_EDGES 1024

// Cyberpunk-style graph data structure
typedef struct {
    int vertices[MAX_VERTICES];
    int colors[MAX_COLORS];
    int edges[MAX_EDGES];
    int num_vertices;
    int num_colors;
    int num_edges;
} CyberGraph;

// Initialize a graph with random vertices, colors, and edges
void init_cybergraph(CyberGraph* g) {
    int i, j, k;

    srand((unsigned) time(NULL));
    
    g->num_vertices = rand() % MAX_VERTICES + 1;
    g->num_colors = rand() % MAX_COLORS + 1;
    g->num_edges = rand() % MAX_EDGES + 1;

    for (i = 0; i < g->num_vertices; i++) {
        g->vertices[i] = i;
    }

    for (i = 0; i < g->num_colors; i++) {
        g->colors[i] = rand() % 0xFFFFFF;
    }

    for (i = 0; i < g->num_edges; i++) {
        j = rand() % g->num_vertices;
        k = rand() % g->num_vertices;

        if (j == k) {
            k = (k + 1) % g->num_vertices;
        }

        g->edges[i] = ((j << 8) | k);
    }
}

// Get the vertex degrees of a graph
void get_degrees(CyberGraph* g, int* degrees) {
    int i, j, k;

    for (i = 0; i < g->num_vertices; i++) {
        degrees[i] = 0;

        for (j = 0; j < g->num_edges; j++) {
            k = g->edges[j];

            if (((k >> 8) == i) || ((k & 0xFF) == i)) {
                degrees[i]++;
            }
        }
    }
}

// Try to color a graph using a greedy algorithm
void color_cybergraph(CyberGraph* g) {
    int i, j, k, l;

    int degrees[MAX_VERTICES];
    int colors[MAX_VERTICES];
    int used_colors[MAX_COLORS];
    int color_degrees[MAX_COLORS];

    get_degrees(g, degrees);
    
    // Sort vertices by degree (descending order)
    for (i = 0; i < g->num_vertices; i++) {
        for (j = i + 1; j < g->num_vertices; j++) {
            if (degrees[j] > degrees[i]) {
                k = degrees[i];
                degrees[i] = degrees[j];
                degrees[j] = k;

                k = g->vertices[i];
                g->vertices[i] = g->vertices[j];
                g->vertices[j] = k;
            }
        }
    }

    // Initialize all colors to -1 (unassigned)
    for (i = 0; i < g->num_vertices; i++) {
        colors[i] = -1;
    }

    // Assign colors to the vertices
    for (i = 0; i < g->num_vertices; i++) {
        // Reset used colors
        for (j = 0; j < g->num_colors; j++) {
            used_colors[j] = 0;
        }

        // Get the neighbors of the current vertex
        for (j = 0; j < g->num_edges; j++) {
            k = g->edges[j];

            if ((k >> 8) == g->vertices[i]) {
                if (colors[k & 0xFF] >= 0) { // neighbor has a color already
                    used_colors[colors[k & 0xFF]] = 1; // mark the color as used
                }
            } else if ((k & 0xFF) == g->vertices[i]) {
                if (colors[k >> 8] >= 0) { // neighbor has a color already
                    used_colors[colors[k >> 8]] = 1; // mark the color as used
                }
            }
        }

        // Find the first available color
        for (j = 0; j < g->num_colors; j++) {
            if (!used_colors[j]) {
                colors[g->vertices[i]] = j;
                break;
            }
        }
    }

    // Print the coloring result
    for (i = 0; i < g->num_vertices; i++) {
        printf("(Vertex %d: color 0x%06X)\n", g->vertices[i], g->colors[colors[g->vertices[i]]]);
    }
}

// Entry point
int main() {
    CyberGraph g;

    // Initialize the graph
    init_cybergraph(&g);

    // Color the graph
    printf("Coloring the cybergraph...\n");
    color_cybergraph(&g);

    return 0;
}
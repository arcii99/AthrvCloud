//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20
#define MAX_COLORS 5

typedef struct Edge
{
    int start;
    int end;
} Edge;

// Function to randomly generate edges between vertices
void generateEdges(Edge edges[MAX_EDGES]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_EDGES; i++) {
        edges[i].start = rand() % MAX_VERTICES;
        edges[i].end = rand() % MAX_VERTICES;
    }
}

// Function to print the edges
void printEdges(Edge edges[MAX_EDGES]) {
    printf("Edges:\n");
    for (int i = 0; i < MAX_EDGES; i++) {
        printf("%d--%d\n", edges[i].start, edges[i].end);
    }
}

// Function to color the graph
void colorGraph(int graph[MAX_VERTICES][MAX_VERTICES], int colors[MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        int used_colors[MAX_COLORS] = {0};
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (graph[i][j] && colors[j] != -1) {
                used_colors[colors[j]] = 1;
            }
        }
        int color = rand() % MAX_COLORS;
        while (used_colors[color]) {
            color = rand() % MAX_COLORS;
        }
        colors[i] = color;
    }
}

// Function to print the colored graph
void printColoredGraph(int graph[MAX_VERTICES][MAX_VERTICES], int colors[MAX_VERTICES]) {
    char color_codes[MAX_COLORS][10] = {"RED", "GREEN", "BLUE", "YELLOW", "ORANGE"};
    printf("Colored Graph:\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("Vertex %d: %s\n", i, color_codes[colors[i]]);
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (graph[i][j]) {
                printf("\t%d--%d\n", i, j);
            }
        }
    }
}

int main() {
    Edge edges[MAX_EDGES];
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int colors[MAX_VERTICES] = {-1};
    
    // Generating random edges for the graph
    generateEdges(edges);
    
    // Adding edges to the graph
    for (int i = 0; i < MAX_EDGES; i++) {
        graph[edges[i].start][edges[i].end] = 1;
        graph[edges[i].end][edges[i].start] = 1;
    }
    
    // Printing the edges
    printEdges(edges);
    
    // Coloring the graph
    colorGraph(graph, colors);
    
    // Printing the colored graph
    printColoredGraph(graph, colors);
    
    return 0;
}
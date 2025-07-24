//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 20
#define MAX_EDGES 50

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

int vertex_colors[MAX_VERTICES];

int num_of_vertices, num_of_edges, max_colors = 0;

void generate_random_graph() {
    srand(time(NULL));
    num_of_vertices = rand() % MAX_VERTICES + 1;
    num_of_edges = rand() % (num_of_vertices * (num_of_vertices - 1) / 2 + 1);
    printf("Generating a random graph with %d vertices and %d edges...\n", num_of_vertices, num_of_edges);
    for (int i = 0; i < num_of_vertices; i++) {
        for (int j = 0; j < num_of_vertices; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < num_of_edges; i++) {
        int u = rand() % num_of_vertices;
        int v = rand() % num_of_vertices;
        while (u == v || adjacency_matrix[u][v] == 1) {
            u = rand() % num_of_vertices;
            v = rand() % num_of_vertices;
        }
        adjacency_matrix[u][v] = 1;
        adjacency_matrix[v][u] = 1;
    }
}

void print_graph() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < num_of_vertices; i++) {
        printf("|");
        for (int j = 0; j < num_of_vertices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("|\n");
    }
}

int get_num_of_colors() {
    for (int i = 0; i < num_of_vertices; i++) {
        vertex_colors[i] = 0;
    }
    for (int i = 0; i < num_of_vertices; i++) {
        int available_colors[max_colors + 1];
        for (int j = 1; j <= max_colors; j++) {
            available_colors[j] = 1;
        }
        for (int j = 0; j < num_of_vertices; j++) {
            if (adjacency_matrix[i][j] && vertex_colors[j] != 0) {
                available_colors[vertex_colors[j]] = 0;
            }
        }
        for (int j = 1; j <= max_colors; j++) {
            if (available_colors[j]) {
                vertex_colors[i] = j;
                break;
            }
        }
        if (vertex_colors[i] == 0) {
            vertex_colors[i] = max_colors + 1;
            max_colors++;
        }
    }
    return max_colors;
}

void print_coloring() {
    printf("Vertex Colors:\n");
    for (int i = 0; i < num_of_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, vertex_colors[i]);
    }
}

int main() {
    generate_random_graph();
    print_graph();
    printf("Calculating the minimum number of colors needed to color the graph...\n");
    printf("The minimum number of colors needed is %d.\n", get_num_of_colors());
    print_coloring();
    return 0;
}
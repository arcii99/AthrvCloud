//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>

#define MAX_NODES 10
#define MAX_COLORS 3

int adj_matrix[MAX_NODES][MAX_NODES] = {{0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                                        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                                        {1, 1, 0, 1, 0, 1, 0, 0, 0, 0},
                                        {1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                                        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
                                        {0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                                        {0, 0, 0, 1, 0, 1, 0, 0, 1, 1},
                                        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                                        {0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
                                        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}};

int color[MAX_NODES];

void print_colors() {
    printf("The colors of the graph are: ");
    for (int i = 0; i < MAX_NODES; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int is_valid_color(int node, int c) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (adj_matrix[node][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(int node) {
    if (node == MAX_NODES) {
        return 1;
    }
    for (int i = 1; i <= MAX_COLORS; i++) {
        if (is_valid_color(node, i)) {
            color[node] = i;
            if (graph_coloring(node + 1)) {
                return 1;
            }
            color[node] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Welcome to my cheerful graph coloring program!\n");
    printf("The goal of this program is to color the following graph with three colors:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    printf("Let's get started!\n");

    if (graph_coloring(0)) {
        print_colors();
    } else {
        printf("Oops! It seems that we cannot color the graph with three colors.\n");
    }

    printf("Thank you for using my cheerful graph coloring program!\n");
    return 0;
}
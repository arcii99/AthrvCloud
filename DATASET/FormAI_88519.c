//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>

#define MAX_VERTICES 10

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

void add_edge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

void print_graph() {
    printf("  ");
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%d ", i);
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    // populate graph with edges
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(1, 2);
    add_edge(1, 4);
    add_edge(2, 5);
    add_edge(3, 4);
    add_edge(4, 5);
    add_edge(4, 6);
    add_edge(5, 7);
    add_edge(6, 7);
    add_edge(8, 9);

    // print graph
    printf("Here is a unique graph representation using C language:\n");
    print_graph();

    return 0;
}
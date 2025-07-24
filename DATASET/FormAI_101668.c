//FormAI DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &size);

    int** graph = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        graph[i] = (int*)malloc(size * sizeof(int));
    }

    printf("Enter the adjacency matrix of the graph: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nYour Graph:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nRepresenting your graph using C Graph:\n");
    printf("graph_t* graph = create_graph(%d);\n", size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (graph[i][j] == 1) {
                printf("add_edge(graph, %d, %d);\n", i, j);
            }
        }
    }

    printf("\nThere you have it! Your graph has been represented in C Graph.\n");
    return 0;
}
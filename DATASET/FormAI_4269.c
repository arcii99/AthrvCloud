//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NODES 5

int graph[NODES][NODES] = {{0, 1, 1, 0, 0},
                           {1, 0, 1, 1, 0},
                           {1, 1, 0, 0, 1},
                           {0, 1, 0, 0, 1},
                           {0, 0, 1, 1, 0}};

void *print_graph(void *arg) {
    int node = *(int *) arg;
    printf("Node %d is connected to: ", node);
    for (int i = 0; i < NODES; i++) {
        if (graph[node][i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NODES];
    void *status;

    int node_nums[NODES] = {0, 1, 2, 3, 4};

    printf("Graph representation:\n");
    for (int i = 0; i < NODES; i++) {
        for (int j = 0; j < NODES; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nConnections/mappings between nodes:\n");
    for (int i = 0; i < NODES; i++) {
        pthread_create(&threads[i], NULL, print_graph, (void *) &node_nums[i]);
    }

    for (int i = 0; i < NODES; i++) {
        pthread_join(threads[i], &status);
    }

    printf("\nDone.\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#define V 5

int graphRepresentation[V][V] = {{0, 1, 0, 1, 1},
                                 {1, 0, 1, 0, 1},
                                 {0, 1, 0, 1, 0},
                                 {1, 0, 1, 0, 1},
                                 {1, 1, 0, 1, 0}};

void printGraph() {
    printf("\n Graph Representation: \n");

    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            printf("%d ", graphRepresentation[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printGraph();
    return 0;
}
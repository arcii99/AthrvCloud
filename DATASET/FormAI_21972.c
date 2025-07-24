//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERTEX 5

int main() {
    srand(time(0));
    int edges[VERTEX][VERTEX] = {0};
    int i, j, weight;
    printf("The adjacency matrix representation of the graph is:\n");
    printf("   ");
    for(i=0; i<VERTEX; i++)
        printf("%d  ", i+1);
    printf("\n");
    for(i=0; i<VERTEX; i++) {
        printf("%d  ", i+1);
        for(j=0; j<VERTEX; j++) {
            if(edges[i][j] == 0 && i != j) {
                weight = rand() % 10;
                edges[i][j] = weight;
                edges[j][i] = weight;
            }
            printf("%d  ", edges[i][j]);
        }
        printf("\n");
    }
    return 0;
}
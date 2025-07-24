//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>

int main() {
    printf("Oh boy, am I excited to show you my graph representation code!\n");
    printf("Just wait until you see how elegantly I have represented the vertices and edges.\n");

    int num_vertices = 5;
    int num_edges = 7;
    int graph[num_vertices][num_edges];

    printf("Now, let me quickly fill up my graph with some data.\n");

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_edges; j++) {
            if ((j == 1 && i == 0) || (j == 2 && i == 1) || (j == 4 && i == 2) ||
                (j == 5 && i == 2) || (j == 3 && i == 3) || (j == 1 && i == 4) ||
                 (j == 6 && i == 4)) {
                graph[i][j] = 1;
            }
            else {
                graph[i][j] = 0;
            }
        }
    }

    printf("Wow, look at that gorgeous graph! I'm so proud of my creation.\n");
    printf("  0 1 2 3 4 5 6\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", i);
        for (int j = 0; j < num_edges; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("I hope you enjoyed my graph representation code as much as I did writing it!\n");

    return 0;
}
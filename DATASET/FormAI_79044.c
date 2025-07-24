//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>

/* This program generates a unique C Graph representation using an array and nested loops */

int main() {

    int graph[5][5] = {{0, 1, 1, 0, 0},
                       {1, 0, 1, 1, 1},
                       {1, 1, 0, 1, 0},
                       {0, 1, 1, 0, 1},
                       {0, 1, 0, 1, 0}};

    printf("     [A]\n");
    printf("      |\n");
    printf("[B]---[C]---[D]\n");
    printf(" |     |\n");
    printf(" -----[E]\n");

    return 0;
}
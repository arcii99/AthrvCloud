//FormAI DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>

int main() {
    int graph[5][5] = {{0, 1, 1, 0, 1},
                       {1, 0, 1, 1, 0},
                       {1, 1, 0, 1, 0},
                       {0, 1, 1, 0, 1},
                       {1, 0, 0, 1, 0}};
    printf("  a b c d e\n");
    printf("a %d %d %d %d %d\n", graph[0][0], graph[0][1], graph[0][2], graph[0][3], graph[0][4]);
    printf("b %d %d %d %d %d\n", graph[1][0], graph[1][1], graph[1][2], graph[1][3], graph[1][4]);
    printf("c %d %d %d %d %d\n", graph[2][0], graph[2][1], graph[2][2], graph[2][3], graph[2][4]);
    printf("d %d %d %d %d %d\n", graph[3][0], graph[3][1], graph[3][2], graph[3][3], graph[3][4]);
    printf("e %d %d %d %d %d\n", graph[4][0], graph[4][1], graph[4][2], graph[4][3], graph[4][4]);
    return 0;
}
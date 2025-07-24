//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define ROWS 7
#define COLUMNS 7

/**
 * This program represents a graph using a 2D array (matrix) of integers.
 * The integers represent the edges between nodes.
 * This is an undirected graph, meaning the edges are bidirectional.
 * 
 * Let's represent the graph using the following nodes:
 * 0 -> A
 * 1 -> B
 * 2 -> C
 * 3 -> D
 * 4 -> E
 * 5 -> F
 * 6 -> G
*/

int graph[ROWS][COLUMNS] = { { 0, 1, 1, 0, 0, 0, 0 },
                             { 1, 0, 0, 1, 0, 0, 0 },
                             { 1, 0, 0, 1, 1, 0, 0 },
                             { 0, 1, 1, 0, 1, 1, 0 },
                             { 0, 0, 1, 1, 0, 0, 1 },
                             { 0, 0, 0, 1, 0, 0, 1 },
                             { 0, 0, 0, 0, 1, 1, 0 } };

/**
 * Print the graph in matrix form
 */
void print_graph() {
    printf("Graph representation:\n");
    printf("    A  B  C  D  E  F  G\n");
    printf("------------------------\n");
    for (int i = 0; i < ROWS; i++) {
        switch(i) {
            case 0: printf("A | "); break;
            case 1: printf("B | "); break;
            case 2: printf("C | "); break;
            case 3: printf("D | "); break;
            case 4: printf("E | "); break;
            case 5: printf("F | "); break;
            case 6: printf("G | "); break;
            default: break;
        }
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    print_graph();
    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

int main() {

    Graph puzzle_graph;
    puzzle_graph.num_vertices = 5;

    // let's create an unconventional graph

    puzzle_graph.adj_matrix[0][1] = 1;
    puzzle_graph.adj_matrix[0][3] = 1;

    puzzle_graph.adj_matrix[1][0] = 1;
    puzzle_graph.adj_matrix[1][2] = 1;
    puzzle_graph.adj_matrix[1][4] = 1;

    puzzle_graph.adj_matrix[2][1] = 1;
    puzzle_graph.adj_matrix[2][3] = 1;

    puzzle_graph.adj_matrix[3][0] = 1;
    puzzle_graph.adj_matrix[3][2] = 1;
    puzzle_graph.adj_matrix[3][4] = 1;

    puzzle_graph.adj_matrix[4][1] = 1;
    puzzle_graph.adj_matrix[4][3] = 1;

    // now let's print the graph

    printf("  _____ _ \n");
    printf(" |  ___(_) __ _ _ __   __ _ _ __ ___   __ _ _ __ \n");
    printf(" | |_  | |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf(" |  _| | | (_| | | | | (_| | | | | | | (_| | | | |\n");
    printf(" |_|   |_|\\__, |_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n");
    printf("          |___/       |___/                       \n");

    printf("\nThis graph has %d vertices\n", puzzle_graph.num_vertices);

    int i, j;
    for(i=0; i<puzzle_graph.num_vertices; i++) {
        printf("\nVertex [%d] is connected to:", i+1);
        for(j=0; j<puzzle_graph.num_vertices; j++) {
            if(puzzle_graph.adj_matrix[i][j] == 1) {
                printf(" %d", j+1);
            }
        }
    }

    printf("\n\nCan you solve this puzzling graph?\n");

    return 0;
}
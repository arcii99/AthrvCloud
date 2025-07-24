//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10

/* Helper function to check if a color can be assigned to a node */
bool is_color_valid(int graph[MAX_NODES][MAX_NODES], int node, int color, int colors[])
{
    for (int i = 0; i < MAX_NODES; i++) {
        /* Check if the adjacent node has the same color */
        if (graph[node][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

/* Recursive function to solve graph coloring problem */
bool solve_coloring(int graph[MAX_NODES][MAX_NODES], int node, int colors[], int num_colors)
{
    /* Base case when all nodes are colored */
    if (node == MAX_NODES) {
        printf("Node colors: [ ");
        for (int i = 0; i < MAX_NODES; i++) {
            printf("%d ", colors[i]);
        }
        printf("]\n");
        return true;
    }

    /* Try assigning each color to the current node */
    for (int i = 1; i <= num_colors; i++) {
        if (is_color_valid(graph, node, i, colors)) {
            colors[node] = i;
            if (solve_coloring(graph, node + 1, colors, num_colors)) {
                return true;
            }
            /* Backtrack if the current color doesn't work */
            colors[node] = 0;
        }
    }

    /* If no color can be assigned to the current node */
    return false;
}

int main()
{
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},    /* Node 0 is adjacent to node 1 and 3 */
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},    /* Node 1 is adjacent to nodes 0, 2, and 4 */
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},    /* Node 2 is adjacent to nodes 1 and 3 and 5 */
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 0},    /* Node 3 is adjacent to nodes 0, 2, 4 and 6 */
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},    /* Node 4 is adjacent to nodes 1, 3, 5 and 7 */
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},    /* Node 5 is adjacent to nodes 2, 4, and 8 */
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},    /* Node 6 is adjacent to nodes 3, 7, and 9 */
        {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},    /* Node 7 is adjacent to nodes 4, 6, and 8 */
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},    /* Node 8 is adjacent to nodes 5, 7, and 9 */
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}     /* Node 9 is adjacent to nodes 6 and 8 */
    };

    int colors[MAX_NODES] = {0};   /* Initialize all node colors to 0 */
    int num_colors = 3;             /* Set the number of colors to use */

    if (!solve_coloring(graph, 0, colors, num_colors)) {
        printf("No valid coloring found!\n");
    }

    return 0;
}
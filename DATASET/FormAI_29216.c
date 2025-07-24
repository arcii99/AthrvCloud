//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include<stdio.h>
#include<stdlib.h>

int graph[20][20], nodeColors[20], n;

void colorGraph(int node, int numColors) {
    int color;
    if (node == n) { // Base case: All nodes are colored
        for (int i = 1; i <= n; i++) {
            printf("Node %d: Color %d\n", i, nodeColors[i]);
        }
        exit(0);
    } else {
        for (color = 1; color <= numColors; color++) {
            int validColor = 1;
            for (int i = 1; i <= n; i++) { // Check if the selected color is valid
                if (graph[node][i] && nodeColors[i] == color) {
                    validColor = 0;
                    break;
                }
            }
            if (validColor) {
                nodeColors[node+1] = color; // Assign color to the current node
                colorGraph(node+1, numColors); // Recursively color the next node
                nodeColors[node+1] = 0; // Backtrack and undo the assigned color
            }
        }
    }
}

int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix of the graph (%d x %d):\n", n, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nEnter the number of colors available: ");
    int numColors;
    scanf("%d", &numColors);
    printf("\nColoring the graph using %d colors...\n\n", numColors);
    colorGraph(0, numColors);
    printf("\nCould not find a valid color scheme.");
    return 0;
}
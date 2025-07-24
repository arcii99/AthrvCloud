//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>

// Graph Coloring function
void colorGraph(int n, int graph[n][n], int colors[]) {
    int i, j, assigned;

    // Assign the first color to the first node
    colors[0]=1;

    // Assign colors to the remaining n-1 nodes
    for (i=1; i<n; i++) {
        // Initialize assigned variable to false
        assigned=0;

        // Loop through the previous nodes
        for (j=0; j<i; j++) {
            // If the current node can be colored with the jth color
            if (graph[i][j] && colors[j]==colors[i]) {
                // Assign a new color to the current node
                colors[i]=colors[j]+1;
                assigned=1;
                break;
            }
        }
        // Assign the first color to the current node, if it has not already been assigned
        if (!assigned)
            colors[i]=1;
    }
}

// Main function
int main() {
    int n, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int colors[n];

    printf("Enter the adjacency matrix: \n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d", &graph[i][j]);

    colorGraph(n, graph, colors);

    // Print the assigned colors of each node
    printf("The assigned colors are: \n");
    for (i=0; i<n; i++)
        printf("Node %d: Color %d\n", i+1, colors[i]);

    return 0;
}
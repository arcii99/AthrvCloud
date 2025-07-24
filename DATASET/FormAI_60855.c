//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>

int main() {
    int num_nodes, num_edges;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);
    int adj_matrix[num_nodes][num_nodes];
    for(int i = 0; i < num_nodes; i++) {
        for(int j = 0; j < num_nodes; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    printf("Enter the edges: (source, destination)\n");
    for(int i = 0; i < num_edges; i++) {
        int source, destination;
        printf("Edge %d: ", i+1);
        scanf("%d %d", &source, &destination);
        adj_matrix[source][destination] = 1;
        adj_matrix[destination][source] = 1;
    }
    printf("The adjacency matrix representation of the graph is:\n");
    printf("   ");
    for(int i = 0; i < num_nodes; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < num_nodes; i++) {
        printf("%d: ", i);
        for(int j = 0; j < num_nodes; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
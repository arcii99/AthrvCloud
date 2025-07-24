//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>

#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];

int main() {
    int nodes,edges;
    printf("Enter the number of nodes: ");
    scanf("%d",&nodes);
    printf("Enter the number of edges: ");
    scanf("%d",&edges);
    int i,j;
    int u,v;
    printf("Enter the connections (u, v) between nodes:\n");
    for (i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    printf("The network topology is:\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
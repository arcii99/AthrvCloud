//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct {
    int source;
    int target;
} Edge;

int numNodes, numEdges, src, target;
Edge edges[MAX_NODES];
bool visited[MAX_NODES];

void dfs(int node) {
    visited[node] = true;
    printf("%d ", node);
    for (int i = 0; i < numEdges; i++) {
        Edge edge = edges[i];
        if (edge.source == node && !visited[edge.target]) {
            dfs(edge.target);
        }
    }
}

void classicalCircuitSimulator() {
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    
    printf("Enter the edges:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d%d", &src, &target);
        edges[i].source = src;
        edges[i].target = target;
    }
    
    printf("Starting node: ");
    scanf("%d", &src);
    
    printf("DFS Traversal starting from node %d: ", src);
    dfs(src);
}

int main() {
    classicalCircuitSimulator();
    return 0;
}
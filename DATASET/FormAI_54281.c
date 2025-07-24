//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES] = {0};
int visited[MAX_NODES] = {0};

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for(int i=0; i<MAX_NODES; i++) {
        if(graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    int num_nodes;
    scanf("%d", &num_nodes);

    printf("Enter the edges in the format (u v):\n");
    int u, v;
    while(scanf("%d %d", &u, &v) == 2) {
        add_edge(u, v);
    }

    printf("The network topology map is:\n");
    for(int i=0; i<num_nodes; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 1500
#define INF 1000000000

int n, m; // number of nodes and edges
int edge[MAX_EDGES][3]; // stores information about edges
int d[MAX_NODES]; // stores shortest path from start node to each node in the graph

// Bellman-Ford algorithm to calculate shortest paths from a starting node
void bellman_ford(int s) {
    for (int i = 0; i < n; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edge[j][0], v = edge[j][1], w = edge[j][2];
            if (d[u] < INF && d[v] > d[u] + w) {
                d[v] = d[u] + w;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }
    int s = 0; // start node
    bellman_ford(s);
    for (int i = 0; i < n; i++) {
        printf("Shortest path from node %d to node %d is %d\n", s, i, d[i]);
    }
    return 0;
}
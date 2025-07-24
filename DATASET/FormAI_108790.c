//FormAI DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 1000
#define INF 10000000

typedef struct Graph {
    int num_vertices;
    int num_edges;
    int head[MAX_VERTICES];
    int to[MAX_EDGES], nxt[MAX_EDGES], dis[MAX_EDGES];
} Graph;

int d[MAX_VERTICES];

void Dijkstra(Graph *graph, int source) {
    for (int i = 0; i < graph->num_vertices; i++)
        d[i] = INF;
    d[source] = 0;

    int vis[MAX_VERTICES] = {0};
    for (int i = 0; i < graph->num_vertices; i++) {
        int u = -1;
        for (int j = 0; j < graph->num_vertices; j++)
            if (!vis[j] && (u == -1 || d[j] < d[u]))
                u = j;
        vis[u] = 1;

        for (int j = graph->head[u]; j != -1; j = graph->nxt[j]) {
            int v = graph->to[j], w = graph->dis[j];
            if (d[u] + w < d[v])
                d[v] = d[u] + w;
        }
    }
}

int main() {
    Graph graph = {5, 7, {-1, 2, 4, 6, 8, 10}, {1, 2, 0, 3, 3, 1, 4}, {10, 3, 3, 4, 1, 5, 8, 2}};

    Dijkstra(&graph, 0);

    for (int i = 0; i < graph.num_vertices; i++)
        printf("%d ", d[i]);
    printf("\n");
    
    return 0;
}
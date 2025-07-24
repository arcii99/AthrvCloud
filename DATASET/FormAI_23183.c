//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include<stdio.h>
#include<stdlib.h>

#define N 100
#define M 100

int n; // number of vertices
int m; // number of edges
int colors[N];
int adj[N][M]; // adjacency matrix

int color; // number of colors used in coloring

void init() {
    int i, j;
    color = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            adj[i][j] = 0;
        }
    }
}

int can_color(int node, int c) {
    int i;
    for (i = 0; i < m; i++) {
        if (adj[node][i] != 0 && colors[adj[node][i]] == c) {
            return 0;
        }
    }
    return 1;
}

void graph_color(int node) {
    int c;
    if (node == n) {
        int i;
        color = 0;
        for (i = 0; i < n; i++) {
            if (colors[i] > color) {
                color = colors[i];
            }
        }
        return;
    }
    for (c = 1; c <= color+1; c++) {
        if (can_color(node, c)) {
            colors[node] = c;
            graph_color(node+1);
            colors[node] = 0;
        }
    }
}

int main() {
    int i, j;
    init();
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edge vertices:\n");
    for (i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a-1][i] = b-1;
        adj[b-1][i] = a-1;
    }
    graph_color(0);
    printf("Minimum number of colors required to color the graph: %d\n", color);
    
    return 0;
}
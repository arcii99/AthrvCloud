//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int color[MAX];
int n, m;

bool isValidColor(int node, int c) {
    for (int i = 0; i < n; i++)
        if (graph[node][i] && c == color[i]) return false;
    return true;
}

bool graphColor(int node) {
    if (node == n) return true;
    for (int c = 1; c <= m; c++) {
        if (isValidColor(node, c)) {
            color[node] = c;
            if (graphColor(node+1)) return true;
            color[node] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter number of nodes and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter the edges:\n");
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }

    if (graphColor(0)) {
        printf("The coloring of the graph is:\n");
        for (int i = 0; i < n; i++)
            printf("Node %d -> Color %d\n", i, color[i]);
    } else {
        printf("No solution found\n");
    }

    return 0;
}
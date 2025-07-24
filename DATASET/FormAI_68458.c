//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

int n, e;

void printSolution(int color[]) {
    printf("Node colors: \n"); 
    for (int i = 0; i < n; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int isSafe(int v, int graph[n][n], int color[], int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

int graphColor(int graph[n][n], int m, int color[], int v) {
    if (v == n) {
        return 1;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColor(graph, m, color, v+1) == 1) {
                return 1;
            }
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1;
    }

    int color[n];
    for (int i = 0; i < n; i++) {
        color[i] = 0;
    }

    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                m++;
            }
        }
    }
    m /= 2;

    if (graphColor(graph, m, color, 0) == 0) {
        printf("Solution does not exist\n");
    } else {
        printf("Solution Exists\n");
        printSolution(color);
    }
    return 0;
}
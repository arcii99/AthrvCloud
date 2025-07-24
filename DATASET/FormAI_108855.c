//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int G[5][5];    // adjacency matrix
int color[5];   // array to store colors of vertices

// function to check if a vertex can be assigned a particular color
int isSafe(int v, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (G[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

// function to assign colors to all vertices
int graphColor(int n, int m, int v) {
    if (v == n) {   // we have colored all vertices
        return 1;
    }

    for (int c = 1; c <= m; c++) {      // consider all possible colors for vertex v
        if (isSafe(v, c, n)) {          // check if color c is valid for vertex v
            color[v] = c;
            if (graphColor(n, m, v+1)) {    // recursively color next vertex
                return 1;
            }
            color[v] = 0;   // backtrack if next vertex cannot be colored
        }
    }

    return 0;   // if all colors have been tried and none worked
}

int main() {
    int n = 5;  // number of vertices
    int m = 3;  // number of colors allowed

    // initializing adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = 0;
        }
    }

    // setting edges between vertices
    G[0][1] = 1;
    G[1][0] = 1;
    G[1][2] = 1;
    G[2][1] = 1;
    G[2][3] = 1;
    G[3][2] = 1;
    G[3][4] = 1;
    G[4][3] = 1;

    if (graphColor(n, m, 0)) {
        printf("Vertex colors: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", color[i]);
        }
    }
    else {
        printf("Graph cannot be colored with %d colors.", m);
    }

    return 0;
}
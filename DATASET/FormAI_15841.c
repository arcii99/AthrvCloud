//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

int main() {
    char alienLanguage[] = "5 3\n1 2 100\n2 5 100\n3 4 100";
    // The above string represents the input in the alien language
    int n, m;
    sscanf(alienLanguage, "%d %d", &n, &m);

    int graph[n][n];
    memset(graph, 0, sizeof(graph));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        sscanf(alienLanguage + strlen("5 3\n"), "%d %d %d", &u, &v, &w);
        // The above code extracts the three integers from the input string
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }

    printf("Translation from Alien Language to English is:\n");

    // Print the graph matrix in English
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                printf("There is a path between planet %d and planet %d, and the distance is %d light years.\n", i+1, j+1, graph[i][j]);
            }
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>

int main() {
    printf("Welcome to the Peaceful Graph Representation Program!\n");

    int n;
    printf("Enter the number of vertices in your graph: ");
    scanf("%d", &n);

    int graph[n][n];

    // Initialize all elements of the graph to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Ask the user for edge input
    char input[5];
    printf("Enter your edges in the format 'u v' (type 'done' to finish):\n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        int u = atoi(strtok(input, " "));
        int v = atoi(strtok(NULL, " "));
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Print the graph
    printf("\nYour Graph:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
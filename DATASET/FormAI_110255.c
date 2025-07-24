//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>

// Function to display the graph in a unique way
void displayGraph(char graph[][50], int numVertices) {
    printf("\n");
    printf("  ____________\n");
    printf(" / \\          \\\n");
    printf("|   |          |\n");

    for(int i=0; i<numVertices; i++) {
        printf("| %c ", 'A'+i);
        for(int j=0; j<numVertices; j++) {
            printf("%c ", graph[i][j]);
        }
        printf(" |\n");
    }

    printf("|   |__________|\n");
    printf("|   /       /   \\\n");
    printf("|  /       /     \\\n");
    printf("| /_______/_______\\\n");
    printf("|\n");
}

int main() {
    char graph[50][50];
    int numVertices;

    printf("Enter the number of vertices:\n");
    scanf("%d", &numVertices);

    // Get user input for the graph matrix
    printf("Enter the graph matrix (1 if there is an edge, 0 otherwise):\n");
    for(int i=0; i<numVertices; i++) {
        for(int j=0; j<numVertices; j++) {
            scanf("%d", &graph[i][j]);
            graph[j][i] = graph[i][j];  // Symmetric matrix
        }
    }

    displayGraph(graph, numVertices);

    return 0;
}
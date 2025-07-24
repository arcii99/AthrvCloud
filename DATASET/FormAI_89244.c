//FormAI DATASET v1.0 Category: Graph representation ; Style: relaxed
#include <stdio.h>

// Function to display the graph
void displayGraph(int graph[][100], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    int graph[rows][cols]; // 2D array to store graph
    
    // Let's initialize the graph with zeros
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            graph[i][j] = 0;
        }
    }
    
    // Let's create a sample graph
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][0] = 1;
    graph[0][3] = 1;
    
    // Let's display the graph
    printf("\nGraph:\n");
    displayGraph(graph, rows, cols);
    
    return 0;
}
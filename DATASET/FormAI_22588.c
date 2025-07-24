//FormAI DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int graph[rows][cols];
    
    printf("\nEnter the adjacency matrix:\n");
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("\nThe graph representation is:\n\n");
    printf("   ");
    for(int i=0; i<cols;i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i=0; i<rows; i++) {
        printf("%d| ",i);
        for(int j=0;j<cols;j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
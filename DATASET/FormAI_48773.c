//FormAI DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>

#define MAX_VERTEX 10

int graph[MAX_VERTEX][MAX_VERTEX];

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the edge matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Graph:\n");
    for(int i=0; i<n; i++) {
        printf("%d: ", i+1);
        for(int j=0; j<n; j++) {
            if(graph[i][j]) {
                printf("%d ", j+1);
            }
        }
        printf("\n");
    }
    
    return 0;
}
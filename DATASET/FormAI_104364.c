//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include<stdio.h>

int main(){
    int n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &graph[i][j]);
        }
    }
    //Printing the graph
    printf("The given graph is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    //Printing the graph representation
    printf("\nThe graph representation is:\n   ");
    for(i=0;i<n;i++){
        printf("%d ", i+1);
    }
    printf("\n__");
    for(i=0;i<n;i++){
        printf("___");
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d| ", i+1);
        for(j=0;j<n;j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
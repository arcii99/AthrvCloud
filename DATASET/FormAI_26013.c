//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include<stdio.h>

int main(){
    printf("Hello curious friend, welcome to my unique C graph representation program!\n\n");
    
    int vertices, edges;
    printf("How many vertices does your graph have?: ");
    scanf("%d", &vertices);
    printf("How many edges does your graph have?: ");
    scanf("%d", &edges);
    
    int matrix[vertices][vertices];
    int i, j;
    for(i=0; i<vertices; i++){
        for(j=0; j<vertices; j++){
            matrix[i][j] = 0;
        }
    }
    
    int u, v;
    printf("\nEnter the pair of vertices where the edge exists: \n");
    for(i=0; i<edges; i++){
        printf("\nEdge %d\n", i+1);
        printf("Vertex U: ");
        scanf("%d", &u);
        printf("Vertex V: ");
        scanf("%d", &v);
        matrix[u-1][v-1] = 1;
        matrix[v-1][u-1] = 1;
    }
    
    printf("\nYour Graph:\n\n    ");
    for(i=0; i<vertices; i++){
        printf("%d ", i+1);
    }
    printf("\n");
    for(i=0; i<vertices; i++){
        printf("%d   ", i+1);
        for(j=0; j<vertices; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\nThanks for using my program! Hope you learned something new today :)");
    return 0;
}
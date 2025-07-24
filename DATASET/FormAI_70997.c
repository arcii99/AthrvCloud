//FormAI DATASET v1.0 Category: Graph representation ; Style: invasive
#include<stdio.h>

int main(){
    printf("Invasive Graph Representation\n");
    printf("------------------------------\n");

    int vertices, edges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    int adj[vertices][vertices];

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            adj[i][j] = 0;
        }
    }

    for(int k=0; k<edges; k++){
        int u, v;
        printf("Enter the vertices which form edge #%d: ", k+1);
        scanf("%d %d", &u, &v);

        adj[u-1][v-1] = 1;
    }

    printf("\nThe Invasive Graph Representation:\n\n");

    for(int i=0; i<vertices; i++){
        printf("%d : ", i+1);

        for(int j=0; j<vertices; j++){
            if(adj[i][j] != 0){
                printf("%d -> ", j+1);
            }
        }

        printf("\n");
    }

    return 0;
}
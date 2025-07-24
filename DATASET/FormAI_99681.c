//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main(){
    //Initializing variables
    int vertices,edges,vertex1,vertex2;
    printf("Enter the number of vertices: ");
    scanf("%d",&vertices);
    printf("Enter the number of edges: ");
    scanf("%d",&edges);

    //Creating an adjacency matrix to represent the graph
    int **graph=(int **)malloc(vertices*sizeof(int *));
    for(int i=0;i<vertices;i++)
        graph[i]=(int *)calloc(vertices,sizeof(int));

    //Taking input from the user for each edge 
    printf("Enter the vertices of the edges one-by-one:\n");
    for(int i=1;i<=edges;i++){
        printf("Edge %d: ",i);
        scanf("%d %d",&vertex1,&vertex2);
        graph[vertex1-1][vertex2-1]=1; //Marking the edge in the matrix
        graph[vertex2-1][vertex1-1]=1; //Making sure it's an undirected graph
    }

    //Printing the adjacency matrix to show the graph
    printf("\nThe Graph is represented as follows\n\n  ");
    for(int i=1; i<=vertices; i++)
        printf("%d ",i);
    printf("\n");
    for(int i=1; i<=vertices; i++){
        printf("%d ",i);
        for(int j=0; j<vertices; j++){
            printf("%d ",graph[i-1][j]);
        }
        printf("\n");
    }

    //Freeing the memory allocated to the matrix
    for(int i=0;i<vertices;i++)
        free(graph[i]);
    free(graph);

    return 0;
}
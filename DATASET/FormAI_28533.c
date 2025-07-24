//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n; // number of vertices
    int m; // number of edges

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int** adj_matrix = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        adj_matrix[i] = (int*)malloc(n * sizeof(int));
        for(int j=0; j<n; j++){
            adj_matrix[i][j] = 0;
        }
    }

    int u, v;
    printf("Enter the edges in the form (u v):\n");
    for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    int* color = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        color[i] = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adj_matrix[i][j] && color[j] == color[i]){
                color[j] = (color[j]+1) % n;
            }
        }
    }

    printf("\nColoring of vertices:\n");
    for(int i=0; i<n; i++){
        printf("Vertex %d: Color %d\n", i+1, color[i]+1);
    }

    return 0;
}
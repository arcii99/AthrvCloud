//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int adj[MAX][MAX], n, m;
int color[MAX], visited[MAX];

int isValid(int v, int c){
    for(int i=0;i<n;i++){
        if(adj[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

void graphColoring(int v){
    for(int c=1; c<=m; c++){
        if(isValid(v,c)){
            color[v] = c;
            visited[v] = 1;
            if(v == n-1){
                printf("Solution found!\n");
                for(int i=0;i<n;i++)
                    printf("Vertex %d --> Color %d\n",i,color[i]);
                exit(0);
            }
            graphColoring(v+1);
            visited[v] = 0;
        }
    }
}

int main(){
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);

    printf("Enter the number of colors: ");
    scanf("%d",&m);

    graphColoring(0);
    printf("Solution does not exist!\n");

    return 0;
}
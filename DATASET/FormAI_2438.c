//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 6
#define MAX_COLORS 4

int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0,1,1,0,1,0},
    {1,0,1,1,0,1},
    {1,1,0,1,0,1},
    {0,1,1,0,1,1},
    {1,0,0,1,0,1},
    {0,1,1,1,1,0}
};

int colors[MAX_VERTICES];

int is_safe(int vertex_index, int color_index){
    int i;
    for(i = 0; i < MAX_VERTICES; ++i)
        if(graph[vertex_index][i] && colors[i] == color_index)
            return 0;
    return 1;
}

int graph_coloring(int vertex_index){
    if(vertex_index == MAX_VERTICES)
        return 1;

    int i;
    for(i = 0; i < MAX_COLORS; ++i){
        if( is_safe(vertex_index, i) ){
            colors[vertex_index] = i;
            if( graph_coloring(vertex_index+1) )
                return 1;
            colors[vertex_index] = -1;
        }
    }
    return 0;
}

int main(){
    int i;
    for(i = 0; i < MAX_VERTICES; ++i)
        colors[i] = -1;

    if(graph_coloring(0)){
        printf("Vertices with their associated colors:\n");
        for(i = 0; i < MAX_VERTICES; ++i)
            printf("%d: %d\n", i, colors[i]);
    }else{
        printf("No solution could be found!\n");
    }

    return 0;
}
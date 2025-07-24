//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VERTICES 10
#define MAX_COLORS 3

int graph[MAX_VERTICES][MAX_VERTICES];
int vertices[MAX_VERTICES];
int colors[MAX_COLORS];

void graph_generator(){
    int i,j;
    srand(time(NULL));
    for(i=0;i<MAX_VERTICES;i++){
        for(j=0;j<MAX_VERTICES;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else{
                graph[i][j]=rand()%2;
            }
        }
    }
}

void vertex_generator(){
    int i;
    for(i=0;i<MAX_VERTICES;i++){
        vertices[i]=i;
    }
}

void color_generator(){
    int i;
    for(i=0;i<MAX_COLORS;i++){
        colors[i]=i+1;
    }
}

int check_color(int vertex, int color){
    int i;
    for(i=0;i<MAX_VERTICES;i++){
        if(graph[vertex][i]==1 && color==vertices[i]){
            return 0;
        }
    }
    return 1;
}

void graph_coloring(){
    int i,j,color;
    for(i=0;i<MAX_VERTICES;i++){
        for(j=0;j<MAX_COLORS;j++){
            color=colors[j];
            if(check_color(i,color)==1){
                vertices[i]=color;
                break;
            }
        }
    }
}

void print_graph(){
    int i,j;
    printf("The generated graph is:\n");
    for(i=0;i<MAX_VERTICES;i++){
        for(j=0;j<MAX_VERTICES;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void print_colors(){
    int i;
    printf("The vertices with respective colors are:\n");
    for(i=0;i<MAX_VERTICES;i++){
        printf("V%d: C%d\n",i,vertices[i]);
    }
}

int main(){
    graph_generator();
    vertex_generator();
    color_generator();
    print_graph();
    graph_coloring();
    print_colors();
    return 0;
}
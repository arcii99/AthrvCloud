//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define V 10 //maximum number of vertices
#define E 15 //maximum number of edges

int main(){
    int graph[V][V]; //declare graph adjacency matrix
    int color[V]; //declare color array
    int i, j; //loop variables
    srand(time(NULL)); //seed random number generator with current time

    //initialize graph with random edges
    for(i=0; i<V; i++){
        for(j=i; j<V; j++){
            if(i!=j){
                graph[i][j] = graph[j][i] = rand() % 2;
            }else{
                graph[i][j] = 0; //self-edges not allowed
            }
        }
    }

    //print adjacency matrix
    printf("Adjacency Matrix:\n");
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    //initialize color array with -1 (no color assigned yet)
    for(i=0; i<V; i++){
        color[i] = -1;
    }

    //color the vertices
    for(i=0; i<V; i++){
        //allocate available colors to adjacent vertices
        int available_colors[V];
        for(j=0; j<V; j++){
            available_colors[j] = 1;
        }
        for(j=0; j<V; j++){
            if(graph[i][j] && color[j] != -1){
                available_colors[color[j]] = 0;
            }
        }

        //assign the smallest available color
        int c;
        for(c=0; c<V; c++){
            if(available_colors[c]){
                break;
            }
        }
        color[i] = c;
    }

    //print vertex colors
    printf("\nVertex Colors:\n");
    for(i=0; i<V; i++){
        printf("Vertex %d: Color %d\n", i, color[i]);
    }

    return 0;
}
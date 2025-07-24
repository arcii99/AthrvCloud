//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 100
int graph[MAX][MAX], V, E;
int color[MAX], available[MAX];
pthread_mutex_t mutex;

void* coloring(void* arg) {
    int v = *((int *) arg);
    int i, j;
    pthread_mutex_lock(&mutex);
    for(i = 1; i<=V; i++) {
        if(graph[v][i] == 1 && color[i] != -1) 
            available[color[i]] = 1;
    }
    for(i = 1; i<=V; i++) {
        if(available[i] == 0) {
            color[v] = i;
            break;
        }
    }   
    for(j = 1; j<=V; j++) {
        if(graph[v][j] == 1 && color[j] == -1) {
            int k;
            for(k = 1; k<=V; k++) {
                if(graph[v][k] == 1 && k!=j && color[k] == color[j]) {
                    color[j] = -1;
                    break;
                }
            }
        }
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    int i, j;
    pthread_t threads[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    //Initialize graph
    for(i = 1; i<=V; i++) {
        for(j = 1; j<=V; j++) {
            graph[i][j] = 0;
        }
    }

    //Add edges to graph
    printf("Enter edges(v1 v2):\n");
    for(i = 0; i<E; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    //Initialize colors and available array
    for(i = 1; i<=V; i++) {
        color[i] = -1;
        available[i] = 0;
    }

    //Create threads for each vertex and color them
    for(i = 1; i<=V; i++) {
        int* arg = (int*) malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&threads[i], NULL, coloring, arg);
    }

    //Join all threads
    for(i = 1; i<=V; i++) {
        pthread_join(threads[i], NULL);
    }

    //Print the colors of vertices
    printf("Vertex colors:\n");
    for(i = 1; i<=V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
    return 0;
}
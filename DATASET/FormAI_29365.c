//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define N 5
#define M 3

int graph[N][N] = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
};

int color[N] = {0};

bool isSafe(int v, int c) {
    for(int i = 0; i < N; i++) {
        if(graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

void* graphColoring(void* arg) {
    int vertex = *(int*) arg;
    for(int c = 1; c <= M; c++) {
        if(isSafe(vertex, c)) {
            color[vertex] = c;
            break;
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t tid[N];
    for(int i = 0; i < N; i++) {
        pthread_create(&tid[i], NULL, graphColoring, &i);
    }
    for(int i = 0; i < N; i++) {
        pthread_join(tid[i], NULL);
    }
    printf("Vertex\tColor\n");
    for(int i = 0; i < N; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXN 1000 // maximum number of vertices
#define MAX_COLOR 5 // maximum number of colors

int N; // number of vertices
int graph[MAXN][MAXN]; // adjacency matrix
int colors[MAXN]; // color of each vertex

sem_t mutex1, mutex2; // semaphores for synchronization
bool waiting[MAX_COLOR]; // array to track waiting threads

void* assign_colors(void* id) {
    int v = *(int*)id;

    // check available colors for the vertex
    bool taken[MAX_COLOR] = {false};
    for (int i = 0; i < N; i++) {
        if (graph[v][i] && colors[i] != -1) {
            taken[colors[i]] = true;
        }
    }

    // find an unused color
    int color = 0;
    for (int i = 0; i < MAX_COLOR; i++) {
        if (!taken[i]) {
            color = i;
            break;
        }
    }

    // wait for access to colors array
    sem_wait(&mutex1);
    while (waiting[color]) {
        sem_post(&mutex1);
        sem_wait(&mutex1);
    }
    waiting[color] = true;
    sem_post(&mutex1);

    // assign color to vertex
    colors[v] = color;

    // release waiting threads
    sem_wait(&mutex2);
    waiting[color] = false;
    sem_post(&mutex2);

    printf("Vertex %d assigned color %d\n", v, color);

    pthread_exit(NULL);
}

int main() {
    // initialize graph with random edges
    srand(time(NULL));
    N = rand() % MAXN + 1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            graph[i][j] = graph[j][i] = rand() % 2;
        }
    }

    // initialize colors array to -1 (unassigned)
    for (int i = 0; i < N; i++) {
        colors[i] = -1;
    }

    // initialize semaphores
    sem_init(&mutex1, 0, 1);
    sem_init(&mutex2, 0, 1);
    for (int i = 0; i < MAX_COLOR; i++) {
        waiting[i] = false;
    }

    // spawn threads to assign colors
    pthread_t threads[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, assign_colors, &ids[i]);
    }

    // wait for threads to finish
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // print final colors
    printf("\nFinal colors:\n");
    for (int i = 0; i < N; i++) {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }

    // cleanup semaphores
    sem_destroy(&mutex1);
    sem_destroy(&mutex2);

    return 0;
}
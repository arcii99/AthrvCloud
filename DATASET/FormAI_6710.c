//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct {
    int vertex1;
    int vertex2;
} Edge;

int numVertices, numEdges;

Edge edges[MAX_EDGES];
int vertexList[MAX_VERTICES][MAX_VERTICES];

pthread_mutex_t mutex;

void addEdge(int vertex1, int vertex2) {
    edges[numEdges].vertex1 = vertex1;
    edges[numEdges].vertex2 = vertex2;

    vertexList[vertex1][vertex2] = 1;
    vertexList[vertex2][vertex1] = 1;

    numEdges++;
}

void printGraph() {
    pthread_mutex_lock(&mutex);

    printf("Graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", vertexList[i][j]);
        }
        printf("\n");
    }

    pthread_mutex_unlock(&mutex);
}

void *addEdges(void *arg) {
    int *num = (int *) arg;

    for (int i = 0; i < *num; i++) {
        int vertex1 = rand() % numVertices;
        int vertex2 = rand() % numVertices;

        if (vertex1 != vertex2 && vertexList[vertex1][vertex2] == 0) {
            printf("Adding edge between %d and %d\n", vertex1, vertex2);
            addEdge(vertex1, vertex2);
        }
    }

    return NULL;
}

int main() {
    numVertices = 5; // Change this value to change number of vertices
    
    // Initialize mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }

    pthread_t thread1, thread2;

    // Create threads
    int numEdgesPerThread = (MAX_EDGES-1)/2;
    pthread_create(&thread1, NULL, addEdges, &numEdgesPerThread);
    pthread_create(&thread2, NULL, addEdges, &numEdgesPerThread);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printGraph();

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
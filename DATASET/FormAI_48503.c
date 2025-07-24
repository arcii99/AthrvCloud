//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_POINTS 100
#define NUM_THREADS 4

typedef struct Point {
    double x;
    double y;
} Point;

Point points[MAX_POINTS];

void *calculateArea(void *threadID) {
    long tid = (long) threadID;
    int start = tid * (MAX_POINTS / NUM_THREADS);
    int end = (tid + 1) * (MAX_POINTS / NUM_THREADS);

    double area = 0;
    for(int i = start; i < end; i++) {
        area += points[i].x * points[(i + 1) % MAX_POINTS].y -
                points[(i + 1) % MAX_POINTS].x * points[i].y;
    }

    area /= 2;

    printf("Thread %ld calculated area: %lf\n", tid, area);

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    // Generate random points
    for(int i = 0; i < MAX_POINTS; i++) {
        points[i].x = (double) rand() / RAND_MAX * 10;
        points[i].y = (double) rand() / RAND_MAX * 10;
    }

    // Create threads
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, calculateArea, (void *) t);
        if(rc) {
            printf("Error: failed to create thread %ld\n", t);
            exit(-1);
        }
    }

    // Join threads
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    return 0;
}
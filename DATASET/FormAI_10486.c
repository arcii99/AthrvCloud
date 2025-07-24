//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

// Define a structure to hold the coordinates of a point
typedef struct {
    double x;
    double y;
} Point;

// Define a function to calculate the distance between two points
double distance(Point p1, Point p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// Define the routine that each thread will execute
void *thread_routine(void *args) {
    int thread_id = (int) args;
    printf("Thread %d started\n", thread_id);

    // Generate some random points
    Point points[10];
    for (int i = 0; i < 10; i++) {
        points[i].x = rand() % 10;
        points[i].y = rand() % 10;
    }

    // Calculate the distance between every pair of points
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            double dist = distance(points[i], points[j]);
            printf("Thread %d: distance between (%f, %f) and (%f, %f) = %f\n", thread_id, points[i].x, points[i].y, points[j].x, points[j].y, dist);
        }
    }

    printf("Thread %d finished\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    // Create each thread and pass in its ID as an argument
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        int rc = pthread_create(&threads[i], NULL, thread_routine, (void*) thread_args[i]);
        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    // Wait for each thread to finish before exiting
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished\n");
    return 0;
}
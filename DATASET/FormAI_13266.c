//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NUM_THREADS 4

// Struct to represent a point in 2D
typedef struct Point {
    double x;
    double y;
} Point;

// Struct to represent a Line Segment in 2D
typedef struct LineSegment {
    Point a;
    Point b;
} LineSegment;

// Function to calculate the Euclidean distance between two points
double calculate_distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Thread function to calculate the length of a LineSegment
void* calculate_length(void* arg) {
    LineSegment* line = (LineSegment*)arg;
    double length = calculate_distance(line->a, line->b);
    printf("Length of line %lf\n", length);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;

    // Create some LineSegments
    LineSegment lines[NUM_THREADS];
    lines[0].a.x = 0; lines[0].a.y = 0; lines[0].b.x = 5; lines[0].b.y = 5;
    lines[1].a.x = 3; lines[1].a.y = 4; lines[1].b.x = 10; lines[1].b.y = 5;
    lines[2].a.x = 2; lines[2].a.y = 7; lines[2].b.x = 8; lines[2].b.y = 3;
    lines[3].a.x = 1; lines[3].a.y = 2; lines[3].b.x = 6; lines[3].b.y = 9;

    // Start the threads to calculate the lengths of the LineSegments
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, calculate_length, (void*)&lines[i]);
        if (rc) {
            printf("Error creating thread\n");
            exit(-1);
        }
    }

    // Wait for the threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
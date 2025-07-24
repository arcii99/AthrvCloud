//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 4    // Define number of threads

// Structure to store point coordinates
typedef struct {
    double x;
    double y;
} Point;

// Structure to store line endpoints
typedef struct {
    Point p1;
    Point p2;
} Line;

// Global variables
Line lines[1000];
int numLines = 0;
int lineIndex = 0;
pthread_mutex_t mutexLineIndex;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Thread worker function to calculate the length of a line
void *calculateLineLength(void *threadId) {
    long tid = (long)threadId;
    while (1) {
        pthread_mutex_lock(&mutexLineIndex);
        if (lineIndex >= numLines) {
            pthread_mutex_unlock(&mutexLineIndex);
            break;
        }
        Line line = lines[lineIndex];
        lineIndex++;
        pthread_mutex_unlock(&mutexLineIndex);
        
        printf("Thread %ld calculating length of line #%d\n", tid, lineIndex);
        double length = distance(line.p1, line.p2);
        printf("Thread %ld calculated length of line #%d: %f\n", tid, lineIndex, length);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutexLineIndex, NULL);
    
    // Generate 1000 random lines
    for (int i = 0; i < 1000; i++) {
        Point p1 = {rand() % 100, rand() % 100};
        Point p2 = {rand() % 100, rand() % 100};
        Line line = {p1, p2};
        lines[i] = line;
    }
    numLines = 1000;
    
    // Create threads
    for (long i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, calculateLineLength, (void *)i);
        if (rc) {
            printf("Error creating thread %ld\n", i);
            exit(-1);
        }
    }
    
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutexLineIndex);
    pthread_exit(NULL);
}
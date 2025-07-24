//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4

typedef struct {
    double x;
    double y;
} Point;

double distance(Point a, Point b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

void *compute(void *param) {
    Point *points = (Point *) param;
    double max_distance = 0;
    Point farthest_point1, farthest_point2;

    for (int i = 0; i < 50; i++) {
        for (int j = i + 1; j < 50; j++) {
            double dist = distance(points[i], points[j]);
            if (dist > max_distance) {
                max_distance = dist;
                farthest_point1 = points[i];
                farthest_point2 = points[j];
            }
        }
    }

    printf("Thread %ld: Farthest points are (%.2f, %.2f) and (%.2f, %.2f). Distance is %.2f\n",
           pthread_self(), farthest_point1.x, farthest_point1.y, farthest_point2.x, farthest_point2.y, max_distance);

    pthread_exit(NULL);
}

int main() {
    Point points[50] = {
        {1, 1}, {2, 3}, {3, 5}, {4, 3}, {5, 1},
        {2, 2}, {3, 4}, {4, 2}, {2, 4}, {4, 4},
        {1, 6}, {2, 7}, {3, 6}, {2, 5}, {3, 3},
        {6, 6}, {7, 7}, {9, 7}, {6, 5}, {7, 5},
        {5, 8}, {5, 9}, {6, 8}, {7, 9}, {8, 8},
        {10, 2}, {10, 4}, {12, 2}, {12, 4}, {11, 3},
        {10, 6}, {10, 7}, {12, 6}, {12, 7}, {11, 5},
        {14, 2}, {15, 3}, {16, 2}, {14, 4}, {16, 4},
        {14, 6}, {14, 7}, {15, 6}, {16, 7}, {15, 5}
    };

    pthread_t threads[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, compute, (void *) points);

        if (rc) {
            printf("Error creating thread: %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}
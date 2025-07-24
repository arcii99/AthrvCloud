//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4

// Structure to hold the coordinates of a point in 2D space
typedef struct Point {
    double x;
    double y;
} Point;

// Structure to hold the coordinates of a line in 2D space
typedef struct Line {
    Point p1;
    Point p2;
} Line;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

// Function to calculate the length of a line
double length(Line l) {
    return distance(l.p1, l.p2);
}

// Function to check if a point lies on a line
int onLine(Point p, Line l) {
    double d1 = distance(p, l.p1);
    double d2 = distance(p, l.p2);
    if (fabs(d1 + d2 - length(l)) < 0.001) {
        return 1;
    }
    return 0;
}

// Function that calculates the intersection point of two lines
Point intersection(Line l1, Line l2) {
    double m1 = (l1.p2.y - l1.p1.y) / (l1.p2.x - l1.p1.x);
    double m2 = (l2.p2.y - l2.p1.y) / (l2.p2.x - l2.p1.x);
    double b1 = l1.p1.y - m1 * l1.p1.x;
    double b2 = l2.p1.y - m2 * l2.p1.x;
    double x = (b2 - b1) / (m1 - m2);
    double y = m1 * x + b1;
    Point p = {x, y};
    return p;
}

// Function that finds the intersection point of two lines and prints it to the console
void findIntersection(Line l1, Line l2) {
    Point p = intersection(l1, l2);
    printf("Intersection point: (%f, %f)\n", p.x, p.y);
}

// Function that finds the point that is closest to the origin among a list of points
void* closestToOrigin(void* args) {
    Point* points = (Point*) args;
    Point closest = points[0];
    double minDist = distance(closest, (Point) {.x = 0, .y = 0});
    for (int i = 1; i < NUM_THREADS; i++) {
        double dist = distance(points[i], (Point) {.x = 0, .y = 0});
        if (dist < minDist) {
            closest = points[i];
            minDist = dist;
        }
    }
    printf("Closest point to origin: (%f, %f)\n", closest.x, closest.y);
    pthread_exit(NULL);
}

int main() {
    Point p1 = {.x = 1, .y = 1};
    Point p2 = {.x = 3, .y = 3};
    Point p3 = {.x = 2, .y = 0};
    Point p4 = {.x = 0, .y = 2};
    Line l1 = {p1, p3};
    Line l2 = {p2, p4};
    
    pthread_t threads[NUM_THREADS];
    int rc;
    
    // Calculate intersection point of two lines using two threads
    rc = pthread_create(&threads[0], NULL, findIntersection, (void*) &l1);
    if (rc) {
        printf("Error: return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
    rc = pthread_create(&threads[1], NULL, findIntersection, (void*) &l2);
    if (rc) {
        printf("Error: return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
    
    // Wait for threads to complete
    void* status;
    for (int i = 0; i < 2; i++) {
        rc = pthread_join(threads[i], &status);
        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }
    
    // Find closest point to origin among a list of points using two threads
    Point* points = malloc(NUM_THREADS * sizeof(Point));
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
    rc = pthread_create(&threads[2], NULL, closestToOrigin, (void*) points);
    if (rc) {
        printf("Error: return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
    rc = pthread_create(&threads[3], NULL, closestToOrigin, (void*) &points[2]);
    if (rc) {
        printf("Error: return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
    
    // Wait for threads to complete
    for (int i = 2; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &status);
        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }
    
    free(points);
    return 0;
}
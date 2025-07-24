//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define Point struct
typedef struct {
    double x;
    double y;
} Point;

// Calculate distance between two points
double calculate_distance(Point p1, Point p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

int main() {
    // Initialize Point variables
    Point p1 = {1.0, 1.0};
    Point p2 = {4.0, 5.0};
    Point p3 = {-2.5, 3.2};

    // Calculate distance between p1 and p2
    double distance_p1_p2 = calculate_distance(p1, p2);
    printf("Distance between p1 and p2: %f\n", distance_p1_p2);

    // Calculate distance between p1 and p3
    double distance_p1_p3 = calculate_distance(p1, p3);
    printf("Distance between p1 and p3: %f\n", distance_p1_p3);

    // Calculate distance between p2 and p3
    double distance_p2_p3 = calculate_distance(p2, p3);
    printf("Distance between p2 and p3: %f\n", distance_p2_p3);

    return 0;
}
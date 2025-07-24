//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: futuristic
#include <stdio.h>
#include <math.h>

// A structure to represent a point in 2D space
struct Point {
    double x;
    double y;
};

// A function to calculate the distance between two points in 2D space
double distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    // Initialize two points with random values
    struct Point p1 = {1.0, 2.0};
    struct Point p2 = {4.0, 3.0};
    
    // Calculate the distance between two points
    double d = distance(p1, p2);
    
    // Print the distance
    printf("The distance between (%.2lf, %.2lf) and (%.2lf, %.2lf) is %.2lf\n", p1.x, p1.y, p2.x, p2.y, d);
    
    return 0;
}
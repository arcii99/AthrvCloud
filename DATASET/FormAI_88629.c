//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

// Define structure to represent a point in 2D
typedef struct {
    float x;
    float y;
} Point;

// Define function to calculate euclidean distance between two points
float euclideanDistance(Point p1, Point p2) {
    float distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distance;
}

int main() {
    // Initialize three points
    Point p1 = {4, 5};
    Point p2 = {8, 2};
    Point p3 = {12, 9};
    
    // Calculate distance between p1 and p2 using euclidean distance
    float distance1 = euclideanDistance(p1, p2);
    printf("Distance between p1 and p2 is %f\n", distance1);
    
    // Calculate distance between p2 and p3 using euclidean distance
    float distance2 = euclideanDistance(p2, p3);
    printf("Distance between p2 and p3 is %f\n", distance2);
    
    // Calculate distance between p1 and p3 using euclidean distance
    float distance3 = euclideanDistance(p1, p3);
    printf("Distance between p1 and p3 is %f\n", distance3);
    
    // Check if the three points form an equilateral triangle
    if(distance1 == distance2 && distance2 == distance3) {
        printf("The three points form an equilateral triangle!\n");
    } else {
        printf("The three points do not form an equilateral triangle.\n");
    }
    
    return 0;
}
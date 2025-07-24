//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>

struct Point {
    int x, y;
};

// Function to calculate square of a number
int square(int x){
    return x*x;
}

// Function to calculate distance between two points
int distance(struct Point p1, struct Point p2) {
    return square(p1.x - p2.x) + square(p1.y - p2.y);
}

// Function to check if three points are collinear
int isCollinear(struct Point p1, struct Point p2, struct Point p3){
    return (p2.y - p1.y) * (p3.x - p2.x) == (p3.y - p2.y) * (p2.x - p1.x);
}

// Function to check if a point is inside a circle
int isInsideCircle(struct Point p, struct Point c, int r){
    return distance(p, c) <= square(r);
}

int main(){
    // Example usage
    struct Point p1 = {0, 0};
    struct Point p2 = {3, 0};
    struct Point p3 = {0, 4};

    // Check if points are collinear
    if (isCollinear(p1, p2, p3)){
        printf("Points are collinear.\n");
    } else {
        printf("Points are not collinear.\n");
    }

    // Check if a point is inside a circle
    struct Point center = {2, 2};
    int radius = 3;
    struct Point testPoint = {4, 4};

    if (isInsideCircle(testPoint, center, radius)){
        printf("Point is inside the circle.\n");
    } else {
        printf("Point is outside the circle.\n");
    }

    return 0;
}
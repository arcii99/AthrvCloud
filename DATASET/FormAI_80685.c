//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function that calculates the distance between two points in 2D space
float dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Function that calculates the area of a triangle given three points in 2D space
float area(float x1, float y1, float x2, float y2, float x3, float y3) {
    float a = dist(x1, y1, x2, y2);
    float b = dist(x2, y2, x3, y3);
    float c = dist(x1, y1, x3, y3);
    float s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    // Define three points in 2D space
    float x1 = 1, y1 = 1;
    float x2 = 2, y2 = 3;
    float x3 = 3, y3 = 2;
    
    // Calculate the distance between two of the points
    printf("The distance between (%.2f, %.2f) and (%.2f, %.2f) is %.2f\n", x1, y1, x2, y2, dist(x1, y1, x2, y2));
    
    // Calculate the area of the triangle formed by the three points
    printf("The area of the triangle formed by (%.2f, %.2f), (%.2f, %.2f), and (%.2f, %.2f) is %.2f\n", x1, y1, x2, y2, x3, y3, area(x1, y1, x2, y2, x3, y3));
    
    return 0;
}
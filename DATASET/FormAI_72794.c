//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define struct for 2D point
typedef struct Point {
    double x;
    double y;
} Point;

// Function to calculate the Euclidean distance between two points
double euclideanDistance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Function to calculate the area of a triangle given three points
double triangleArea(Point p1, Point p2, Point p3) {
    double a = euclideanDistance(p1, p2);
    double b = euclideanDistance(p2, p3);
    double c = euclideanDistance(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to generate a random point within a given bounding box
Point generateRandomPoint(double minX, double minY, double maxX, double maxY) {
    Point p;
    p.x = (double) rand() / RAND_MAX * (maxX - minX) + minX;
    p.y = (double) rand() / RAND_MAX * (maxY - minY) + minY;
    return p;
}

int main() {
    srand(time(NULL)); // Seed random number generator
    
    // Define a bounding box for the points
    double minX = -10;
    double minY = -10;
    double maxX = 10;
    double maxY = 10;
    
    // Generate three random points
    Point p1 = generateRandomPoint(minX, minY, maxX, maxY);
    Point p2 = generateRandomPoint(minX, minY, maxX, maxY);
    Point p3 = generateRandomPoint(minX, minY, maxX, maxY);
    
    // Calculate the area of the triangle formed by the three points
    double area = triangleArea(p1, p2, p3);
    
    // Print out the points and area
    printf("Point 1: (%f, %f)\n", p1.x, p1.y);
    printf("Point 2: (%f, %f)\n", p2.x, p2.y);
    printf("Point 3: (%f, %f)\n", p3.x, p3.y);
    printf("Triangle area: %f\n", area);
    
    return 0;
}
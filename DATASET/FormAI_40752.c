//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
#include <stdio.h>
#include <math.h>

// This program calculates the area of a triangle given 3 vertices in a 2D space

// Define a struct to store the coordinates of a point
typedef struct {
    double x;
    double y;
} point;

// Define a function to calculate the distance between two points
double distance(point p1, point p2) {
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}

int main() {
    // Ask the user to enter the coordinates of three points
    point p1, p2, p3;
    printf("Enter the coordinates of point 1 (x y): ");
    scanf("%lf %lf", &p1.x, &p1.y);
    printf("Enter the coordinates of point 2 (x y): ");
    scanf("%lf %lf", &p2.x, &p2.y);
    printf("Enter the coordinates of point 3 (x y): ");
    scanf("%lf %lf", &p3.x, &p3.y);
    
    // Calculate the lengths of the sides of the triangle
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    
    // Calculate the semiperimeter of the triangle
    double s = (a + b + c) / 2;
    
    // Calculate the area of the triangle using Heron's formula
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    
    // Print the area of the triangle
    printf("The area of the triangle is %lf\n", area);
    
    return 0;
}
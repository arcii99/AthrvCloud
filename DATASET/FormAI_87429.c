//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <math.h>

// Define a structure to represent a 2D point
typedef struct point {
   float x,y;
} Point;

// Function to calculate distance between two points
float distance(Point p1, Point p2) {
   return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
}

// Function to calculate the perimeter of a triangle
float perimeter(Point p1, Point p2, Point p3) {
   return distance(p1,p2) + distance(p2,p3) + distance(p1,p3);
}

// Function to calculate the area of a triangle
float area(Point p1, Point p2, Point p3) {
   float s = perimeter(p1,p2,p3)/2; // Half of the perimeter
   return sqrt(s*(s-distance(p1,p2))*(s-distance(p2,p3))*(s-distance(p3,p1))); // Heron's formula
}

int main() {
   Point p1 = {0,0}, p2 = {3,0}, p3 = {0,4}; // Define three points to form a triangle
   printf("Triangle perimeter = %.2f\n", perimeter(p1,p2,p3)); // Print the perimeter of the triangle
   printf("Triangle area = %.2f\n", area(p1,p2,p3)); // Print the area of the triangle
   return 0;
}
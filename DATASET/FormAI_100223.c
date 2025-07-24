//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: content
#include <stdio.h>
#include <stdlib.h>

// struct to represent a point in 2D space
typedef struct Point {
   int x, y;
} Point;

// function to calculate Euclidean distance between two points
double distance(Point p1, Point p2) {
   int dx = p2.x - p1.x;
   int dy = p2.y - p1.y;
   return sqrt(dx*dx + dy*dy);
}

// function to calculate the area of a triangle formed by three points
double triangle_area(Point a, Point b, Point c) {
   double side_a = distance(a, b);
   double side_b = distance(b, c);
   double side_c = distance(c, a);
   double s = (side_a + side_b + side_c) / 2;  // semiperimeter
   return sqrt(s*(s-side_a)*(s-side_b)*(s-side_c));  // Heron's formula
}

int main() {
   // create three points to form a triangle
   Point A = {1, 1};
   Point B = {4, 5};
   Point C = {7, 1};
   
   // calculate the area of triangle ABC
   double area = triangle_area(A, B, C);
   
   // output the result
   printf("The area of triangle ABC is %.2f\n", area);
   
   return 0;
}
//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include <stdio.h>
#include <math.h>

// define a structure to hold the x and y coordinates of a point
struct Point {
   double x;
   double y;
};

// function to calculate the distance between two points
double distance(struct Point p1, struct Point p2) {
   double dx = p2.x - p1.x;
   double dy = p2.y - p1.y;
   return sqrt(dx*dx + dy*dy);
}

// function to calculate the area of a triangle
double area(struct Point p1, struct Point p2, struct Point p3) {
   double a = distance(p1, p2);
   double b = distance(p2, p3);
   double c = distance(p3, p1);
   double s = (a + b + c) / 2;
   return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
   struct Point p1 = {0, 0};
   struct Point p2 = {4, 0};
   struct Point p3 = {0, 3};

   double tri_area = area(p1, p2, p3);

   printf("The area of the triangle with vertices (%.1f, %.1f), (%.1f, %.1f), and (%.1f, %.1f) is %.2f\n",
          p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, tri_area);

   return 0;
}
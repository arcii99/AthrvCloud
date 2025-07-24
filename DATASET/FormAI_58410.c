//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include <stdio.h>
#include <math.h>

/*
This program will find the intersection point of two line segments in a 2D plane using the geometric approach.
*/

typedef struct point {
   float x;
   float y;
} Point;

typedef struct line {
   Point p1;
   Point p2;
} Line;

float signedArea(Point p1, Point p2, Point p3) {
   float a = p1.x * (p2.y - p3.y);
   float b = p2.x * (p3.y - p1.y);
   float c = p3.x * (p1.y - p2.y);
   return 0.5 * (a + b + c);
}

int intersection(Line l1, Line l2, Point* intersectionPoint) {
   float a1 = l1.p2.y - l1.p1.y;
   float b1 = l1.p1.x - l1.p2.x;
   float c1 = a1 * l1.p1.x + b1 * l1.p1.y;
   
   float a2 = l2.p2.y - l2.p1.y;
   float b2 = l2.p1.x - l2.p2.x;
   float c2 = a2 * l2.p1.x + b2 * l2.p1.y;
   
   float det = a1 * b2 - a2 * b1;
   if (det == 0) {
      return 0;
   } else {
      float x = (b2 * c1 - b1 * c2) / det;
      float y = (a1 * c2 - a2 * c1) / det;
      
      // Check if the intersection point is within the line segments
      if (fmin(l1.p1.x, l1.p2.x) <= x && x <= fmax(l1.p1.x, l1.p2.x) &&
          fmin(l1.p1.y, l1.p2.y) <= y && y <= fmax(l1.p1.y, l1.p2.y) &&
          fmin(l2.p1.x, l2.p2.x) <= x && x <= fmax(l2.p1.x, l2.p2.x) &&
          fmin(l2.p1.y, l2.p2.y) <= y && y <= fmax(l2.p1.y, l2.p2.y)) {
         intersectionPoint->x = x;
         intersectionPoint->y = y;
         return 1;
      } else {
         return 0;
      }
   }
}

int main() {
   Point P1 = {1, 1};
   Point P2 = {3, 3};
   Point P3 = {1, 3};
   Point P4 = {3, 1};
   
   Line L1 = {P1, P2};
   Line L2 = {P3, P4};
   
   Point intersectionPoint;
   if (intersection(L1, L2, &intersectionPoint)) {
      printf("The intersection point is (%f, %f)\n", intersectionPoint.x, intersectionPoint.y);
   } else {
      printf("The two line segments do not intersect.\n");
   }
   
   return 0;
}
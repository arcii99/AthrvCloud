//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

typedef struct point {
   int x;
   int y;
} Point;

float distance(Point p1, Point p2) {
   return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
   Point p1 = {0, 0};
   Point p2 = {3, 4};
   printf("Distance between points (%d, %d) and (%d, %d) is %f\n",
          p1.x, p1.y, p2.x, p2.y, distance(p1, p2));

   return 0;
}
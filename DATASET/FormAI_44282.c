//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: future-proof
#include <stdio.h>
#include <math.h>

typedef struct Point {
   double x;
   double y;
} Point;

double getDistance(Point p1, Point p2) {
   double dx = p2.x - p1.x;
   double dy = p2.y - p1.y;
   return sqrt(dx*dx + dy*dy);
}

int main() {
   Point p1, p2, p3;
   double a, b, c;

   printf("Enter the coordinates of first point: ");
   scanf("%lf %lf", &p1.x, &p1.y);

   printf("Enter the coordinates of second point: ");
   scanf("%lf %lf", &p2.x, &p2.y);

   printf("Enter the coordinates of third point: ");
   scanf("%lf %lf", &p3.x, &p3.y);

   a = getDistance(p1, p2);
   b = getDistance(p2, p3);
   c = getDistance(p3, p1);

   if (a + b > c && b + c > a && c + a > b) {
      double s = (a + b + c) / 2.0;
      double area = sqrt(s*(s-a)*(s-b)*(s-c));
      printf("Triangle area = %.2f\n", area);
   }
   else {
      printf("Not a triangle!\n");
   }

   return 0;
}
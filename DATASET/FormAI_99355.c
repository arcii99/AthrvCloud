//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

int main() {
 int x1, y1, x2, y2, x3, y3, slope1, slope2;
 printf("Enter the first point (x1, y1):\n");
 scanf("%d%d", &x1, &y1);
 printf("Enter the second point (x2, y2):\n");
 scanf("%d%d", &x2, &y2);
 printf("Enter the third point (x3, y3):\n");
 scanf("%d%d", &x3, &y3);
 
 slope1 = (y2 - y1) / (x2 - x1);
 slope2 = (y3 - y2) / (x3 - x2);
 
 if (slope1 == slope2) {
     printf("The three points are collinear.\n");
 } else {
     int area = (x1*y2) + (x2*y3) + (x3*y1) - (y1*x2) - (y2*x3) - (y3*x1);
     if (area > 0) {
         printf("The three points form a counter-clockwise triangle.\n");
     } else {
         printf("The three points form a clockwise triangle.\n");
     }
 }
 
 return 0;
}
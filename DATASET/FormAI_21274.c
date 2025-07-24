//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>

struct point {
   int x, y;
};

struct line {
   struct point start, end;
};

int main() {
   struct line l;
   printf("Enter start point: ");
   scanf("%d %d", &l.start.x, &l.start.y);
   printf("Enter end point: ");
   scanf("%d %d", &l.end.x, &l.end.y);
   
   //Calculate midpoint
   struct point midpoint;
   midpoint.x = (l.start.x + l.end.x) / 2;
   midpoint.y = (l.start.y + l.end.y) / 2;
   
   //Calculate distance between start and end points
   float distance = sqrt((l.end.x - l.start.x) * (l.end.x - l.start.x) + (l.end.y - l.start.y) * (l.end.y - l.start.y));
   
   //Calculate slope of line
   float slope = (l.end.y - l.start.y) / (float)(l.end.x - l.start.x);
   
   //Calculate angle of line with x-axis in degrees
   float angle = atan(slope) * 180 / 3.14;
   
   printf("Midpoint of line: (%d, %d)\n", midpoint.x, midpoint.y);
   printf("Distance between start and end points: %f\n", distance);
   printf("Slope of line: %f\n", slope);
   printf("Angle of line with x-axis: %f degrees", angle);
   
   return 0;
}
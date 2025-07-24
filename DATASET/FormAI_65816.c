//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: genious
#include <stdio.h>
#include <math.h>

int main() {
  int x1, y1, r1, x2, y2, r2;   // coordinates and radii of two circles
  float dist;                   // distance between centers of circles
  printf("Enter the coordinates and radii of the first circle: ");
  scanf("%d %d %d", &x1, &y1, &r1);
  printf("Enter the coordinates and radii of the second circle: ");
  scanf("%d %d %d", &x2, &y2, &r2);
  dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));    // calculate distance
  if (dist == 0) {    // if centers coincide
    if (r1 == r2) {
      printf("The two circles coincide.\n");
    } else {
      printf("The two circles intersect at a point.\n");
    }
  } else {    // centers are distinct
    if ((dist < (r1 + r2)) && (dist > fabs(r1 - r2))) {   // if circles intersect
      printf("The two circles intersect at two points.\n");
      float d = (pow(r1,2) - pow(r2,2) + pow(dist,2)) / (2 * dist);
      float h = sqrt(pow(r1,2) - pow(d,2));
      float x0 = x1 + d * (x2 - x1)/dist;
      float y0 = y1 + d * (y2 - y1)/dist;
      printf("The intersection points are: (%f,%f) and (%f,%f)\n", 
             x0 + h * (y2 - y1)/dist, y0 - h * (x2 - x1)/dist, 
             x0 - h * (y2 - y1)/dist, y0 + h * (x2 - x1)/dist);
    } else {
      printf("The two circles do not intersect.\n");
    }
  }
  return 0;
}
//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: puzzling
#include <stdio.h>
#include <math.h>

int main() {
  int n, x, y;
  float r;

  // Prompt user for input
  printf("Enter the radius r of the circle: ");
  scanf("%f", &r);
  printf("Enter the coordinates (x, y) of a point: ");
  scanf("%d %d", &x, &y);

  // Calculate distance from the point to the center
  float d = sqrt(pow(x, 2) + pow(y, 2));

  // Check if the point is inside or outside the circle
  if (d < r) {
    printf("The point (%d, %d) is inside the circle with radius %.2f\n", x, y, r);
  } else if (d > r) {
    printf("The point (%d, %d) is outside the circle with radius %.2f\n", x, y, r);
  } else {
    printf("The point (%d, %d) is on the circle with radius %.2f\n", x, y, r);
  }

  // Prompt user to enter n points and find the farthest point from the center
  printf("Enter the number of points to be plotted: ");
  scanf("%d", &n);
  int farthest_x, farthest_y;
  float farthest_d = 0;
  for (int i = 0; i < n; i++) {
    printf("Enter the coordinates (x, y) of point %d: ", i+1);
    scanf("%d %d", &x, &y);
    d = sqrt(pow(x, 2) + pow(y, 2));
    if (d > farthest_d) {
      farthest_d = d;
      farthest_x = x;
      farthest_y = y;
    }
  }
  printf("The farthest point from the center is (%d, %d) with a distance of %.2f\n", farthest_x, farthest_y, farthest_d);

  return 0;
}
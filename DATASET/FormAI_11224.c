//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include <stdio.h>

// A unique geometric algorithm

int main() {

  int x1, y1, x2, y2;
  printf("Enter the coordinates of point 1:\n");
  printf("x1 = ");
  scanf("%d", &x1);
  printf("y1 = ");
  scanf("%d", &y1);

  printf("Enter the coordinates of point 2:\n");
  printf("x2 = ");
  scanf("%d", &x2);
  printf("y2 = ");
  scanf("%d", &y2);

  int distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  printf("The distance between the two points is %d units\n", distance);

  printf("Enter a point:\n");
  int x, y;
  printf("x = ");
  scanf("%d", &x);
  printf("y = ");
  scanf("%d", &y);

  if ((x >= x1 && x <= x2) || (x >= x2 && x <= x1)) {
    if ((y >= y1 && y <= y2) || (y >= y2 && y <= y1)) {
        printf("The point is inside or on the line segment.\n");
    } else {
        printf("The point is outside of the line segment.\n");
    }
  } else {
      printf("The point is outside of the line segment.\n");
  }

  return 0;
}
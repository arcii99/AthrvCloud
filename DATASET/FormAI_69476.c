//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shocked
#include <stdio.h>

int main() {
  printf("What?! No way! A geometric algorithm? I never thought I'd see the day.\n");
  printf("But hey, I'm always up for a challenge!\n\n");

  int x1, y1, x2, y2, x3, y3;
  printf("Alright, let's get started with some coordinates!\n");
  printf("Enter the coordinates for Point 1 (x1 y1): ");
  scanf("%d %d", &x1, &y1);

  printf("Enter the coordinates for Point 2 (x2 y2): ");
  scanf("%d %d", &x2, &y2);

  printf("Enter the coordinates for Point 3 (x3 y3): ");
  scanf("%d %d", &x3, &y3);

  printf("\nCalculating the area of our triangle...\n");

  int area = abs((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1)) / 2;
  printf("The area of our triangle is %d!\n", area);

  printf("\nAnd that's it! Another successful algorithm conquered.\n");
  return 0;
}
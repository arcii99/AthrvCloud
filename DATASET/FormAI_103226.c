//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: surprised
#include <stdio.h>

int main() {
  int sides, radius;
  float area, perimeter;

  printf("Enter the number of sides of the polygon: ");
  scanf("%d", &sides);
  printf("Enter the radius of the circle: ");
  scanf("%d", &radius);

  if (sides == 3) {
    perimeter = 3 * radius;
    area = 1.5 * radius * radius;
  } else if (sides == 4) {
    perimeter = 4 * radius;
    area = radius * radius;
  } else if (sides == 5) {
    perimeter = 5 * radius;
    area = 1.72 * radius * radius;
  } else if (sides == 6) {
    perimeter = 6 * radius;
    area = 2.598 * radius * radius;
  } else if (sides == 7) {
    perimeter = 7 * radius;
    area = 3.634 * radius * radius;
  } else if (sides == 8) {
    perimeter = 8 * radius;
    area = 4 * radius * radius;
  } else if (sides == 9) {
    perimeter = 9 * radius;
    area = 5.282 * radius * radius;
  } else {
    printf("Invalid number of sides\n");
    return 0;
  }

  printf("The area of the polygon is: %f\n", area);
  printf("The perimeter of the polygon is: %f\n", perimeter);
  printf("Wow, Isn't geometric algorithms amazing?!");

  return 0;
}
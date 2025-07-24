//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
  int sides;
  float radius, area, perimeter;

  printf("Enter the number of sides of the regular polygon: ");
  scanf("%d", &sides);

  printf("Enter the radius of the regular polygon: ");
  scanf("%f", &radius);

  // calculating the perimeter
  perimeter = 2 * sides * radius * sin(M_PI / sides);

  // calculating the area
  area = sides * radius * radius * sin((2 * M_PI) / sides) / 2;

  printf("The perimeter of the regular polygon is: %f\n", perimeter);
  printf("The area of the regular polygon is: %f\n", area);
  
  return 0;
}
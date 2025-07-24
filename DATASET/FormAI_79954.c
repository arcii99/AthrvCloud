//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include <stdio.h>
#include <math.h>

/* This program calculates the area and perimeter of a regular polygon */

int main(void) {
  int sides;
  float radius, length, apothem, perimeter, area;

  printf("Enter the number of sides of the regular polygon: ");
  scanf("%d", &sides);

  printf("Enter the length of one side of the regular polygon: ");
  scanf("%f", &length);

  /* calculate the radius */
  radius = length / (2 * sin(M_PI/sides));

  /* calculate the apothem */
  apothem = radius * cos(M_PI/sides);

  /* calculate the perimeter */
  perimeter = sides * length;

  /* calculate the area */
  area = (sides * length * apothem) / 2;

  printf("\nA regular polygon with %d sides and with a length of %.2f\n", sides, length);
  printf("has a radius of %.2f units and an apothem of %.2f units.\n", radius, apothem);
  printf("The perimeter of the polygon is %.2f units and the area is %.2f square units.\n", perimeter, area);

  return 0;
}
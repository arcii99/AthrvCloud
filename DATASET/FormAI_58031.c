//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

int main(void) {
  int choice;
  float x, y, angle, radius, perimeter, area;

  printf("Please choose a geometric shape:\n1. Circle\n2. Triangle\n3. Square\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Enter circle radius: ");
      scanf("%f", &radius);
      perimeter = 2 * M_PI * radius;
      area = M_PI * pow(radius, 2);
      printf("Circle perimeter: %f\n", perimeter);
      printf("Circle area: %f\n", area);
      break;

    case 2:
      printf("Enter triangle base: ");
      scanf("%f", &x);
      printf("Enter triangle height: ");
      scanf("%f", &y);
      angle = atan(y / x) * 180.0 / M_PI;
      perimeter = x + y + sqrt(pow(x, 2) + pow(y, 2));
      area = 0.5 * x * y;
      printf("Triangle angle: %f degrees\n", angle);
      printf("Triangle perimeter: %f\n", perimeter);
      printf("Triangle area: %f\n", area);
      break;

    case 3:
      printf("Enter square side: ");
      scanf("%f", &x);
      perimeter = 4 * x;
      area = pow(x, 2);
      printf("Square perimeter: %f\n", perimeter);
      printf("Square area: %f\n", area);
      break;

    default:
      printf("Invalid choice, please try again.\n");
      break;
  }

  return 0;
}
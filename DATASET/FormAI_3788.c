//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int a, b, c, x1, x2;
  printf("Enter values of a, b, and c in ax^2 + bx + c = 0: ");
  scanf("%d %d %d", &a, &b, &c);

  if (a == 0) {
    printf("Error: 'a' cannot be equal to zero.\n");
    return 1;
  }

  int discriminant = pow(b, 2) - 4 * a * c;

  if (discriminant < 0) {
    printf("Error: solution using real numbers does not exist.\n");
    return 1;
  } else if (discriminant == 0) {
    x1 = -b / (2 * a);
    printf("The equation has one real root: x = %d.\n", x1);
  } else {
    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("The equation has two real roots: x1 = %d, x2 = %d.\n", x1, x2);
  }

  return 0;
}
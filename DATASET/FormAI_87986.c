//FormAI DATASET v1.0 Category: Math exercise ; Style: scientific
#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c, discriminant, root1, root2, realPart, imaginaryPart;

  printf("Enter coefficients a, b and c: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  discriminant = b*b - 4*a*c;

  // condition for real and different roots
  if (discriminant > 0) {
    root1 = (-b + sqrt(discriminant)) / (2*a);
    root2 = (-b - sqrt(discriminant)) / (2*a);

    printf("Roots are: %.2lf and %.2lf", root1, root2);
  }

  // condition for real and equal roots
  else if (discriminant == 0) {
    root1 = root2 = -b / (2*a);

    printf("Roots are: %.2lf and %.2lf", root1, root2);
  }

  // if roots are not real
  else {
    realPart = -b / (2*a);
    imaginaryPart = sqrt(-discriminant) / (2*a);

    printf("Roots are: %.2lf+%.2lfi and %.2f-%.2fi", realPart, imaginaryPart, realPart, imaginaryPart);
  }

  return 0;
}
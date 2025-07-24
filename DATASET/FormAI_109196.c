//FormAI DATASET v1.0 Category: Arithmetic ; Style: multivariable
#include <stdio.h>

int main() {
  int a = 10, b = 5, c = 15;
  float d = 2.5, e = 3.5;
  double f = 20.789;
  char greet[] = "Hello, World!";
  
  printf("The value of a + b is %d\n", a+b);
  printf("The value of a - b is %d\n", a-b);
  printf("The value of a * b is %d\n", a*b);
  printf("The value of a / b is %d\n", a/b);
  printf("The value of a mod b is %d\n", a%b);

  printf("The value of b * c is %d\n", b*c);
  printf("The value of c / a is %d\n", c/a);
  printf("The value of c mod b is %d\n", c%b);

  printf("The value of d + e is %.2f\n", d+e);
  printf("The value of d - e is %.2f\n", d-e);
  printf("The value of d * e is %.2f\n", d*e);
  printf("The value of d / e is %.2f\n", d/e);
  
  printf("The value of f + d is %.3f\n", f+d);
  printf("The value of e * f is %.3f\n", e*f);
  printf("The value of f / d is %.3f\n", f/d);
  
  printf("%s\n", greet);

  return 0;
}
//FormAI DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>

int main() {
  int i = 1;
  char c = 'a';
  float f = 3.14;
  double d = 123.456;

  printf("Value of i: %d\n", i);
  printf("Value of c: %c\n", c);
  printf("Value of f: %f\n", f);
  printf("Value of d: %lf\n\n", d);

  printf("Size of int: %ld bytes\n", sizeof(int));
  printf("Size of char: %ld bytes\n", sizeof(char));
  printf("Size of float: %ld bytes\n", sizeof(float));
  printf("Size of double: %ld bytes\n\n", sizeof(double));

  printf("Type casting examples:\n");
  printf("----------------------------------\n");
  printf("After type casting, i becomes: %f\n", (float)i);
  printf("After type casting, f becomes: %d\n", (int)f);
  printf("After type casting, c becomes: %d\n", (int)c);
  printf("After type casting, d becomes: %f\n", (float)d);

  return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 10;
  int b = 25;
  int c = a*b + 5;
  int d = abs(c-100);

  printf("The value of a is: %d\n", a);
  printf("The value of b is: %d\n", b);
  printf("The value of c is: %d\n", c);
  printf("The absolute difference between c and 100 is: %d\n", d);

  if (d > 50) {
    printf("The difference between c and 100 is greater than 50.\n");
  } else {
    printf("The difference between c and 100 is less than or equal to 50.\n");
  }

  return 0;
}
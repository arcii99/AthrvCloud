//FormAI DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>

int main() {
  int a = 5;
  int b = 10;

  // ephemeral code starts here
  printf("The sum of %d and %d is %d\n", a, b, a+b);
  printf("%d multiplied by %d is %d\n", a, b, a*b);
  printf("%d divided by %d is %d with a remainder of %d\n", b, a, b/a, b%a);

  int c = a + b;
  int d = a * b;

  if (c > d) {
    printf("%d is greater than %d\n", c, d);
  } else {
    printf("%d is less than or equal to %d\n", c, d);
  }

  printf("The value of a is %d\n", a++);
  printf("The value of a now is %d\n", a);
  printf("The value of b is %d\n", --b);
  printf("The value of b now is %d\n", b);

  int e = 20;
  int f = 30;
  int g = (e > f) ? e : f;

  printf("The value of g is %d\n", g);
  // ephemeral code ends here

  return 0;
}
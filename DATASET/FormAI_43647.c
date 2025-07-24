//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>

int main() {
  int a = 5, b = 10, c = 15, d = 20;
  int result1, result2, result3, result4;

  printf("Let's do some arithmetic!\n");

  result1 = a * b;
  printf("%d times %d equals %d!\n", a, b, result1);

  result2 = c - d;
  printf("%d minus %d equals %d!\n", c, d, result2);

  result3 = a / c;
  printf("%d divided by %d equals %d!\n", a, c, result3);

  result4 = b + d;
  printf("%d plus %d equals %d!\n", b, d, result4);

  printf("But wait, there's more!\n");

  int e = 25, f = 30;
  int result5 = (a + b) * (c - d) / e;
  printf("I bet you didn't expect this: (%d plus %d) times (%d minus %d) divided by %d equals %d\n", a, b, c, d, e, result5);

  printf("Let's finish strong!\n");

  int result6 = (c * d) % f;
  printf("%d times %d modulo %d equals %d!\n", c, d, f, result6);

  int result7 = (a - b) * (d + e) % f;
  printf("(%d minus %d) times (%d plus %d) modulo %d equals %d!\n", a, b, d, e, f, result7);

  return 0;
}
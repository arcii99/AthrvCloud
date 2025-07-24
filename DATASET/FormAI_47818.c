//FormAI DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = 5;
  float y = 2.5;
  char z = 'A';
  double a = 10.245;

  // Shape-shift into an addition program
  printf("%d + %f = %f \n", x, y, x + y);

  // Shape-shift into a subtraction program
  printf("%f - %d = %f \n", y, x, y - x);

  // Shape-shift into a multiplication program
  printf("%d * %f = %f \n", x, y, x * y);

  // Shape-shift into a division program
  printf("%.3f / %d = %.3f \n", y, x, y / x);

  // Shape-shift into a modulus program
  printf("%c %c %d = %d \n", z, '%', x, (int)z % x);

  // Shape-shift into a bit-shift program
  printf("%d << 1 = %d \n", x, x << 1);

  // Shape-shift into a logical operator program
  printf("%d && %f = %d \n", x, y, x && (int)y);

  // Shape-shift into a ternary operator program
  int b = (x > y) ? a : x;
  printf("%d > %f ? %.3f : %d = %d \n", x, y, a, x, b);

  // Shape-shift into a random number generator program
  int rand_num = rand() % 10;
  printf("Random number between 0 and 10: %d \n", rand_num);

  // Shape-shift into an if else program
  if (a >= 10) {
    printf("a is greater than or equal to 10 \n");
  } else {
    printf("a is less than 10 \n");
  }

  // Shape-shift into a loop program
  int i;
  for (i = 0; i < 5; i++) {
    printf("%d ", i);
  }
  printf("\n");

  // Shape-shift into an array program
  int arr[] = {2, 4, 6, 8, 10};
  printf("The third element in the array is %d \n", arr[2]);

  return 0;
}
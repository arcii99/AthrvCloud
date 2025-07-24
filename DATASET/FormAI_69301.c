//FormAI DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>

int main() {
  int num_one = 10;
  int num_two = 5;
  int result;

  printf("Let's perform some arithmetic operations!\n");

  printf("Addition:\n");
  result = num_one + num_two;
  printf("%d + %d = %d\n", num_one, num_two, result);

  printf("Subtraction:\n");
  result = num_one - num_two;
  printf("%d - %d = %d\n", num_one, num_two, result);

  printf("Multiplication:\n");
  result = num_one * num_two;
  printf("%d * %d = %d\n", num_one, num_two, result);

  printf("Division:\n");
  result = num_one / num_two;
  printf("%d / %d = %d\n", num_one, num_two, result);

  printf("Modulus:\n");
  result = num_one % num_two;
  printf("%d %% %d = %d\n", num_one, num_two, result);

  printf("Increment:\n");
  result = num_one++;
  printf("num_one++ = %d\n", result);

  printf("Decrement:\n");
  result = num_two--;
  printf("num_two-- = %d\n", result);

  return 0;
}
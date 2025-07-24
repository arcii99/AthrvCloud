//FormAI DATASET v1.0 Category: Bitwise operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1 = 13, num2 = 7; // let's start with some happy numbers

  printf("The bitwise AND of %d and %d is %d\n", num1, num2, num1 & num2);
  printf("The bitwise OR of %d and %d is %d\n", num1, num2, num1 | num2);
  printf("The bitwise XOR of %d and %d is %d\n", num1, num2, num1 ^ num2);
  printf("The bitwise NOT of %d is %d\n", num1, ~num1);
  printf("The bitwise left shift of %d by 2 is %d\n", num1, num1 << 2);
  printf("The bitwise right shift of %d by 2 is %d\n", num1, num1 >> 2);

  // Let's do something fun with bitwise operations

  int random_num = rand() % 100; // generate a random number
  printf("Here's a random number between 0 and 99: %d\n", random_num);

  int binary_num = 0, i = 1; // let's convert it to binary using bitwise operations
  while (random_num > 0) {
    binary_num += (random_num % 2) * i;
    random_num /= 2;
    i *= 10;
  }

  printf("In binary, that number is %06d\n", binary_num);

  int flipped_num = ~binary_num; // let's flip all the bits
  printf("If we flip all the bits, we get %06d\n", flipped_num);

  int shifted_num = flipped_num << 2; // let's shift the bits to the left by 2
  printf("If we shift all the bits to the left by 2, we get %06d\n", shifted_num);

  int result = shifted_num & binary_num; // let's do a bitwise AND with the original number
  printf("If we AND the original number with the shifted number, we get %06d\n", result);

  if (result == 0) {
    printf("It worked! The original number is now completely different.\n");
  } else {
    printf("Oops, something went wrong. The original number is still there.\n");
  }

  return 0;
}
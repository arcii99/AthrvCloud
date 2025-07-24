//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Hello, let's play with Bitwise operations!\n");
  printf("Enter two numbers to perform operations on: \n");
  int num1, num2;
  scanf("%d %d", &num1, &num2);
  
  // Bitwise AND
  printf("The Bitwise AND of %d and %d is: %d\n", num1, num2, num1 & num2);
  
  // Bitwise OR
  printf("The Bitwise OR of %d and %d is: %d\n", num1, num2, num1 | num2);
  
  // Bitwise XOR
  printf("The Bitwise XOR of %d and %d is: %d\n", num1, num2, num1 ^ num2);
  
  // Bitwise NOT
  printf("The Bitwise NOT of %d is: %d\n", num1, ~num1);

  // Left shift
  printf("Enter the number of bits to shift left: ");
  int lshift;
  scanf("%d", &lshift);
  printf("Shifting %d left by %d bits, we get: %d\n", num1, lshift, num1<<lshift);
  
  // Right shift
  printf("Enter the number of bits to shift right: ");
  int rshift;
  scanf("%d", &rshift);
  printf("Shifting %d right by %d bits, we get: %d\n", num1, rshift, num1>>rshift);

  return 0;
}
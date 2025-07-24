//FormAI DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>

int main() {
  int x = 10;
  int y = 20;
  int z;
  
  // Addition
  z = x + y;
  printf("Addition of %d and %d is %d\n", x, y, z);
  
  // Subtraction
  z = x - y;
  printf("Subtraction of %d and %d is %d\n", x, y, z);

  // Multiplication
  z = x * y;
  printf("Multiplication of %d and %d is %d\n", x, y, z);

  // Division
  z = x / y;
  printf("Division of %d and %d is %d\n", x, y, z);
  
  // Modulus
  z = x % y;
  printf("Modulus of %d and %d is %d\n", x, y, z);

  // Increment
  x++;
  printf("Increment of %d is %d\n", x-1, x);

  // Decrement
  y--;
  printf("Decrement of %d is %d\n", y+1, y);

  // Bitwise AND
  z = x & y;
  printf("Bitwise AND of %d and %d is %d\n", x, y, z);

  // Bitwise OR
  z = x | y;
  printf("Bitwise OR of %d and %d is %d\n", x, y, z);

  // Bitwise XOR
  z = x ^ y;
  printf("Bitwise XOR of %d and %d is %d\n", x, y, z);

  // Bitwise NOT
  z = ~x;
  printf("Bitwise NOT of %d is %d\n", x, z);

  return 0;
}
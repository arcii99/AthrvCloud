//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>

int main() {
  int x = 10;
  int y = 5;
  int z;
  
  printf("The value of x is: %d\n", x);
  printf("The value of y is: %d\n", y);
  
  // Addition
  z = x + y;
  printf("Addition: %d + %d = %d\n", x, y, z);
  
  // Subtraction
  z = x - y;
  printf("Subtraction: %d - %d = %d\n", x, y, z);
  
  // Multiplication
  z = x * y;
  printf("Multiplication: %d * %d = %d\n", x, y, z);
  
  // Division
  z = x / y;
  printf("Division: %d / %d = %d\n", x, y, z);
  
  // Modulus
  z = x % y;
  printf("Modulus: %d %% %d = %d\n", x, y, z);
  
  // Increment
  x++;
  printf("Increment of x: %d\n", x);
  
  // Decrement
  y--;
  printf("Decrement of y: %d\n", y);
  
  // Compound assignment
  x += 5; // equivalent to x = x + 5
  printf("Compound assignment: %d\n", x);
  
  return 0;
}
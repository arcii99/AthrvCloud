//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Alan Touring
#include <stdio.h>

// Define a function to display the binary representation of an integer
void display_binary(unsigned int num) {
  int bit;
  for (bit = 31; bit >= 0; bit--) {
    putchar((num & (1u << bit)) ? '1' : '0');
  }
  putchar('\n');
}

int main(void) {
  // Define two unsigned integers
  unsigned int a = 0xABCD;
  unsigned int b = a;

  // Display their binary representations
  printf("a = ");
  display_binary(a);
  printf("b = ");
  display_binary(b);

  // Perform bitwise AND operation
  printf("a & b = ");
  display_binary(a & b);

  // Perform bitwise OR operation
  printf("a | b = ");
  display_binary(a | b);

  // Perform bitwise XOR operation
  printf("a ^ b = ");
  display_binary(a ^ b);

  // Perform bitwise NOT operation
  printf("~a = ");
  display_binary(~a);

  // Perform left shift operation
  printf("a << 4 = ");
  display_binary(a << 4);

  // Perform right shift operation
  printf("a >> 4 = ");
  display_binary(a >> 4);

  return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the Bitwise Operation Fun House!\n");
  printf("Let's start with some simple operations:\n");
  
  int a = 5; // 0101 binary
  int b = 3; // 0011 binary
  
  // AND operation
  printf("AND Operation:\n");
  printf("a & b = %d\n", a & b); // 0001 binary
  
  // OR operation
  printf("OR Operation:\n");
  printf("a | b = %d\n", a | b); // 0111 binary
  
  // XOR operation
  printf("XOR Operation:\n");
  printf("a ^ b = %d\n", a ^ b); // 0110 binary
  
  // NOT operation
  printf("NOT Operation:\n");
  printf("~a = %d\n", ~a); // 1010 binary
  
  printf("Wow, that was easy!\n");
  
  printf("Now let's kick it up a notch with some bitwise shifting:\n");
  
  int c = 10; // 1010 binary
  
  // Left shift
  printf("Left Shift:\n");
  printf("c << 2 = %d\n", c << 2); // 101000 binary
  
  // Right shift
  printf("Right Shift:\n");
  printf("c >> 1 = %d\n", c >> 1); // 0101 binary
  
  printf("Who knew shifting bits could be so much fun?\n");
  
  printf("Last but not least, let's try some bitwise assignment:\n");
  
  int d = 7; // 0111 binary
  
  // Bitwise AND assignment
  printf("Bitwise AND Assignment:\n");
  d &= 5; // 0101 binary
  printf("d after &= 5: %d\n", d); // 0101 binary
  
  // Bitwise OR assignment
  printf("Bitwise OR Assignment:\n");
  d |= 3; // 0111 binary
  printf("d after |= 3: %d\n", d); // 0111 binary
  
  // Bitwise XOR assignment
  printf("Bitwise XOR Assignment:\n");
  d ^= 6; // 0101 binary
  printf("d after ^= 6: %d\n", d); // 0101 binary
  
  printf("Hope you had as much fun as I did with these Bitwise Operations!\n");
  
  return 0;
}
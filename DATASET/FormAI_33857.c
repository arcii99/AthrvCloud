//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>

int main() {
  unsigned int a = 165567; 
  unsigned int b = 987602;
  
  // OR operation
  unsigned int orOp = a | b;
  printf("OR Operation: %u\n", orOp);
  
  // AND operation
  unsigned int andOp = a & b;
  printf("AND Operation: %u\n", andOp);
  
  // XOR operation
  unsigned int xorOp = a ^ b;
  printf("XOR Operation: %u\n", xorOp);
  
  // Left shift operation
  unsigned int leftShiftOp = a << 3;
  printf("Left Shift Operation: %u\n", leftShiftOp);
  
  // Right shift operation
  unsigned int rightShiftOp = a >> 2;
  printf("Right Shift Operation: %u\n", rightShiftOp);
  
  // Compliment operation
  unsigned int complimentOp = ~a;
  printf("Compliment Operation: %u\n", complimentOp);
  
  return 0;
}
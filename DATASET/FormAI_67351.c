//FormAI DATASET v1.0 Category: Bitwise operations ; Style: lively
#include<stdio.h>

int main(){
  int x = 7;  // binary value: 00000111
  int y = 9;  // binary value: 00001001
  
  // Bitwise AND operation
  printf("Result of x & y: %d\n", x & y);  // Expected output: 1 (00000001)
  
  // Bitwise OR operation
  printf("Result of x | y: %d\n", x | y);  // Expected output: 15 (00001111)
  
  // Bitwise XOR operation
  printf("Result of x ^ y: %d\n", x ^ y);  // Expected output: 14 (00001110)
  
  // Bitwise NOT operation
  printf("Result of ~x: %d\n", ~x);  // Expected output: -8 (11111000)
  
  // Bitwise left shift operation
  printf("Result of x << 2: %d\n", x << 2);  // Expected output: 28 (00011100)
  
  // Bitwise right shift operation
  printf("Result of x >> 2: %d\n", x >> 2);  // Expected output: 1 (00000001)
  
  return 0;
}
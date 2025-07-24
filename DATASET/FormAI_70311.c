//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int num = 100;
  unsigned int half_num = num >> 1;
  unsigned int double_num = num << 1;
  
  // Print the initial number
  printf("%u\n", num);
  
  // Right shift the number
  printf("%u shifted right is: %u\n", num, half_num);
  
  // Left shift the number
  printf("%u shifted left is: %u\n", num, double_num);
  
  // Bitwise AND operation with 5
  unsigned int and_num = num & 5;
  printf("%u AND 5 is: %u\n", num, and_num);
  
  // Bitwise OR operation with 10
  unsigned int or_num = num | 10;
  printf("%u OR 10 is: %u\n", num, or_num);
  
  // Bitwise XOR operation with 15
  unsigned int xor_num = num ^ 15;
  printf("%u XOR 15 is: %u\n", num, xor_num);
  
  // Bitwise NOT operation
  unsigned int not_num = ~num;
  printf("NOT %u is: %u\n", num, not_num);
  
  // Bitwise shift and assign
  num >>= 2;
  printf("After shifting right by 2, num is: %u\n", num);
  
  // Bitwise OR and assign
  num |= 12;
  printf("After ORing with 12, num is: %u\n", num);
  
  // Bitwise XOR and assign
  num ^= 8;
  printf("After XORing with 8, num is: %u\n", num);
  
  // Bitwise NOT and assign
  num = ~num;
  printf("After NOTing, num is: %u\n", num);
  
  return 0;
}
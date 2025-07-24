//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

int main() {
  int a = 21;
  int b = 19;
  int c;

  printf("Using Bitwise Operations to Solve Statistics Problems\n\n");

  c = (~a);     
  printf("1. One's Complement of %d is %d\n", a, c);

  c = a & b;   
  printf("2. Bitwise AND of %d and %d is %d\n", a, b, c);

  c = a | b;    
  printf("3. Bitwise OR of %d and %d is %d\n", a, b, c);
  
  c = a ^ b;     
  printf("4. Bitwise XOR of %d and %d is %d\n", a, b, c);

  c = a << 2;   
  printf("5. Left shift of %d by 2 is %d\n", a, c);

  c = b >> 2;   
  printf("6. Right shift of %d by 2 is %d\n", b, c);

  return 0;
}
//FormAI DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
      int a = 25, b = 30; 

      printf("a = %d, b = %d\n", a, b); 

      a = a ^ b; // 25 XOR 30 = 7
      b = a ^ b; // 7 XOR 30 = 25
      a = a ^ b; // 7 XOR 25 = 30

      printf("\nAfter Swapping\n");
      printf("a = %d, b = %d\n", a, b); 

      return 0; 
}
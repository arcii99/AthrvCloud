//FormAI DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>

int main() {
  int x = 10;
  int y = 5;
  
  // Addition Operation
  int sum = x + y;
  printf("Addition: %d + %d = %d\n", x, y, sum);

  // Subtraction Operation
  int diff = x - y;
  printf("Subtraction: %d - %d = %d\n", x, y, diff);

  // Multiplication Operation
  int prod = x * y;
  printf("Multiplication: %d * %d = %d\n", x ,y, prod);
  
  // Division Operation
  int quo = x / y;
  printf("Division: %d / %d = %d\n", x, y, quo);

  // Modulus Operation
  int mod = x % y;
  printf("Modulus: %d %% %d = %d\n", x, y, mod);

  // Increment Operation
  int i = 0;
  printf("Pre-Increment: ++i = %d\n", ++i);
  printf("Post-Increment: i++ = %d\n", i++);
  printf("Value of i after Post-Increment: %d\n", i);

  // Decrement Operation
  int j = 0;
  printf("Pre-Decrement: --j = %d\n", --j);
  printf("Post-Decrement: j-- = %d\n", j--);
  printf("Value of j after Post-Decrement: %d\n", j);

  return 0;
}
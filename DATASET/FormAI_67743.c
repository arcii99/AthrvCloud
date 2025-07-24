//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() {
  /* Let's create two variables with initial values */
  int num1 = 10;
  int num2 = 5;
  
  /* Perform Bitwise operations on the variables */
  
  /* Bitwise AND */
  int result_1 = num1 & num2;
  
  /* Bitwise OR */
  int result_2 = num1 | num2;
  
  /* Bitwise XOR */
  int result_3 = num1 ^ num2;
  
  /* Bitwise LEFT SHIFT */
  int result_4 = num1 << 1;
  
  /* Bitwise RIGHT SHIFT */
  int result_5 = num1 >> 1;
  
  /* Display the results */
  printf("Bitwise AND of %d and %d is %d\n", num1, num2, result_1);
  printf("Bitwise OR of %d and %d is %d\n", num1, num2, result_2);
  printf("Bitwise XOR of %d and %d is %d\n", num1, num2, result_3);
  printf("Bitwise LEFT SHIFT of %d is %d\n", num1, result_4);
  printf("Bitwise RIGHT SHIFT of %d is %d\n", num1, result_5);
  
  /* Let's create another variable with some random value */
  int num3 = 28;
  
  /* Bitwise NOT */
  int result_6 = ~num3;
  
  /* Display the result of Bitwise NOT */
  printf("Bitwise NOT of %d is %d\n", num3, result_6);
  
  return 0; /* Program execution completed. */
}
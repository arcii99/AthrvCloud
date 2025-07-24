//FormAI DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>

int main() {
  int a = 5, b = 10, c = 15;
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  
  // Addition
  printf("\nAddition:\n");
  int result = a + b + c;
  printf("a + b + c = %d\n", result);
  
  // Subtraction
  printf("\nSubtraction:\n");
  result = c - b - a;
  printf("c - b - a = %d\n", result);
  
  // Multiplication
  printf("\nMultiplication:\n");
  result = a * b * c;
  printf("a * b * c = %d\n", result);
  
  // Division
  printf("\nDivision:\n");
  float a_f = (float)a;
  float b_f = (float)b;
  float c_f = (float)c;
  float float_result = c_f / b_f / a_f;
  printf("c / b / a = %f\n", float_result);
  
  // Modulo
  printf("\nModulo:\n");
  result = c % b % a;
  printf("c %% b %% a = %d\n", result);
  
  return 0;
}
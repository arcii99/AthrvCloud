//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>

int main() {
  int num1, num2;
  float result;
  
  printf("Enter the first integer: ");
  scanf("%d", &num1);
  
  printf("Enter the second integer: ");
  scanf("%d", &num2);
  
  result = (float)num1 / (float)num2; // Type cast to float for accurate result
  
  printf("The result of %d divided by %d is: %.2f", num1, num2, result); // Limiting result to two decimal places
  return 0;
}
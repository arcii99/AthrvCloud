//FormAI DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>

int main() {
  int num1, num2, result;
  
  printf("Enter a number: ");
  scanf("%d", &num1);
  
  printf("Enter another number: ");
  scanf("%d", &num2);
  
  result = num1 * num2;
  
  if (result > 100) {
    printf("WARNING: Result exceeds 100!\n");
  }
  
  if (num1 < 0 || num2 < 0) {
    printf("ALERT: Negative numbers detected!\n");
  }
  
  if (num1 == num2) {
    printf("CAUTION: Both numbers are equal!\n");
  }
  
  printf("The result is: %d\n", result);
  
  return 0;
}
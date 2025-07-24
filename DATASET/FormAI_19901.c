//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>

int main() {
  int num, deno, result;
  
  printf("Enter numerator: ");
  scanf("%d", &num);
  
  printf("Enter denominator: ");
  scanf("%d", &deno);
  
  if(deno == 0) {
    printf("Error: Division by zero is undefined! Please provide non-zero denominator.\n");
  } else {
    result = num / deno;
    printf("Result: %d\n", result);
  }
  
  return 0;
}
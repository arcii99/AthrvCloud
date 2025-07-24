//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  int numerator, denominator, result;
  printf("Enter numerator: ");
  scanf("%d", &numerator);

  printf("Enter denominator: ");
  scanf("%d", &denominator);

  if(denominator == 0) {
    printf("Error: Cannot divide by zero\n");
    exit(0);
  }

  result = numerator / denominator;

  printf("%d / %d = %d\n", numerator, denominator, result); 
  return 0;
}
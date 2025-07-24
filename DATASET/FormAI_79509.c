//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {

  int num1, num2, result;

  printf("Let's perform some division!\n");
  printf("Enter the first number: ");
  if(scanf("%d", &num1)) {
    printf("Enter the second number: ");
    if(scanf("%d", &num2)) {
      if(num2 == 0) {
        printf("Cannot divide by zero!\n");
        exit(1);
      }
      result = num1 / num2;
      printf("%d / %d = %d\n", num1, num2, result);
    } else {
      printf("Invalid input.\n");
      exit(1);
    }
  } else {
    printf("Invalid input.\n");
    exit(1);
  }

  return 0;
}
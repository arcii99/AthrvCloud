//FormAI DATASET v1.0 Category: Error handling ; Style: enthusiastic
#include <stdio.h>

int main() {
  int num1, num2;
  printf("Enter two numbers to divide: \n");
  scanf("%d %d", &num1, &num2);
  if(num2 == 0) {
    printf("Oops! Cannot divide by zero!\n");
    return 1;
  }
  int result = num1 / num2;
  printf("%d divided by %d is equal to %d\n", num1, num2, result);
  return 0;
}
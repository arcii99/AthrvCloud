//FormAI DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void handleError(int error) {
  printf("Error code: %d\n", error);
  exit(1);
}

int main() {
  int num1, num2;
  printf("Enter two numbers:\n");
  if (scanf("%d %d", &num1, &num2) != 2) {
    handleError(1);
  }
  if (num2 == 0) {
    handleError(2);
  }
  int result = num1 / num2;
  printf("%d / %d = %d\n", num1, num2, result);
  return 0;
}
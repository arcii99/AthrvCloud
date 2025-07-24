//FormAI DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>

// Given three numbers, finds the largest number.
int main() {
  int num1, num2, num3;
  printf("Please enter three numbers: ");
  scanf("%d%d%d", &num1, &num2, &num3);

  // checks if num1 is the largest number
  if (num1 >= num2) {
    if (num1 >= num3) {
      printf("%d is the largest number.\n", num1);
    } else {
      printf("%d is the largest number.\n", num3);
    }
  }

  // checks if num2 is the largest number
  else if (num2 >= num3) {
    printf("%d is the largest number.\n", num2);
  }

  // checks if num3 is the largest number
  else {
    printf("%d is the largest number.\n", num3);
  }
  
  return 0;
}
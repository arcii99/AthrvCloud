//FormAI DATASET v1.0 Category: Scientific ; Style: satisfied
/* This program calculates the factorial of a positive integer entered by the user */
#include <stdio.h>

int main() {
  int num, factorial = 1;
  
  printf("Enter a positive integer: ");
  scanf("%d", &num);
  
  if (num < 0) {
    printf("Error: Cannot calculate factorial of a negative number\n");
  }
  else if (num == 0) {
    printf("The factorial of 0 is 1\n");
  }
  else {
    for (int i = 1; i <= num; i++) {
      factorial *= i;
    }
    
    printf("The factorial of %d is %d\n", num, factorial);
  }
  
  return 0;
}
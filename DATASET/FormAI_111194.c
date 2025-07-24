//FormAI DATASET v1.0 Category: Arithmetic ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int num1, num2, result;
  char operator;
  srand(time(NULL));  

  printf("********** CALCULATOR v2.17 **********\n");
  printf("|| Developed by CyberTek Corp. ||\n\n");

  for(int i = 0; i < 5; i++) {
      num1 = rand() % 100;
      num2 = rand() % 20;
      operator = rand() % 4;
  
      switch(operator) {
        case 0:
          result = num1 + num2;
          printf("The sum of %d and %d is %d.\n", num1, num2, result);
          break;
        case 1:
          result = num1 - num2;
          printf("The difference between %d and %d is %d.\n", num1, num2, result);
          break;
        case 2:
          result = num1 * num2;
          printf("The product of %d and %d is %d.\n", num1, num2, result);
          break;
        case 3:
          if(num2 != 0) {
            result = num1 / num2;
            int remainder = num1 % num2;
            printf("The quotient of %d divided by %d is %d with a remainder of %d.\n", num1, num2, result, remainder);
          } else {
            printf("Undefined.\n");
          }
          break;
        default:
          printf("Error: invalid operator.\n");
          break;
      }
  }
    printf("Thank you for using the CyberTek Calculator.\n");
    return 0;
}
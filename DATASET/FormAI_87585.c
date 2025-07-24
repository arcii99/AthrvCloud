//FormAI DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
   int num1, num2, result;

   printf("Enter the first number: ");
   scanf("%d", &num1);

   printf("Enter the second number: ");
   if (scanf("%d", &num2) != 1) {
      printf("Invalid input: not a number\n");
      exit(1);
   }

   if (num2 == 0) {
      printf("Error: division by zero\n");
      exit(1);
   }

   result = num1 / num2;
   printf("%d divided by %d is %d\n", num1, num2, result);

   return 0;
}
//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {

   int num1, num2;
   float result;

   printf("Enter num1: ");
   if(scanf("%d", &num1) != 1) {
      printf("Oops! Invalid input!\n");
      exit(EXIT_FAILURE);
   }

   printf("Enter num2: ");
   if(scanf("%d", &num2) != 1) {
      printf("Oops! Invalid input!\n");
      exit(EXIT_FAILURE);
   }
   
   /* divide by zero handling */
   if(num2 == 0) {
      printf("Oops! Division by zero error!\n");
      exit(EXIT_FAILURE);
   }

   result = num1 / num2;

   /* handling floating point exception */
   if(result == ((float) 10 / 0)) {
      printf("Oops! Floating point exception error!\n");
      exit(EXIT_FAILURE);
   }

   printf("%d divided by %d is %.2f\n", num1, num2, result);

   return 0;
}
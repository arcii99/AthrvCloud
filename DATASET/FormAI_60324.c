//FormAI DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int num1, num2, result;
   printf("Welcome to the happiest calculation program ever!\n");
   printf("Please enter two numbers to divide: ");
   if(scanf("%d %d", &num1, &num2) != 2) {
      printf("Oops, looks like you didn't enter two numbers! Let's try that again!\n");
      exit(1);
   }
   if(num2 == 0) {
      printf("Oops, you tried to divide by zero! That's not possible. Don't worry though, we'll fix it!\n");
      num2++;
   }
   result = num1 / num2;
   printf("The result of %d divided by %d is %d and we did it with a smile!\n", num1, num2, result);
   return 0;
}
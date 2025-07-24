//FormAI DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Generate two random numbers within the range of 1 to 100
   srand(time(NULL));
   int num1 = rand() % 100 + 1;
   int num2 = rand() % 100 + 1;
  
   // Check whether num1 is greater than num2
   if (num1 > num2) {
      // If num1 is greater, subtract num2 from num1 and print the result
      int result = num1 - num2;
      printf("%d is greater than %d\n", num1, num2);
      printf("%d - %d = %d\n", num1, num2, result);
   } else {
      // If num2 is greater, add num2 to num1 and print the result
      int result = num1 + num2;
      printf("%d is greater than %d\n", num2, num1);
      printf("%d + %d = %d\n", num1, num2, result);
   }
   return 0;
}
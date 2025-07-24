//FormAI DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>

int main() {
   int num1, num2, results;
   
   printf("Enter the first number: ");
   scanf("%d", &num1);
   
   printf("Enter the second number: ");
   scanf("%d", &num2);
   
   results = num1 + num2;
   printf("The result of %d + %d = %d\n", num1, num2, results);
   
   results = num1 - num2;
   printf("The result of %d - %d = %d\n", num1, num2, results);
   
   results = num1 * num2;
   printf("The result of %d * %d = %d\n", num1, num2, results);
   
   if (num2 == 0) {
      printf("Cannot divide by zero\n");
   }
   else {
      results = num1 / num2;
      printf("The result of %d / %d = %d\n", num1, num2, results);
   }
   
   return 0;
}
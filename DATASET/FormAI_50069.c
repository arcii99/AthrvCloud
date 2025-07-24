//FormAI DATASET v1.0 Category: Syntax parsing ; Style: excited
#include <stdio.h>

int main() {
   int num1, num2;

   printf("Enter two integer values: ");
   scanf("%d %d", &num1, &num2);

   printf("\nWow! You entered %d and %d!\n\n", num1, num2);

   if (num1 > num2) {
      printf("Number %d is greater than %d\n", num1, num2);
   }
   else if (num2 > num1) {
      printf("Number %d is greater than %d\n", num2, num1);
   }
   else {
      printf("Both numbers are equal!\n");
   }

   printf("\nDo you want to see another example? (y/n)\n");

   char choice = getchar();

   if (choice == 'y') {
      printf("\nGreat, let's try some arithmetic operations!\n");
      int sum = num1 + num2;
      int difference = num1 - num2;
      int product = num1 * num2;
      int quotient = num1 / num2;

      printf("\nThe sum of %d and %d is: %d\n", num1, num2, sum);
      printf("The difference between %d and %d is: %d\n", num1, num2, difference);
      printf("The product of %d and %d is: %d\n", num1, num2, product);
      printf("The quotient of %d and %d is: %d\n", num1, num2, quotient);
   }
   else {
      printf("\nAlright then, thanks for trying out this program!\n");
   }

   return 0;
}
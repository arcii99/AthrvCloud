//FormAI DATASET v1.0 Category: Educational ; Style: lively
#include <stdio.h>

int main() {
   int num1, num2, sum;
   
   printf("Enter a number: ");
   scanf("%d", &num1);
   
   printf("Enter another number: ");
   scanf("%d", &num2);

   sum = num1 + num2;

   printf("The sum of %d and %d is %d.\n", num1, num2, sum);

   if (sum % 2 == 0) {
      printf("The sum is even.\n");
   } else {
      printf("The sum is odd.\n");
   }

   if (num1 > num2) {
      printf("%d is greater than %d.\n", num1, num2);
   } else if (num2 > num1) {
      printf("%d is greater than %d.\n", num2, num1);
   } else {
      printf("%d and %d are equal.\n", num1, num2);
   }

   return 0;
}
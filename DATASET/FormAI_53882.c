//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>

int main() {
   int input1, input2, sum, difference, product, quotient, remainder;
   printf("Enter two numbers: ");
   scanf("%d %d", &input1, &input2);

   sum = input1 + input2;
   difference = input1 - input2;
   product = input1 * input2;
   quotient = input1 / input2;
   remainder = input1 % input2;

   printf("\nSum of %d and %d is %d", input1, input2, sum);
   printf("\nDifference of %d and %d is %d", input1, input2, difference);
   printf("\nProduct of %d and %d is %d", input1, input2, product);
   printf("\nQuotient of %d and %d is %d", input1, input2, quotient);
   printf("\nRemainder of %d and %d is %d", input1, input2, remainder);

   return 0;
}
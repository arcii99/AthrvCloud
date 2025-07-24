//FormAI DATASET v1.0 Category: Scientific ; Style: sophisticated
#include <stdio.h>

int main() {
   int num1, num2, num3, sum, product;
   float average;
 
   printf("Enter three integers separated by a space: ");
   scanf("%d %d %d", &num1, &num2, &num3);
 
   sum = num1 + num2 + num3;
   product = num1 * num2 * num3;
   average = (float)(sum) / 3;
 
   printf("The sum of %d, %d, and %d is: %d\n", num1, num2, num3, sum);
   printf("The product of %d, %d, and %d is: %d\n", num1, num2, num3, product);
   printf("The average of %d, %d, and %d is: %0.2f\n", num1, num2, num3, average);
 
   return 0;
}
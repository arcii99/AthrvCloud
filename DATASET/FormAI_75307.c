//FormAI DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>

int main() {

   int num1, num2, num3, sum;
   float avg;

   printf("Enter the first number: ");
   scanf("%d", &num1);

   printf("Enter the second number: ");
   scanf("%d", &num2);

   printf("Enter the third number: ");
   scanf("%d", &num3);

   sum = num1 + num2 + num3;

   avg = (float)sum / 3;

   printf("\nSum of the numbers: %d", sum);
   printf("\nAverage of the numbers: %.2f", avg);

   return 0;
}
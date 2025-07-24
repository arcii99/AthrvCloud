//FormAI DATASET v1.0 Category: Error handling ; Style: enthusiastic
#include<stdio.h>

int main() {
   int num, den;
   float quotient;

   printf("Enter numerator: ");
   scanf("%d", &num);
   printf("Enter denominator: ");
   scanf("%d", &den);

   if (den == 0) {
      printf("Error: Division by zero\n");
      printf("Enter denominator again: ");
      scanf("%d", &den);
   }

   quotient = (float)num / den;

   printf("Quotient = %f\n", quotient);

   return 0;
}
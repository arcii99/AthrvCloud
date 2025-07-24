//FormAI DATASET v1.0 Category: Calculator ; Style: grateful
#include <stdio.h>

int main()
{
   int a, b, sum, diff, prod;
   float div;

   printf("Hey! I am a calculator bot.\n");
   printf("Please enter two numbers: \n");
   scanf("%d%d", &a, &b);

   sum = a + b;
   diff = a - b;
   prod = a * b;
   
   if(b != 0)
   {
      div = (float)a / (float)b;
      printf("The division of %d and %d is %.2f\n", a, b, div);
   }
   else
   {
      printf("Cannot calculate the division by 0\n");
   }

   printf("The addition of %d and %d is %d\n", a, b, sum);
   printf("The difference of %d and %d is %d\n", a, b, diff);
   printf("The product of %d and %d is %d\n", a, b, prod);

   printf("Thank you for using me. Always here to help you!\n");

   return 0;
}
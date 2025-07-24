//FormAI DATASET v1.0 Category: Arithmetic ; Style: authentic
#include<stdio.h>

int main()
{
   int a, b, sum, diff, pro, div;
   
   printf("Enter the first number: ");
   scanf("%d", &a);
   
   printf("Enter the second number: ");
   scanf("%d", &b);
   
   sum = a + b;
   printf("\nThe sum of %d and %d is %d.", a, b, sum);
   
   diff = a - b;
   printf("\nThe difference of %d and %d is %d.", a, b, diff);
   
   pro = a * b;
   printf("\nThe product of %d and %d is %d.", a, b, pro);
   
   div = a / b;
   printf("\nThe quotient of %d and %d is %d.", a, b, div);
   
   return 0;
}
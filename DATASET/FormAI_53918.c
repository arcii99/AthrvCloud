//FormAI DATASET v1.0 Category: Syntax parsing ; Style: real-life
#include<stdio.h>

int main() {
   int num1, num2, sum;
   printf("Enter two numbers:");
   scanf("%d %d", &num1, &num2);   //get input from the user

   sum = num1 + num2;   //add the numbers

   if(sum % 2 == 0) {
      printf("The sum is even!\n");
   }
   else {
      printf("The sum is odd!\n");
   }

   return 0;
}
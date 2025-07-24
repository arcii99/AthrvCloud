//FormAI DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include<stdio.h>

int factorial(int n) {
   if(n<=1){
      return 1;
   } else {
      return n * factorial(n-1);
   }
}

int main() {
   int num,fact;
   
   printf("Enter a non-negative integer: ");
   scanf("%d",&num);

   if (num < 0) {
       printf("Invalid input\n");
   } else {
       fact = factorial(num);
       printf("Factorial of %d is %d", num, fact);
   }

   return 0;
}
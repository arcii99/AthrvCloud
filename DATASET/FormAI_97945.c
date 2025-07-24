//FormAI DATASET v1.0 Category: Funny ; Style: recursive
#include <stdio.h>

int sum(int num) {
   if(num != 0)
       return num + sum(num-1);
   else
       return num;
}

int factorial(int num) {
   if(num == 0)
       return 1;
   else
       return(num * factorial(num-1));
}

int fibonacci(int num) {
   if(num == 0)
       return 0;
   else if(num == 1)
       return 1;
   else
       return (fibonacci(num-1) + fibonacci(num-2));
}

int main() {
   int num;
   
   printf("Enter a positive integer: ");
   scanf("%d",&num);

   printf("\n Sum of first %d natural numbers : %d \n", num, sum(num));
   
   printf("\n Factorial of %d is: %d \n", num, factorial(num));
   
   printf("\n Fibonacci sequence up to %d terms : \n", num);
   for(int i = 0; i < num; i++)
      printf("%d ", fibonacci(i));

   return 0;
}
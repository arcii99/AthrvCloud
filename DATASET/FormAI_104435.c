//FormAI DATASET v1.0 Category: Recursive ; Style: scientific
#include <stdio.h>

// function declaration
int fibonacci(int n);

int main() {
   int n, result;
   
   // user input
   printf("Enter the number of terms: ");
   scanf("%d", &n);

   // call function and store result
   result = fibonacci(n);

   // print result
   printf("The %dth term of the Fibonacci sequence is %d\n", n, result);
   
   return 0;
}

// recursive function to calculate Fibonacci sequence
int fibonacci(int n) {
   if(n <= 1) {
      return n;
   } else {
      return (fibonacci(n-1) + fibonacci(n-2));
   }
}
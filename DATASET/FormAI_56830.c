//FormAI DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>
int fibonacci(int n) {
   if(n <= 1) 
      return n;
   return fibonacci(n-1) + fibonacci(n-2);
}
int main() {
   int n = 0, result = 0;

   printf("Enter the number of terms you want in Fibonacci Series:\n");
   scanf("%d", &n);

   printf("The Fibonacci Series is:\n");
   for(int i = 0; i < n; i++) {
      result = fibonacci(i);
      printf("%d ", result);
   }
   return 0;
}
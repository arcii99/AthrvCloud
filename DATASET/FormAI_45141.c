//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: dynamic
#include <stdio.h>

int main() {
   int n;

   printf("Enter the number of terms in Fibonacci series: ");
   scanf("%d",&n);

   int fib[n];

   fib[0] = 0;
   fib[1] = 1;

   for(int i=2; i<n; i++) {
      fib[i] = fib[i-1] + fib[i-2];
   }

   int max = fib[n-1];
   int digitCount = 0;
  
   while (max != 0) { //count number of digits in largest number
        max /= 10;
        digitCount++;
   }

   int spaceCount = 0;
   int i, j, k;

   for (i = 0; i < n; i++) {
      if(fib[i] >= 0 && fib[i] <= 9) 
         spaceCount = digitCount;
      else {
         max = fib[i];
         while (max != 0) {
            max /= 10;
            spaceCount++;
         }
      }

      for(k=0; k<digitCount-spaceCount; k++)
         printf(" ");

      printf("%d\n", fib[i]);
   }

   return 0;
}